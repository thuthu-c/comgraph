
#include <iostream>
#include <cstdint>
#include <memory>
#include <fstream>


using byte = std::uint8_t;

void save_ppm6(const std::string& filename, const byte *buffer, size_t width, size_t height, short channels){
    std::ofstream fs (filename, std::ios::out); 

    fs << "P3\n";
    fs << width << " " << height << '\n'; 
    fs << "255\n"; 

    size_t total_bytes{width * height * channels}; 

    for(auto idx{0}; idx < total_bytes; idx+=3){
        fs << (short) buffer[idx] << " " << (short) buffer[idx+1] << " " << (short) buffer[idx+2] << "\n"; 
         
    }

    fs.close(); 

}

int main () {
    constexpr size_t width{400}; //usigned long long int
    constexpr size_t heigth{200};
    constexpr short channels{3};
    constexpr size_t total_bytes{width * heigth * channels}; 

    std::unique_ptr<byte[]> image = std::make_unique<byte[]>(total_bytes);

    constexpr byte max_value {255};
    constexpr float blue_percentage{0.2};

    byte blue_channel_value = (byte) (blue_percentage*max_value);

    size_t idx{0}; 

    for(auto row{0}; row < heigth; ++row){
        byte green_channel_value = static_cast<byte>((max_value * row) / static_cast<float>(heigth) + 0.5f);

        for(auto col{0}; col < width; ++col){

            byte red_channel_value = static_cast<byte>((max_value * col) / static_cast<float>(width) + 0.5f);
            


        
            image[idx+0] = red_channel_value;
            image[idx+1] = green_channel_value;
            image[idx+2] = blue_channel_value; 


            idx +=3; 

        }
    }

    save_ppm6("background.ppm", image.get(), width, heigth, channels); 


    return 0;
    
}