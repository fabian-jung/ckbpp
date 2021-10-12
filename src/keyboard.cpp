#include "keyboard.hpp"
#include <unordered_map>
#include <sstream>

namespace ckbpp {

std::ostream& operator<<(std::ostream& lhs,  const key_t& rhs) {
	switch(rhs) {
		case key_t::nokey       : return lhs << "nokey"     ;
		case key_t::profswitch  : return lhs << "profswitch";
		case key_t::light       : return lhs << "light"     ;
		case key_t::lock        : return lhs << "lock"      ;
		case key_t::mute        : return lhs << "mute"      ;
		case key_t::g1          : return lhs << "g1"        ;
		case key_t::esc         : return lhs << "esc"       ;
		case key_t::f1          : return lhs << "f1"        ;
		case key_t::f2          : return lhs << "f2"        ;
		case key_t::f3          : return lhs << "f3"        ;
		case key_t::f4          : return lhs << "f4"        ;
		case key_t::f5          : return lhs << "f5"        ;
		case key_t::f6          : return lhs << "f6"        ;
		case key_t::f7          : return lhs << "f7"        ;
		case key_t::f8          : return lhs << "f8"        ;
		case key_t::f9          : return lhs << "f9"        ;
		case key_t::f10         : return lhs << "f10"       ;
		case key_t::f11         : return lhs << "f11"       ;
		case key_t::f12         : return lhs << "f12"       ;
		case key_t::prtscn      : return lhs << "prtscn"    ;
		case key_t::scroll      : return lhs << "scroll"    ;
		case key_t::pause       : return lhs << "pause"     ;
		case key_t::stop        : return lhs << "stop"      ;
		case key_t::prev        : return lhs << "prev"      ;
		case key_t::play        : return lhs << "play"      ;
		case key_t::next        : return lhs << "next"      ;
		case key_t::g2          : return lhs << "g2"        ;
		case key_t::grave       : return lhs << "grave"     ;
		case key_t::k1          : return lhs << "1"         ;
		case key_t::k2          : return lhs << "2"         ;
		case key_t::k3          : return lhs << "3"         ;
		case key_t::k4          : return lhs << "4"         ;
		case key_t::k5          : return lhs << "5"         ;
		case key_t::k6          : return lhs << "6"         ;
		case key_t::k7          : return lhs << "7"         ;
		case key_t::k8          : return lhs << "8"         ;
		case key_t::k9          : return lhs << "9"         ;
		case key_t::k0          : return lhs << "0"         ;
		case key_t::minus       : return lhs << "minus"     ;
		case key_t::equal       : return lhs << "equal"     ;
		case key_t::bspace      : return lhs << "bspace"    ;
		case key_t::ins         : return lhs << "ins"       ;
		case key_t::home        : return lhs << "home"      ;
		case key_t::pgup        : return lhs << "pgup"      ;
		case key_t::numlock     : return lhs << "numlock"    ;
		case key_t::numslash    : return lhs << "numslash"  ;
		case key_t::numstar     : return lhs << "numstar"   ;
		case key_t::numminus    : return lhs << "numminus"  ;
		case key_t::g3          : return lhs << "g3"        ;
		case key_t::tab         : return lhs << "tab"       ;
		case key_t::q           : return lhs << "q"         ;
		case key_t::w           : return lhs << "w"         ;
		case key_t::e           : return lhs << "e"         ;
		case key_t::r           : return lhs << "r"         ;
		case key_t::t           : return lhs << "t"         ;
		case key_t::y           : return lhs << "y"         ;
		case key_t::u           : return lhs << "u"         ;
		case key_t::i           : return lhs << "i"         ;
		case key_t::o           : return lhs << "o"         ;
		case key_t::p           : return lhs << "p"         ;
		case key_t::lbrace      : return lhs << "lbrace"    ;
		case key_t::rbrace      : return lhs << "rbrace"    ;
		case key_t::enter       : return lhs << "enter"     ;
		case key_t::del         : return lhs << "del"       ;
		case key_t::end         : return lhs << "end"       ;
		case key_t::pgdn        : return lhs << "pgdn"      ;
		case key_t::num7        : return lhs << "num7"      ;
		case key_t::num8        : return lhs << "num8"      ;
		case key_t::num9        : return lhs << "num9"      ;
		case key_t::numplus     : return lhs << "numplus"   ;
		case key_t::g4          : return lhs << "g4"        ;
		case key_t::caps        : return lhs << "caps"      ;
		case key_t::a           : return lhs << "a"         ;
		case key_t::s           : return lhs << "s"         ;
		case key_t::d           : return lhs << "d"         ;
		case key_t::f           : return lhs << "f"         ;
		case key_t::g           : return lhs << "g"         ;
		case key_t::h           : return lhs << "h"         ;
		case key_t::j           : return lhs << "j"         ;
		case key_t::k           : return lhs << "k"         ;
		case key_t::l           : return lhs << "l"         ;
		case key_t::colon       : return lhs << "colon"     ;
		case key_t::quote       : return lhs << "quote"     ;
		case key_t::hash        : return lhs << "hash"      ;
		case key_t::num4        : return lhs << "num4"      ;
		case key_t::num5        : return lhs << "num5"      ;
		case key_t::num6        : return lhs << "num6"      ;
		case key_t::g5          : return lhs << "g5"        ;
		case key_t::lshift      : return lhs << "lshift"    ;
		case key_t::bslash_iso  : return lhs << "bslash_iso";
		case key_t::z           : return lhs << "z"         ;
		case key_t::x           : return lhs << "x"         ;
		case key_t::c           : return lhs << "c"         ;
		case key_t::v           : return lhs << "v"         ;
		case key_t::b           : return lhs << "b"         ;
		case key_t::n           : return lhs << "n"         ;
		case key_t::m           : return lhs << "m"         ;
		case key_t::comma       : return lhs << "comma"     ;
		case key_t::dot         : return lhs << "dot"       ;
		case key_t::slash       : return lhs << "slash"     ;
		case key_t::rshift      : return lhs << "rshift"    ;
		case key_t::up          : return lhs << "up"        ;
		case key_t::num1        : return lhs << "num1"      ;
		case key_t::num2        : return lhs << "num2"      ;
		case key_t::num3        : return lhs << "num3"      ;
		case key_t::numenter    : return lhs << "numenter"  ;
		case key_t::g6          : return lhs << "g6"        ;
		case key_t::lctrl       : return lhs << "lctrl"     ;
		case key_t::lwin        : return lhs << "lwin"      ;
		case key_t::lalt        : return lhs << "lalt"      ;
		case key_t::space       : return lhs << "space"     ;
		case key_t::ralt        : return lhs << "ralt"      ;
		case key_t::rwin        : return lhs << "rwin"      ;
		case key_t::rmenu       : return lhs << "rmenu"     ;
		case key_t::rctrl       : return lhs << "rctrl"     ;
		case key_t::left        : return lhs << "left"      ;
		case key_t::down        : return lhs << "down"      ;
		case key_t::right       : return lhs << "right"     ;
		case key_t::num0        : return lhs << "num0"      ;
		case key_t::numdot      : return lhs << "numdot"    ;
		case key_t::topbar1     : return lhs << "topbar1"   ;
		case key_t::topbar2     : return lhs << "topbar2"   ;
		case key_t::topbar3     : return lhs << "topbar3"   ;
		case key_t::topbar4     : return lhs << "topbar4"   ;
		case key_t::topbar5     : return lhs << "topbar5"   ;
		case key_t::topbar6     : return lhs << "topbar6"   ;
		case key_t::topbar7     : return lhs << "topbar7"   ;
		case key_t::topbar8     : return lhs << "topbar8"   ;
		case key_t::topbar9     : return lhs << "topbar9"   ;
		case key_t::topbar10    : return lhs << "topbar10"  ;
		case key_t::topbar11    : return lhs << "topbar11"  ;
		case key_t::topbar12    : return lhs << "topbar12"  ;
		case key_t::topbar13    : return lhs << "topbar13"  ;
		case key_t::topbar14    : return lhs << "topbar14"  ;
		case key_t::topbar15    : return lhs << "topbar15"  ;
		case key_t::topbar16    : return lhs << "topbar16"  ;
		case key_t::topbar17    : return lhs << "topbar17"  ;
		case key_t::topbar18    : return lhs << "topbar18"  ;
		case key_t::topbar19    : return lhs << "topbar19"  ;
	}
	return lhs;
}

keyboard_t::keyboard_t(const color_t& color)
{
	std::fill(begin(), end(), color);
}

std::ostream& operator<<(std::ostream& lhs, const keyboard_t& keyboard) {
	for(auto key_it = keyboard.key_begin(); key_it != keyboard.key_end(); ++key_it) {
		lhs << *key_it << ":" << keyboard[*key_it] << " ";
	}
	return lhs;
}

key_t string_to_key(const std::string& str) {
	static auto key_map = [](){
		std::unordered_map<std::string, key_t> map;
		for(
			auto it  = contiguous_enum_iterator_t<key_t>::begin();
			     it != contiguous_enum_iterator_t<key_t>::end();
			   ++it
		) {
			const auto key = *it;
			std::stringstream stream;
			stream << key;
			map.emplace(stream.str(), key);
		}
		return map;
	}();

	try {
		return key_map.at(str);
	} catch(std::exception& e) {

	}
	return key_t::nokey;
}

const std::unordered_map<key_t, std::vector<key_t>> neighbour_key_t::neighbours {
	{ key_t::nokey,		{}},
	{ key_t::profswitch,    {key_t::light}},
	{ key_t::light,         {key_t::profswitch, key_t::lock}},
	{ key_t::lock,          {key_t::light}},
	{ key_t::mute,          {}},
	{ key_t::g1,            {key_t::esc, key_t::g2}},
	{ key_t::esc,           {key_t::g1, key_t::grave}},
	{ key_t::f1,            {key_t::f2, key_t::k1, key_t::k2}},
	{ key_t::f2,            {key_t::f1, key_t::k2, key_t::k3, key_t::f3}},
	{ key_t::f3,            {key_t::f2, key_t::k3, key_t::k4, key_t::f4}},
	{ key_t::f4,            {key_t::f3, key_t::k4, key_t::k5}},
	{ key_t::f5,            {key_t::k6, key_t::k7, key_t::f6}},
	{ key_t::f6,            {key_t::f5, key_t::k7, key_t::k8, key_t::f7}},
	{ key_t::f7,            {key_t::f6, key_t::k8, key_t::k9, key_t::f8}},
	{ key_t::f8,            {key_t::f7, key_t::k9, key_t::k0}},
	{ key_t::f9,            {key_t::minus, key_t::f10}},
	{ key_t::f10,           {key_t::f9, key_t::equal, key_t::f11}},
	{ key_t::f11,           {key_t::f10, key_t::bspace, key_t::f12}},
	{ key_t::f12,           {key_t::f11, key_t::bspace, key_t::prtscn}},
	{ key_t::prtscn,        {key_t::f12, key_t::ins, key_t::scroll}},
	{ key_t::scroll,        {key_t::prtscn, key_t::home, key_t::pause}},
	{ key_t::pause,         {key_t::scroll, key_t::pgup, key_t::stop}},
	{ key_t::stop,          {key_t::pause, key_t::numlock, key_t::prev}},
	{ key_t::prev,          {key_t::stop, key_t::numslash, key_t::play}},
	{ key_t::play,          {key_t::prev, key_t::numstar, key_t::next}},
	{ key_t::next,          {key_t::play, key_t::numminus}},
	{ key_t::g2,            {key_t::g3, key_t::grave, key_t::g1}},
	{ key_t::grave,         {key_t::g2, key_t::tab, key_t::k1, key_t::esc}},
	{ key_t::k1,            {key_t::grave, key_t::tab, key_t::q, key_t::k2, key_t::f1}},
	{ key_t::k2,            {key_t::k1, key_t::q, key_t::w, key_t::k3, key_t::f2, key_t::f1}},
	{ key_t::k3,            {key_t::k2, key_t::w, key_t::e, key_t::k4, key_t::f3, key_t::f2}},
	{ key_t::k4,            {key_t::k3, key_t::e, key_t::r, key_t::k5, key_t::f4, key_t::f3}},
	{ key_t::k5,            {key_t::k4, key_t::r, key_t::t, key_t::k6, key_t::f4}},
	{ key_t::k6,            {key_t::k5, key_t::t, key_t::y, key_t::k7, key_t::f5}},
	{ key_t::k7,            {key_t::k6, key_t::y, key_t::u, key_t::k8, key_t::f6, key_t::f5}},
	{ key_t::k8,            {key_t::k7, key_t::u, key_t::i, key_t::k9, key_t::f7, key_t::f6}},
	{ key_t::k9,            {key_t::k8, key_t::i, key_t::o, key_t::k0, key_t::f8, key_t::f7}},
	{ key_t::k0,            {key_t::k9, key_t::o, key_t::p, key_t::minus, key_t::f8}},
	{ key_t::minus,         {key_t::k0, key_t::p, key_t::lbrace, key_t::equal, key_t::f9}},
	{ key_t::equal,         {key_t::minus, key_t::lbrace, key_t::rbrace, key_t::bspace, key_t::f10}},
	{ key_t::bspace,        {key_t::equal, key_t::rbrace, key_t::enter, key_t::ins, key_t::f12, key_t::f11}},
	{ key_t::ins,           {key_t::bspace, key_t::del, key_t::home, key_t::prtscn}},
	{ key_t::home,          {key_t::ins, key_t::end, key_t::pgup, key_t::scroll}},
	{ key_t::pgup,          {key_t::home, key_t::pgdn, key_t::numlock, key_t::pause}},
	{ key_t::numlock,       {key_t::pgup, key_t::num7, key_t::numslash, key_t::stop}},
	{ key_t::numslash,      {key_t::numlock, key_t::num8, key_t::numstar, key_t::prev}},
	{ key_t::numstar,       {key_t::numslash, key_t::num9, key_t::numminus, key_t::play}},
	{ key_t::numminus,      {key_t::numstar, key_t::numplus, key_t::next}},
	{ key_t::g3,            {key_t::g4, key_t::tab, key_t::g2}},
	{ key_t::tab,           {key_t::g3, key_t::caps, key_t::q, key_t::k1, key_t::grave}},
	{ key_t::q,             {key_t::tab, key_t::caps, key_t::a, key_t::w, key_t::k2, key_t::k1}},
	{ key_t::w,             {key_t::q, key_t::a, key_t::s, key_t::e, key_t::k3, key_t::k2}},
	{ key_t::e,             {key_t::w, key_t::s, key_t::d, key_t::r, key_t::k4, key_t::k3}},
	{ key_t::r,             {key_t::e, key_t::d, key_t::f, key_t::t, key_t::k5, key_t::k4}},
	{ key_t::t,             {key_t::r, key_t::f, key_t::g, key_t::y, key_t::k6, key_t::k5}},
	{ key_t::y,             {key_t::t, key_t::g, key_t::h, key_t::u, key_t::k7, key_t::k6}},
	{ key_t::u,             {key_t::y, key_t::h, key_t::j, key_t::i, key_t::k8, key_t::k7}},
	{ key_t::i,             {key_t::u, key_t::j, key_t::k, key_t::o, key_t::k9, key_t::k8}},
	{ key_t::o,             {key_t::i, key_t::k, key_t::l, key_t::p, key_t::k0, key_t::k9}},
	{ key_t::p,             {key_t::o, key_t::l, key_t::colon, key_t::lbrace, key_t::minus, key_t::k0}},
	{ key_t::lbrace,        {key_t::p, key_t::colon, key_t::quote, key_t::rbrace, key_t::equal, key_t::minus}},
	{ key_t::rbrace,        {key_t::lbrace, key_t::quote, key_t::hash, key_t::enter, key_t::bspace, key_t::equal}},
	{ key_t::enter,         {key_t::rbrace, key_t::hash, key_t::rshift, key_t::del, key_t::bspace}},
	{ key_t::del,           {key_t::enter, key_t::end, key_t::ins}},
	{ key_t::end,           {key_t::del, key_t::pgdn, key_t::home}},
	{ key_t::pgdn,          {key_t::end, key_t::num7, key_t::pgup}},
	{ key_t::num7,          {key_t::pgdn, key_t::num4, key_t::num8, key_t::numlock}},
	{ key_t::num8,          {key_t::num7, key_t::num5, key_t::num9, key_t::numslash}},
	{ key_t::num9,          {key_t::num8, key_t::num6, key_t::numplus, key_t::numstar}},
	{ key_t::numplus,       {key_t::num9, key_t::num6, key_t::numenter, key_t::numminus}},
	{ key_t::g4,            {key_t::g5, key_t::caps, key_t::g3}},
	{ key_t::caps,          {key_t::g4, key_t::lshift, key_t::bslash_iso, key_t::a, key_t::q, key_t::tab}},
	{ key_t::a,             {key_t::caps, key_t::bslash_iso, key_t::z, key_t::s, key_t::w, key_t::q}},
	{ key_t::s,             {key_t::a, key_t::z, key_t::x, key_t::d, key_t::e, key_t::w}},
	{ key_t::d,             {key_t::s, key_t::x, key_t::c, key_t::f, key_t::r, key_t::e}},
	{ key_t::f,             {key_t::d, key_t::c, key_t::v, key_t::g, key_t::t, key_t::r}},
	{ key_t::g,             {key_t::f, key_t::v, key_t::b, key_t::h, key_t::y, key_t::t}},
	{ key_t::h,             {key_t::g, key_t::b, key_t::n, key_t::j, key_t::u, key_t::y}},
	{ key_t::j,             {key_t::h, key_t::n, key_t::m, key_t::k, key_t::i, key_t::u}},
	{ key_t::k,             {key_t::j, key_t::m, key_t::comma, key_t::l, key_t::o, key_t::i}},
	{ key_t::l,             {key_t::k, key_t::comma, key_t::dot, key_t::colon, key_t::p, key_t::o}},
	{ key_t::colon,         {key_t::l, key_t::dot, key_t::slash, key_t::quote, key_t::lbrace, key_t::p}},
	{ key_t::quote,         {key_t::colon, key_t::slash, key_t::rshift, key_t::hash, key_t::rbrace, key_t::lbrace}},
	{ key_t::hash,          {key_t::quote, key_t::rshift, key_t::enter, key_t::rbrace}},
	{ key_t::num4,          {key_t::num1, key_t::num5, key_t::num7}},
	{ key_t::num5,          {key_t::num4, key_t::num2, key_t::num6, key_t::num8}},
	{ key_t::num6,          {key_t::num5, key_t::num3, key_t::numplus, key_t::num9}},
	{ key_t::g5,            {key_t::g6, key_t::lshift, key_t::g4}},
	{ key_t::lshift,        {key_t::g5, key_t::lctrl, key_t::bslash_iso, key_t::caps}},
	{ key_t::bslash_iso,    {key_t::lshift, key_t::lctrl, key_t::lwin, key_t::z, key_t::a, key_t::caps}},
	{ key_t::z,             {key_t::bslash_iso, key_t::lwin, key_t::lalt, key_t::x, key_t::s, key_t::a}},
	{ key_t::x,             {key_t::z, key_t::lalt, key_t::space, key_t::c, key_t::d, key_t::s}},
	{ key_t::c,             {key_t::x, key_t::space, key_t::v, key_t::f, key_t::d}},
	{ key_t::v,             {key_t::c, key_t::space, key_t::b, key_t::g, key_t::f}},
	{ key_t::b,             {key_t::v, key_t::space, key_t::n, key_t::h, key_t::g}},
	{ key_t::n,             {key_t::b, key_t::space, key_t::m, key_t::j, key_t::h}},
	{ key_t::m,             {key_t::n, key_t::space, key_t::comma, key_t::k, key_t::j}},
	{ key_t::comma,         {key_t::m, key_t::space, key_t::dot, key_t::l, key_t::k}},
	{ key_t::dot,           {key_t::comma, key_t::ralt, key_t::slash, key_t::colon, key_t::l}},
	{ key_t::slash,         {key_t::dot, key_t::ralt, key_t::rwin, key_t::rshift, key_t::quote, key_t::colon}},
	{ key_t::rshift,        {key_t::slash, key_t::rwin, key_t::rmenu, key_t::rctrl, key_t::enter, key_t::hash, key_t::quote}},
	{ key_t::up,            {key_t::down}},
	{ key_t::num1,          {key_t::num0, key_t::num2, key_t::num4}},
	{ key_t::num2,          {key_t::num1, key_t::num0, key_t::num3, key_t::num5}},
	{ key_t::num3,          {key_t::num2, key_t::numdot, key_t::numenter, key_t::num6}},
	{ key_t::numenter,      {key_t::num3, key_t::numdot, key_t::numplus}},
	{ key_t::g6,            {key_t::lctrl, key_t::g5}},
	{ key_t::lctrl,         {key_t::g6, key_t::lwin, key_t::bslash_iso, key_t::lshift}},
	{ key_t::lwin,          {key_t::lctrl, key_t::lalt, key_t::z, key_t::bslash_iso}},
	{ key_t::lalt,          {key_t::lwin, key_t::space, key_t::x, key_t::z}},
	{ key_t::space,         {key_t::lalt, key_t::ralt,                                            key_t::comma, key_t::m, key_t::n, key_t::b, key_t::v, key_t::c, key_t::x}},
	{ key_t::ralt,          {key_t::space, key_t::rwin, key_t::slash, key_t::dot}},
	{ key_t::rwin,          {key_t::ralt, key_t::rmenu, key_t::rshift, key_t::slash}},
	{ key_t::rmenu,         {key_t::rwin, key_t::rctrl, key_t::rshift}},
	{ key_t::rctrl,         {key_t::rmenu, key_t::left, key_t::rshift}},
	{ key_t::left,          {key_t::rctrl, key_t::down}},
	{ key_t::down,          {key_t::left, key_t::right, key_t::up}},
	{ key_t::right,         {key_t::down, key_t::num0}},
	{ key_t::num0,          {key_t::right, key_t::numdot, key_t::num2, key_t::num1}},
	{ key_t::numdot,        {key_t::num0, key_t::numenter, key_t::num3}},
	{ key_t::topbar1,       {}},
	{ key_t::topbar2,       {}},
	{ key_t::topbar3,       {}},
	{ key_t::topbar4,       {}},
	{ key_t::topbar5,       {}},
	{ key_t::topbar6,       {}},
	{ key_t::topbar7,       {}},
	{ key_t::topbar8,       {}},
	{ key_t::topbar9,       {}},
	{ key_t::topbar10,      {}},
	{ key_t::topbar11,      {}},
	{ key_t::topbar12,      {}},
	{ key_t::topbar13,      {}},
	{ key_t::topbar14,      {}},
	{ key_t::topbar15,      {}},
	{ key_t::topbar16,      {}},
	{ key_t::topbar17,      {}},
	{ key_t::topbar18,      {}},
	{ key_t::topbar19,      {}}
};



}
