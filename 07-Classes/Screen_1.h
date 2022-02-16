//
// Created by CottonCandyZ on 2/13/22.
//

#ifndef C__PRIMER_SCREEN_1_H
#define C__PRIMER_SCREEN_1_H

#include <string>

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default;

    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }

    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c) { // 最好将 inline 写在类外侧
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

#endif //C__PRIMER_SCREEN_1_H
