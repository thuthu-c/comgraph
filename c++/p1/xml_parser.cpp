#include "xml.hpp"
#include "rapidxml_print.hpp"

#include <fstream>
#include <vector>
#include <iostream>

using namespace rapidxml;

void parse(std::string input_file) {

    std::ifstream file(input_file);
    if (!file)
        throw std::runtime_error("Failed to open file: " + input_file);
    
    std::vector<char> file_content((std::istreambuf_iterator<char>(file)), 
    std::istreambuf_iterator<char>());
    file_content.push_back('\0');

    char* raw_xml = file_content.data();

    xml_document<> doc;
    doc.parse<0>(raw_xml);

    std::cout << doc;
}