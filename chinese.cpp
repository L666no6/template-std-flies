#include "chinese.h"
class chinese {
private:
	char c[3];
public:
	int number() {
		int a = c[0], b = c[1];
		a = -a; b = -b;
		return a * 100 + b;
	}
	friend istream& operator>> (istream& in, chinese& ch) {
		in >> ch.c[0] >> ch.c[1];
		ch.c[2] = '\0';
		return in;
	}
	friend ostream& operator<< (ostream& out, chinese& ch) {
		out << ch.c;
		return out;
	}
	chinese operator=(int n) {
		int a, b;
		b = n % 100;
		n = (n - b) / 100;
		a = n % 100;
		a = -a; b = -b;
		this->c[0] = (char)a;
		this->c[1] = (char)b;
		this->c[2] = '\0';
		return *this;
	}
	chinese operator=(chinese ch) {
		this->c[0] = ch.c[0];
		this->c[1] = ch.c[1];
		this->c[2] = '\0';
		return *this;
	}
	chinese operator=(char a[]) {
		this->c[0] = a[0];
		this->c[1] = a[1];
		this->c[2] = '\0';
		return *this;
	}
	chinese() {
		c[2] = '\0';
	}
};
