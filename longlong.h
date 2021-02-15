#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1000;

class longlong {
private:
    int d[maxn], len;

    void clean();
public:
    longlong() { memset(d, 0, sizeof(d)); len = 1; }
    longlong(int num) { *this = num; }
    longlong(char* num) { *this = num; }
    longlong operator = (const char* num);
    longlong operator = (int num);
    longlong operator + (const longlong& b);
    longlong operator - (const longlong& b);
    longlong operator * (const longlong& b)const;
    longlong operator / (const longlong& b);
    longlong operator % (const longlong& b);
    longlong operator += (const longlong& b);
    bool operator <(const longlong& b) const;
    bool operator >(const longlong& b) const;
    bool operator<=(const longlong& b) const;
    bool operator>=(const longlong& b) const;
    bool operator!=(const longlong& b) const;
    bool operator==(const longlong& b) const;

    string str() const;
};

istream& operator >> (istream& in, longlong& x);

ostream& operator << (ostream& out, const longlong& x);
