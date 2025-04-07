#include<iostream>
#include "cli.hpp"
#include "api.hpp"

#include <iostream>
int main(int argc, char* argv[]) {
    RunningOptions options = parse_args(argc, argv);
    API api = API(options);
    
    try {
        api.run();
    } catch(std::runtime_error err) {
        std::cout << err.what() << std::endl;
        return 0;
    }
}