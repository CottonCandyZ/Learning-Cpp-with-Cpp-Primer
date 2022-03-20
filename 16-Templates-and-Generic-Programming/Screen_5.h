//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_SCREEN_5_H
#define C__PRIMER_SCREEN_5_H

#include <string>
#include <iostream>

using pos = std::string::size_type;

template<pos H, pos W>
class Screen;

template<pos H, pos W>
std::istream &operator>>(std::istream &, Screen<H, W> &);

template<pos H, pos W>
std::ostream &operator<<(std::ostream &, const Screen<H, W> &);

template<pos H, pos W>
class Screen {
    friend std::ostream &operator<<<H,W>(std::ostream &, const Screen<H,W> &);
    friend std::istream &operator>><H,W>(std::istream &, Screen<H,W> &);

public:
    Screen &set(char); // set cursor 所在位置的值
    Screen &set(pos, pos, char); // 指定位置

    Screen() : contents(H * W, ' ') {}

    Screen(char c) : contents(H * W, c) {}

    char get() const { return contents[cursor]; }

    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    Screen &display(std::ostream &os) { // 普通版本
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const { // 常量版本
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const { os << contents; } // 隐式内联版本
    pos cursor = 0;
    std::string contents;
};

template<pos H, pos W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c) { // 最好将 inline 写在类外侧
    pos row = r * W;
    cursor = row + c;
    return *this;
}

template<pos H, pos W>
char Screen<H, W>::get(pos r, pos c) const {
    pos row = r * W;
    return contents[row + c];
}

template<pos H, pos W>
inline Screen<H, W> &Screen<H, W>::set(char c) {
    contents[cursor] = c;
    return *this;
}

template<pos H, pos W>
inline Screen<H, W> &Screen<H, W>::set(pos r, pos col, char ch) {
    contents[r * W + col] = ch;
    return *this;
}

template<pos H, pos W>
std::istream &operator>>(std::istream &is, Screen<H, W> &s) {
    std::string input;
    is >> input;
    for (char ch : input) s.set(ch);
    return is;
}

template<pos H, pos W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &s) {
    for (pos r = 0; r != H; ++r) {
        for (pos c = 0; c != W; ++c) {
            os << s.get(r, c);
        }
        os << std::endl;
    }
    return os;
}

#endif //C__PRIMER_SCREEN_5_H
