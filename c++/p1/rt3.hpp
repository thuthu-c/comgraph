#include <vector>
#include "math_operators.hpp"

#pragma once

class Film {
    public:
        std::vector<std::vector<Color24>> roll;
};

class Background {
    public:
        std::vector<std::vector<Color24>> background;
        Color24 get_color_from_coordinates(Point2 coordinates);
};