#include <iostream>
#include <future>
#include <algorithm>

#include "cpu_meter.hpp"
#include "signal.hpp"
#include "ckb.hpp"

#include <stdlib.h>

using namespace ckbpp;

int main(int argc, char **argv) {
	ckb_t ckb;
	keyboard_t keyboard;
	std::array<float, static_cast<size_t>(ckbpp::key_t::__SIZE__)> energy;
	std::fill(energy.begin(), energy.end(), 0.0f);
	ckb.set_key_event_callback(
	[&](const ckbpp::key_t& key, const key_event_t& event) mutable {
		energy[static_cast<size_t>(key)] += 1.0f;
	});

	std::promise<void> finished_promise;
	std::future<void> finished = finished_promise.get_future();
	signal_handler_t signal_handler(
		[&](int){
			finished_promise.set_value();
		}
	);

	cpu_meter_t cpu_meter;
	float cpu = 0;
	while(finished.wait_for(std::chrono::milliseconds(33)) == std::future_status::timeout) {
		std::for_each(keyboard.key_begin(), keyboard.key_end(), [&](const ckbpp::key_t& key){
			const auto energy_coupling_factor = 0.05;
			const auto diff = energy_coupling_factor*energy[static_cast<size_t>(key)];
			energy[static_cast<size_t>(key)] -= diff;
			neighbour_key_t neighbour_keys(key);
			const auto energy_loss_factor = 0.95;
			const auto delta = energy_loss_factor*diff/neighbour_keys.size();
			std::for_each(neighbour_keys.begin(), neighbour_keys.end(), [&](auto neighbour)  {
				energy[static_cast<size_t>(neighbour)] += delta;
			});
			const auto e = std::clamp(energy[static_cast<size_t>(key)], 0.0f, 1.0f);
			const color_t hot {255,0,0};
			const color_t cold {85,170,255};
			keyboard[key] = e*hot+(1-e)*cold;
		});

		cpu += 0.03*(cpu_meter.read()-cpu);
		std::fill(keyboard.topbar_begin(), keyboard.topbar_end(), (1-cpu)*color_t{0, 255, 0}+cpu*color_t{255, 0, 0});
		ckb.set_led(keyboard);
	}
	return 0;
}