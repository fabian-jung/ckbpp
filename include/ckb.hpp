#pragma once
#include <fstream>
#include <thread>
#include "keyboard.hpp"

namespace ckbpp {

enum class key_event_t {
	press,
	release
};

class ckb_t {
public:
	ckb_t();

	~ckb_t();

	void set_led(const key_t& key, const color_t& color);
	void set_led(const keyboard_t& keyboard);
	void set_key_event_callback(std::function<void(const key_t&, const key_event_t&)> cb);

private:


	const unsigned int m_notify_id;
	std::ofstream m_cmd;
	std::ifstream m_notify;
	std::function<void(const key_t&, const key_event_t&)> m_key_event_callback;
	std::thread m_listener;
};

}
