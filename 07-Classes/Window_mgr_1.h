//
// Created by CottonCandyZ on 2/13/22.
//

#ifndef C__PRIMER_WINDOW_MGR_1_H
#define C__PRIMER_WINDOW_MGR_1_H

#include <vector>
#include "Screen_1.h"

class Window_mgr {
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};

};

#endif //C__PRIMER_WINDOW_MGR_1_H
