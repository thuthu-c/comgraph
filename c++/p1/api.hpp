#include "rt3.hpp"
#include "cli.hpp"

#pragma once

class API {
public:
    Background background;
    Film film;
    RunningOptions options;
    void render();
    void run();
    API(RunningOptions options);
};