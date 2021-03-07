#pragma once
#include "unsign.h"
class longlong
{
private:
	unsign b;
	bool sign;
public:
	longlong() {
		b = 0;
		sign = 0;
	}
	longlong(const longlong& obj) {
		this->sign = obj.sign;
		this->b = obj.b;
	}
	longlong(unsign a) {
		this->b = a;
		sign = 0;
	}
	longlong(int a) {
		*this = a;
	}
	longlong operator=(longlong l);
	longlong operator=(unsign b);
	longlong operator=(int a);

	longlong operator+(longlong l);
	longlong operator-(longlong l);
	longlong operator*(longlong l);
	longlong operator/(longlong l);
	longlong operator%(longlong l);

	longlong operator++();
	longlong operator--();
	longlong operator+=(longlong l);
	longlong operator-=(longlong l);
	longlong operator*=(longlong l);
	
	bool operator<(longlong l);
	bool operator>(longlong l);
	bool operator==(longlong l);
	bool operator!=(longlong l);
	bool operator>=(longlong l);
	bool operator<=(longlong l);

	void x16(std::string s);

	friend std::istream& operator >>(std::istream& in, longlong& l);
	friend std::ostream& operator<<(std::ostream& out, longlong& l);
};

