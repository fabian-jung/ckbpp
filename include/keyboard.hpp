#pragma once

#include <array>
#include "color.hpp"
#include "enum.hpp"

namespace ckbpp {

enum class key_t : size_t {
	nokey,
	profswitch,
	light,
	lock,
	mute,
	g1,
	esc,
	f1,
	f2,
	f3,
	f4,
	f5,
	f6,
	f7,
	f8,
	f9,
	f10,
	f11,
	f12,
	prtscn,
	scroll,
	pause,
	stop,
	prev,
	play,
	next,
	g2,
	grave,
	k1,
	k2,
	k3,
	k4,
	k5,
	k6,
	k7,
	k8,
	k9,
	k0,
	minus,
	equal,
	bspace,
	ins,
	home,
	pgup,
	numlock,
	numslash,
	numstar,
	numminus,
	g3,
	tab,
	q,
	w,
	e,
	r,
	t,
	y,
	u,
	i,
	o,
	p,
	lbrace,
	rbrace,
	enter,
	del,
	end,
	pgdn,
	num7,
	num8,
	num9,
	numplus,
	g4,
	caps,
	a,
	s,
	d,
	f,
	g,
	h,
	j,
	k,
	l,
	colon,
	quote,
	hash,
	num4,
	num5,
	num6,
	g5,
	lshift,
	bslash_iso,
	z,
	x,
	c,
	v,
	b,
	n,
	m,
	comma,
	dot,
	slash,
	rshift,
	up,
	num1,
	num2,
	num3,
	numenter,
	g6,
	lctrl,
	lwin,
	lalt,
	space,
	ralt,
	rwin,
	rmenu,
	rctrl,
	left,
	down,
	right,
	num0,
	numdot,
	topbar1,
	topbar2,
	topbar3,
	topbar4,
	topbar5,
	topbar6,
	topbar7,
	topbar8,
	topbar9,
	topbar10,
	topbar11,
	topbar12,
	topbar13,
	topbar14,
	topbar15,
	topbar16,
	topbar17,
	topbar18,
	topbar19,
	__SIZE__
};

std::ostream& operator<<(std::ostream& lhs,  const key_t& rhs);

class keyboard_t {
public:
	keyboard_t(const color_t& color = color_t(0, 0, 0));

	keyboard_t(keyboard_t&& mov) = default;
	keyboard_t& operator=(keyboard_t&& mov) = default;

	keyboard_t(const keyboard_t& cpy) = default;
	keyboard_t& operator=(const keyboard_t& cpy) = default;

	auto key_begin() const {
		return contiguous_enum_iterator_t<key_t>::begin();
	}
	auto key_end() const {
		return contiguous_enum_iterator_t<key_t>::end();
	}
	auto begin() {
		return m_keys.begin();
	}
	auto begin() const {
		return m_keys.begin();
	}
	auto end() {
		return m_keys.end();
	}
	auto end() const {
		return m_keys.end();
	}
	auto topbar_begin() {
		return begin()+static_cast<size_t>(key_t::topbar1);
	}
	auto topbar_end() {
		return begin()+static_cast<size_t>(key_t::topbar19)+1;
	}
	color_t& operator[](key_t key) {
		return m_keys[static_cast<size_t>(key)];
	}

	const color_t& operator[](key_t key) const {
		return m_keys[static_cast<size_t>(key)];
	}

private:
	std::array<color_t, static_cast<size_t>(key_t::__SIZE__)> m_keys;
};

std::ostream& operator<<(std::ostream& lhs, const keyboard_t& keyboard);
key_t string_to_key(const std::string& str);

class neighbour_key_t {
public:
	neighbour_key_t(const key_t& key) :
		range(neighbours.at(key))
	{}

	auto begin() const {
		return range.begin();
	}

	auto end() const {
		return range.end();
	}

	auto size() const {
		return range.size();
	}

private:
	const std::vector<key_t>& range;
	static const std::unordered_map<key_t, std::vector<key_t>> neighbours;
};


}
