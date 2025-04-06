#include <string>

struct CropWindow {
    int x0;
    int x1;
    int y0;
    int y1;
};

struct RunningOptions {
    std::string input_scene_file;
    std::string output_file;
    CropWindow cropWindow;
    bool quick;
};