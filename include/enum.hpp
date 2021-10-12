#pragma once

#include <type_traits>

namespace ckbpp {

template <class T>
class contiguous_enum_iterator_t {
	using position_type = std::underlying_type_t<T>;
public:
	explicit contiguous_enum_iterator_t(const T& pos) :
		pos(static_cast<position_type>(pos))
	{}

	static contiguous_enum_iterator_t begin() {
		return contiguous_enum_iterator_t(0);
	}

	static contiguous_enum_iterator_t end() {
		return contiguous_enum_iterator_t(static_cast<size_t>(T::__SIZE__));
	}

	constexpr bool operator==(const contiguous_enum_iterator_t& rhs) const {
		return pos == rhs.pos;
	}

	constexpr bool operator!=(const contiguous_enum_iterator_t& rhs) const {
		return pos != rhs.pos;
	}

	constexpr bool operator>=(const contiguous_enum_iterator_t& rhs) const {
		return pos >= rhs.pos;
	}

	constexpr bool operator<=(const contiguous_enum_iterator_t& rhs) const {
		return pos <= rhs.pos;
	}

	constexpr bool operator<(const contiguous_enum_iterator_t& rhs) const {
		return pos < rhs.pos;
	}

	constexpr bool operator>(const contiguous_enum_iterator_t& rhs) const {
		return pos > rhs.pos;
	}

	contiguous_enum_iterator_t& operator++() {
		++pos;
		return *this;
	}

	contiguous_enum_iterator_t operator++(int) {
		contiguous_enum_iterator_t result(*this);
		++pos;
		return result;
	}

	contiguous_enum_iterator_t& operator+(const size_t& offset) {
		pos += offset;
		return *this;
	}

	contiguous_enum_iterator_t& operator-(const size_t& offset) {
		pos -= offset;
		return *this;
	}

	[[nodiscard]]
	T operator*() const {
		return static_cast<T>(pos);
	}

	T operator[](size_t offset) const {
		return static_cast<T>(pos+offset);
	}

private:

	explicit contiguous_enum_iterator_t(const position_type& pos) :
		pos(pos)
	{}

	position_type pos;
};

template <class T>
contiguous_enum_iterator_t<T> operator+(const contiguous_enum_iterator_t<T>& lhs, const size_t& rhs) {
	contiguous_enum_iterator_t result(lhs);
	return lhs += rhs;
}

template <class T>
contiguous_enum_iterator_t<T> operator-(const contiguous_enum_iterator_t<T>& lhs, const size_t& rhs) {
	contiguous_enum_iterator_t result(lhs);
	return lhs -= rhs;
}

}
