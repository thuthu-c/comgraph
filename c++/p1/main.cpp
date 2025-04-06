#include<iostream>
#include "cli_parser.cpp"

int main(int argc, char* argv[]) {
    RunningOptions options = parse_args(argc, argv);
}