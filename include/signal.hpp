#pragma once

#include <functional>

class signal_handler_t {
public:
	signal_handler_t(std::function<void(int)> handler);

	~signal_handler_t();
private:
	size_t m_id;
};
