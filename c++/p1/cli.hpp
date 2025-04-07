#include <string>
#include <iostream>

#pragma once

struct CropWindow {
    int x0;
    int x1;
    int y0;
    int y1;
};

inline std::ostream& operator<<(std::ostream& os, const CropWindow& cw) {
    return os << cw.x0 << " " << cw.x1 << " " << cw.y0 << " " << cw.y1;
}


struct RunningOptions {
    std::string input_scene_file;
    std::string output_file;
    CropWindow cropWindow;
    bool quick;
};

inline std::ostream& operator<<(std::ostream& os, const RunningOptions& options) {
    os << "Input file: " << options.input_scene_file
       << "\nOutput file: " << options.output_file
       << "\nQuick: " << std::boolalpha << options.quick
       << "\nCrop: " << options.cropWindow;
    return os;
}

RunningOptions parse_args(int argc, char* argv[]);