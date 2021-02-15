#pragma once
using namespace std;

class chinese {
private:
	char c[3];
public:
	int number();
	friend istream& operator>> (istream& in, chinese& ch);
	friend ostream& operator<< (ostream& out, chinese& ch);
	chinese operator=(int n);
	chinese operator=(chinese ch);
	chinese operator=(char a[]);
	chinese();
};

