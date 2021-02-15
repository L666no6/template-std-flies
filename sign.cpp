#include "sign.h"
using namespace std;

class sign {
private:
	int a;
public:
	sign() {
		a = 0;
	}
	sign(const sign& obj) {
		a = obj.a;
	}
	friend ostream& operator << (ostream& out, const sign& s) {
		if (s.a < 100) {
			out << (char)s.a;
			return out;
		}
		if (1000 <= s.a and s.a <= 9999) {
			chinese ch;
			ch = s.a;
			out << ch;
			return out;
		}
		return out;
	}
	friend istream& operator >> (istream& in, sign& s) {
		char c[3] = { ' ',' ','\0' };
		in >> c;
		c[2] = '\0';
		if ((int)c[0] < 0) {
			chinese ch;
			ch = c;
			s.a = ch.number();
		}
		if ((int)c[0] > 0) {
			s.a = (int)c[0];
		}
		return in;
	}
	int number() {
		return this->a;
	}
	sign operator = (int b) {
		this->a = b;
		return *this;
	}
	sign operator = (sign s) {
		this->a = s.a;
		return *this;
	}
	sign operator = (char c) {
		this->a = (int)c;
		return *this;
	}
	sign operator = (chinese ch) {
		this->a = ch.number();
		return *this;
	}
	sign operator + (int b) {
		this->a = this->a + b;
		return *this;
	}
	sign operator + (sign s) {
		this->a = this->a + s.a;
		return *this;
	}
	sign operator - (int b) {
		this->a = this->a - b;
		return *this;
	}
	sign operator - (sign s) {
		this->a = this->a - s.a;
		return *this;
	}
	bool operator == (sign s) {
		return (this->a == s.a);
	}
	bool operator == (char c) {
		return (this->a == (int)c);
	}
	bool operator == (chinese ch) {
		return (this->a == ch.number());
	}
	bool operator != (sign s) {
		return !(*this == s);
	}
	bool operator != (char c) {
		return !(*this == c);
	}
	bool operator != (chinese ch) {
		return !(*this == ch);
	}
};
