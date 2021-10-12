#include "ckb.hpp"
#include <filesystem>
#include <iostream>
#include <thread>

namespace ckbpp {

constexpr auto device_path = "/dev/input/ckb1/";

namespace fs = std::filesystem;

unsigned int first_free_notify_id() {
	unsigned int i = 0;
	while(!fs::exists("/dev/input/ckb1/")) {
		std::cout << "Ckb driver not ready." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	while(fs::exists(device_path+std::string("notify")+std::to_string(i))) {
		++i;
	}
	return i;
}

ckb_t::ckb_t() :
	m_notify_id(first_free_notify_id()),
	m_cmd(std::string(device_path)+"cmd")
{
	m_cmd << "active" << std::endl;
	m_cmd << "notifyon " << m_notify_id << std::endl;
	m_cmd << "@" << m_notify_id << " notify all" << std::endl;
	std::cout << "Listening on " << m_notify_id << std::endl;
	const std::string notify_name(device_path+std::string("notify")+std::to_string(m_notify_id));
	while(!std::filesystem::exists(notify_name)) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	m_notify.open(notify_name);
	m_listener = std::thread([this](){
		std::string line;
		while(std::getline(m_notify, line)) {
			auto event = line[4]== '+' ? key_event_t::press : key_event_t::release;
			line.erase(0, 5); // erase "key +"
			auto key = string_to_key(line);
			if(m_key_event_callback) {
				m_key_event_callback(key, event);
			}
		}
	});
}

ckb_t::~ckb_t() {
	m_cmd << "notifyoff " << m_notify_id << std::endl;
	m_cmd << "active" << std::endl;
	m_listener.join();
}

void ckb_t::set_led(const key_t& key, const color_t& color) {
	m_cmd << "rgb " << key << ":" << color << std::endl;
}
void ckb_t::set_led(const keyboard_t& keyboard) {
	m_cmd << "rgb " << keyboard << std::endl;
}

void ckb_t::set_key_event_callback(std::function<void(const key_t&, const key_event_t&)> cb) {
	m_key_event_callback = std::move(cb);
}

}

