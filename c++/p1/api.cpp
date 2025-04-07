#include "api.hpp"
#include "xml.hpp"
#include <iostream>

API::API(RunningOptions param_options)
    : background(), film(), options(param_options) {}


void API::run() {
    std::cout << "API running" << std::endl;
    try {
        parse(options.input_scene_file);
    } catch(std::runtime_error err) {
        throw err;
    }
}