#pragma once
#include "chinese.h"
using namespace std;

class sign {
private:
	int a;
public:
	sign();
	sign(const sign& obj);
	friend ostream& operator << (ostream& out, const sign& s);
	friend istream& operator >> (istream& in, sign& s);
	int number();
	sign operator = (int b);
	sign operator = (sign s);
	sign operator = (char c);
	sign operator = (chinese ch);
	sign operator + (int b);
	sign operator + (sign s);
	sign operator - (int b);
	sign operator - (sign s);
	bool operator == (sign s);
	bool operator == (char c);
	bool operator == (chinese ch);
	bool operator != (sign s);
	bool operator != (char c);
	bool operator != (chinese ch);
};
