
#include <iostream>
#include <cstdint>
#include <memory>
#include <fstream>


using byte = std::uint8_t;


struct color24
{
    byte R;
    byte G;
    byte B; 
};


color24 lerp(const color24 &A, const color24 &B, float t){
    byte rchannel = (1-t)*A.R + (t*B.R); 
    byte gchannel = (1-t)*A.G + (t*B.G); 
    byte bchannel = (1-t)*A.B + (t*B.B); 

    return color24{rchannel,gchannel,bchannel}; 
}

color24 lerp_point (const color24 &A, const color24 &B, const color24 &C, const color24 &D, float u, float v){
   color24 Xb=  lerp(A, B, u); 
   color24 Xt = lerp(C,D,u); 
   return lerp(Xb, Xt, v); 
}




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

    constexpr color24 corner1{255, 0, 0};
    constexpr color24 corner2{0, 255, 0};
    constexpr color24 corner3{0, 0, 255};
    constexpr color24 corner4{255, 255, 0};

    constexpr size_t width{400}; //usigned long long int
    constexpr size_t heigth{200};
    constexpr short channels{3};
    constexpr size_t total_bytes{width * heigth * channels}; 

    std::unique_ptr<byte[]> image = std::make_unique<byte[]>(total_bytes);

    constexpr byte max_value {255};
    auto idx{0}; 

    for(auto i{0}; i < heigth; ++i){
        for(auto j{0}; j < width; ++j){
            color24 point = lerp_point(corner1, corner2, corner3, corner4,(float) ((100*j)/width)/100, (float) ((100*i)/heigth)/100 );

            image[idx] = point.R; 
            image[idx+1] = point.G;
            image[idx+2] = point.B; 

            idx+=3;
        }
    }




    save_ppm6("backgroundtwo.ppm", image.get(), width, heigth, channels); 


    return 0;
    
}