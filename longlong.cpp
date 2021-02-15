#include "longlong.h"

using namespace std;
//private
    void longlong::clean() { while (len > 1 && !d[len - 1]) len--; }
//public
    longlong longlong::operator = (const char* num) {
        memset(d, 0, sizeof(d)); len = strlen(num);
        for (int i = 0; i < len; i++) d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }
    longlong longlong::operator = (int num) {
        len = 0;
        while (num != 0) {
            this->d[len] = (num % 10);
            len++;
            num = num / 10;
         }
        return *this;
    }

    longlong longlong::operator + (const longlong& b) {
        longlong c = *this; int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] += b.d[i];
            if (c.d[i] > 9) c.d[i] %= 10, c.d[i + 1]++;
        }
        while (c.d[i] > 9) c.d[i++] %= 10, c.d[i]++;
        c.len = max(len, b.len);
        if (c.d[i] && c.len <= i) c.len = i + 1;
        return c;
    }
    longlong longlong::operator - (const longlong& b) {
        longlong c = *this; int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0) c.d[i] += 10, c.d[i + 1]--;
        }
        while (c.d[i] < 0) c.d[i++] += 10, c.d[i]--;
        c.clean();
        return c;
    }
    longlong longlong::operator * (const longlong& b)const {
        int i, j; longlong c; c.len = len + b.len;
        for (j = 0; j < b.len; j++) for (i = 0; i < len; i++)
            c.d[i + j] += d[i] * b.d[j];
        for (i = 0; i < c.len - 1; i++)
            c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    longlong longlong::operator / (const longlong& b) {
        int i, j;
        longlong c = *this, a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++) if (a < b * (j + 1)) break;
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    longlong longlong::operator % (const longlong& b) {
        int i, j;
        longlong a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++) if (a < b * (j + 1)) break;
            a = a - b * j;
        }
        return a;
    }
    longlong longlong::operator += (const longlong& b) {
        *this = *this + b;
        return *this;
    }

    bool longlong::operator <(const longlong& b) const {
        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }
    bool longlong::operator >(const longlong& b) const { return b < *this; }
    bool longlong::operator<=(const longlong& b) const { return !(b < *this); }
    bool longlong::operator>=(const longlong& b) const { return !(*this < b); }
    bool longlong::operator!=(const longlong& b) const { return b < *this || *this < b; }
    bool longlong::operator==(const longlong& b) const { return !(b < *this) && !(b > *this); }

    string longlong::str() const {
        char s[maxn] = {};
        for (int i = 0; i < len; i++) s[len - 1 - i] = d[i] + '0';
        return s;
    }
//std
istream& operator >> (istream& in, longlong& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream& out, const longlong& x)
{
    out << x.str();
    return out;
}
