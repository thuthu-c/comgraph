#include <cstdint>

#pragma once

struct Color24
{
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue; 
};

struct Point2 {
    int x;
    int y;
};

struct Point3 {
    int x;
    int y;
    int z;
};

class Pixel{
    public:
        Color24 color;
        Point2 coordinate;
};

