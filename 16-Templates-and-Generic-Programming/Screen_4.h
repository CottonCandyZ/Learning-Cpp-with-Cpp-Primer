//
// Created by CottonCandyZ on 3/17/22.
//

#ifndef C__PRIMER_SCREEN_4_H
#define C__PRIMER_SCREEN_4_H

#include <string>

using pos = std::string::size_type;

template<pos H, pos W>
class Screen {
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

#endif //C__PRIMER_SCREEN_4_H
