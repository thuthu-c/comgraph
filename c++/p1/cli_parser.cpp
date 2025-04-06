#include "rt3.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>

RunningOptions parse_args(int argc, char* argv[]) {
    const std::vector<std::string> args(argv + 1, argv + argc);

    size_t idx = 0;

    RunningOptions options{};

    for (const auto& arg : args) {
        if (arg == "--help") {
            std::cout << "Usage: rt3 [<options>] <input_scene_file>\n"
                         "Rendering simulation options:\n"
                         "--help                     Print this help text.\n"
                         "--cropwindow <x0,x1,y0,y1> Specify an image crop window.\n"
                         "--quick                   Reduces quality parameters to render image quickly.\n"
                         "--outfile <filename>      Write the rendered image to <filename>."
                      << std::endl;
            std::exit(EXIT_SUCCESS);
        }
         else if (arg == "--cropwindow") {
            const std::vector<std::string> crop_window(args.begin()+idx, args.begin()+idx+4);
            try {
                int x0 = std::stoi(crop_window[0]);
                int x1 = std::stoi(crop_window[0]);
                int y0 = std::stoi(crop_window[0]);
                int y1 = std::stoi(crop_window[0]);
                CropWindow crop{x0, x1, y0, y1};
                options.cropWindow = crop;
                idx += 4;
            } catch(std::invalid_argument) {
                throw std::runtime_error("Invalid cropwindow parameters");
            }
        } else if (arg == "--quick") {
            options.quick = true;

        } else if (arg == "--outfile") {
            std::string outfile = args[idx + 1];
            ++idx;
        } else {
            throw std::runtime_error("No valid option");
        }

        ++idx;
    }
}