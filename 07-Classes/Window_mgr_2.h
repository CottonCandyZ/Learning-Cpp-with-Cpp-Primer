//
// Created by CottonCandyZ on 2/14/22.
//

#ifndef C__PRIMER_WINDOW_MGR_2_H
#define C__PRIMER_WINDOW_MGR_2_H

#include <vector>

class Screen;
class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    Window_mgr();

private:
    std::vector<Screen> screens;
};


#endif //C__PRIMER_WINDOW_MGR_2_H
