#include "signal.hpp"
#include <csignal>
#include <iostream>
#include <map>

inline std::map<
	size_t,
	std::function<void(int signum)>
> handler_map;

void generic_signal_handler(int signum) {
	std::cout << "Catched Signal " << signum << std::endl;
	for(auto& [id, handler] : handler_map) {
		handler(signum);
	}
}

signal_handler_t::signal_handler_t(std::function<void(int)> handler)
{
	static size_t id = 0;
	m_id = ++id;
	handler_map.insert(
		std::make_pair(
			m_id,
			handler
		)
	);
	static bool init = false;
	if(!init) {
		init = true;
		std::signal(SIGABRT, generic_signal_handler);
		std::signal(SIGFPE, generic_signal_handler);
		std::signal(SIGILL, generic_signal_handler);
		std::signal(SIGINT, generic_signal_handler);
		std::signal(SIGSEGV, generic_signal_handler);
		std::signal(SIGTERM, generic_signal_handler);
	}
}

signal_handler_t::~signal_handler_t() {
	handler_map.erase(m_id);
}

