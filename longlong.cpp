#include "longlong.h"

longlong longlong::operator=(longlong l)
{
	this->b = l.b;
	this->sign = l.sign;
	return longlong();
}

longlong longlong::operator=(unsign b)
{
	this->b = b;
	this->sign = 0;
	return longlong();
}

longlong longlong::operator=(int a)
{
	this->sign = 0;
	if (a < 0) {
		this->sign = 1;
		a = -a;
	}
	this->b = a;
	return longlong();
}

longlong longlong::operator+(longlong l)
{
	longlong a = *this;
	if (this->sign == 0 and l.sign == 0) {
		a.b = a.b + l.b;
		a.sign = 0;
	}
	else if (this->sign == 1 and l.sign == 1) {
		a.b = a.b + l.b;
		a.sign = 1;
	}
	else {
		if (a.b == l.b) {
			a.b = 0;
			a.sign = 0;
		}
		else if (a.b > l.b) {
			a.b = a.b - l.b;
		}
		else {
			a.b = l.b - a.b;
		}
		a.sign = !a.sign;
	}
	return a;
}

longlong longlong::operator-(longlong l)
{
	longlong a = *this;
	if (a.sign == 0 and l.sign == 0) {
		if (a.b >= l.b) {
			a.b = a.b - l.b;
			a.sign = 0;
		}
		else {
			a.b = l.b - a.b;
			a.sign = 1;
		}
	}
	else if (a.sign == 1 and l.sign == 1) {
		if (a.b >= l.b) {
			a.b = a.b - l.b;
			a.sign = 1;
		}
		else {
			a.b = l.b - a.b;
			a.sign = 0;
		}
	}
	else {
		if (a.sign = 0) {
			a.b = a.b + l.b;
			a.sign = 0;
		}
		else {
			a.b = a.b + l.b;
			a.sign = 1;
		}
	}
	return a;
}

longlong longlong::operator*(longlong l)
{
	longlong r;
	r.b = this->b * l.b;
	if (this->sign == l.sign) {
		r.sign = 0;
	}
	else {
		r.sign = 1;
	}
	return r;
}

longlong longlong::operator/(longlong l)
{
	longlong r;
	r.b = this->b / l.b;
	if (this->sign == l.sign) {
		r.sign = 0;
	}
	else {
		r.sign = 1;
	}
	return r;
	return longlong();
}

longlong longlong::operator%(longlong l)
{
	longlong a = *this;
	if (a.sign == false and l.sign==false) {
		a.b = a.b % l.b;
	}
	else if (a.sign == l.sign == true) {
		a.b = a.b % l.b;
		a.sign = 1;
	}
	else {
		if (a.sign = 1) {
			a.b = a.b % l.b;
			a.b = l.b - a.b;
			a.sign = 0;
		}
	}
	return a;
}

longlong longlong::operator++()
{
	*this = *this + 1;
	return *this;
}

longlong longlong::operator--()
{
	*this = *this - 1;
	return *this;
}

longlong longlong::operator+=(longlong l)
{
	*this = *this + l;
	return longlong();
}

longlong longlong::operator-=(longlong l)
{
	*this = *this - l;
	return *this;
}

longlong longlong::operator*=(longlong l)
{
	*this = *this * l;
	return *this;
}

bool longlong::operator<(longlong l)
{
	if (this->sign < l.sign)return false;
	if (this->sign > l.sign)return true;
	unsign x, y;
	x = this->b;
	y = l.b;
	if (this->sign == l.sign == 0) return x < y;
	if (this->sign == l.sign == 1)return x > y;
	return false;
}

bool longlong::operator>(longlong l)
{
	return *this>=l and *this!=l;
}

bool longlong::operator==(longlong l)
{
	if (this->sign != l.sign) return false;
	if (this->b != l.b)return false;
	return true;
}

bool longlong::operator!=(longlong l)
{
	return !(*this==l);
}

bool longlong::operator>=(longlong l)
{
	return !(*this<l);
}

bool longlong::operator<=(longlong l)
{
	return !(*this>l);
}

void longlong::x16(std::string s)
{
	this->b.x16(s);
}

std::istream& operator>>(std::istream& in, longlong& l)
{
	std::string s;
	in >> s;
	l.sign = 0;
	if (s[0] == '-') {
		l.sign = 1;
		std::string r;
		r = s;
		s = "";
		for (int i = 1; i < r.length(); i++) {
			s += r[i];
		}
	}
	l.b = s.c_str();
	return in;
}

std::ostream& operator<<(std::ostream& out, longlong& l)
{
	if (l.sign) {
		out << '-';
	}
	out << l.b;
	return out;
}
