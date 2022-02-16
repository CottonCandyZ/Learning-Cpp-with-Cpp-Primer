//
// Created by CottonCandyZ on 2/14/22.
//

#ifndef C__PRIMER_SCREEN_2_E_H
#define C__PRIMER_SCREEN_2_E_H

#include <string>

class Screen {
public:

    using pos = std::string::size_type; // 有顺序，这个必须在上面

    Screen set(char); // set cursor 所在位置的值
    Screen set(pos, pos, char); // 指定位置

    Screen() = default;

    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }

    inline char get(pos ht, pos wd) const;

    Screen move(pos r, pos c);

    Screen display(std::ostream &os) { // 普通版本
        do_display(os);
        return *this;
    }

    const Screen display(std::ostream &os) const { // 常量版本
        do_display(os);
        return *this;
    }


private:
    void do_display(std::ostream &os) const { os << contents; } // 隐式内联版本

    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

};

inline Screen Screen::move(pos r, pos c) { // 最好将 inline 写在类外侧
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}



#endif //C__PRIMER_SCREEN_2_E_H
