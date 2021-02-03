#include <string>
#include <cstring>
#include <iostream>

class String
{
    struct StrImpl;
    struct SymWrap;
    StrImpl *pimpl;
public:
    String();
    String(const String &other);
    String(const char *str);
    String& operator=(const String &other);
    String& operator+=(const char *str);
    String::SymWrap operator[](size_t index);
    char operator[](size_t index) const;
    operator std::string() const;
    void copy();
    ~String();
};

struct String::StrImpl
{
    char *data;
    int strcount;
    size_t len;
    StrImpl (char *newbuf = nullptr, int count = 1, size_t len = 0) : data{newbuf}, strcount{count}, len{len} {};
    ~StrImpl() {
        delete [] data;
    }
};

struct String::SymWrap
{
    String *orig;
    size_t orig_idx;
    char sym;
    SymWrap (String *str, size_t orig_index, char sym) : orig {str}, orig_idx {orig_index}, sym {sym} {};
    char operator=(char newsym) {
        orig->copy();
        orig->pimpl->data[orig_idx] = newsym;
        return newsym;
    }
    operator char(){
        return sym;
    }
};

String::String() : pimpl {new StrImpl{}} {}

String::String(const String &other) : pimpl {other.pimpl} {
    pimpl->strcount++;
}

String::String(const char *str) {
    size_t length = strlen(str);
    char *newbuf = new char[length + 1];
    for (size_t i = 0; i < length; i++) {
        newbuf[i] = str[i];
    }
    newbuf[length] = '\0';
    pimpl = new StrImpl(newbuf, 1, length);
}
String & String::operator=(const String &other) {
    if (&other != this) {
        pimpl->strcount--;
        if (pimpl->strcount <= 0) {
            delete pimpl;
        }
        pimpl = other.pimpl;
        pimpl->strcount++;
    }
    return *this;
}

String::SymWrap String::operator[](size_t index) {
    return SymWrap(this, index, pimpl->data[index]);
}

char String::operator[](size_t index) const {
    return pimpl->data[index];
}

String & String::operator+=(const char *str) {
    size_t length = pimpl->len + strlen(str);
    char *newbuf = new char[length + 1];
    for (size_t i = 0; i < pimpl->len; i++) {
        newbuf[i] = pimpl->data[i];
    }
    for (size_t i = pimpl->len; i < length; i++) {
        newbuf[i] = str[i - pimpl->len];
    }
    newbuf[length] = '\0';
    pimpl->strcount--;
    if (pimpl->strcount <= 0) {
        delete pimpl;
    }
    pimpl = new StrImpl(newbuf, 1, length);
    return *this;
}

String::operator std::string() const {
    return std::string(pimpl->data);
}

void String::copy() {
    if (pimpl->strcount > 1) {
        char *newbuf = new char[pimpl->len + 1];
        for (size_t i = 0; i < pimpl->len; i++) {
            newbuf[i] = pimpl->data[i];
        }
        newbuf[pimpl->len] = '\0';
        pimpl->strcount--;
        if (pimpl->strcount <= 0) {
            delete pimpl;
        }
        pimpl = new StrImpl(newbuf, pimpl->strcount, pimpl->len);
    }
}

String::~String() {
    pimpl->strcount--;
    if (pimpl->strcount <= 0) {
        delete pimpl;
    }
}