#pragma once

#include <type_traits>
#include <ostream>
#include <array>
#include <algorithm>

class color_t {
	using value_type = std::uint8_t;
	constexpr static value_type full_color = 255;

public:
	union {
		struct {
			value_type r;
			value_type g;
			value_type b;
		};
		std::array<std::uint8_t, 3> array;
	};

	color_t() :
		r(0),
		g(0),
		b(0)
	{}

	template <
		class T,
		std::enable_if_t<std::is_floating_point_v<T>, int> = 0
	>
	constexpr color_t(T r, T g, T b) :
		r(full_color*r),
		g(full_color*g),
		b(full_color*b)
	{
	}

	template <
		class T,
		std::enable_if_t<std::is_integral_v<T>, int> = 0
	>
	color_t(T r, T g, T b) :
		r(r),
		g(g),
		b(b)
	{
	}

	color_t(color_t&& mov);
	color_t& operator=(color_t&& mov);
	color_t(const color_t& mov);
	color_t& operator=(const color_t& mov);

	color_t& operator+=(const color_t& rhs);
	color_t& operator-=(const color_t& rhs);
	template <class T>
	color_t& operator*=(const T& rhs) {
		std::for_each(array.begin(), array.end(), [rhs](value_type& lhs){ lhs=static_cast<double>(lhs)*static_cast<double>(rhs); });
		return *this;
	}

	template <class T>
	color_t& operator/=(const T& rhs) {
		std::for_each(array.begin(), array.end(), [rhs](value_type& lhs){ lhs=static_cast<double>(lhs)/static_cast<double>(rhs); });
		return *this;
	}

};

color_t operator+(const color_t& lhs, const color_t& rhs);
color_t operator-(const color_t& lhs, const color_t& rhs);

template <class T>
color_t operator*(const color_t& lhs, const T& rhs) {
	color_t result = lhs;
	return result *= rhs;
}

template <class T>
color_t operator*(const T& rhs, const color_t& lhs) {
	return lhs*rhs;
}


template <class T>
color_t operator/(const color_t& lhs, const T& rhs) {
	color_t result = lhs;
	return result /= rhs;
}

std::ostream& operator<<(std::ostream& lhs, const color_t& rhs);
