#include "color.hpp"

#include <iomanip>

color_t::color_t(color_t&& mov) = default;
color_t& color_t::operator=(color_t&& mov) = default;
color_t::color_t(const color_t& mov) = default;
color_t& color_t::operator=(const color_t& mov) = default;

color_t& color_t::operator+=(const color_t& rhs) {
	std::transform(array.begin(), array.end(), rhs.array.begin(), array.begin(), std::plus<value_type>());
	return *this;
}

color_t& color_t::operator-=(const color_t& rhs) {
	std::transform(array.begin(), array.end(), rhs.array.begin(), array.begin(), std::minus<value_type>());
	return *this;
}

color_t operator+(const color_t& lhs, const color_t& rhs) {
	color_t result = lhs;
	return result += rhs;
}

color_t operator-(const color_t& lhs, const color_t& rhs) {
	color_t result = lhs;
	return result -= rhs;
}

std::ostream& operator<<(std::ostream& lhs, const color_t& rhs) {
	lhs << std::setw(2) << std::setfill('0') << std::hex
		<< std::setw(2) << static_cast<unsigned int>(rhs.r)
		<< std::setw(2) << static_cast<unsigned int>(rhs.g)
		<< std::setw(2) << static_cast<unsigned int>(rhs.b);
	return lhs;
}
