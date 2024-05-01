#include <iostream>
#include <fstream>
#include <sstream>

struct Config {
    int width = 0;
    int height = 0;
    bool hasRed = false;
    bool hasGreen = false;
    bool hasBlue = false;
};

int main() {
    Config config;
    //prompting config parameters
    std::cout << "Enter width: ";
    std::cin >> config.width;

    std::cout << "Enter height: ";
    std::cin >> config.height;

    std::cout << "Enter if you want the color red (0 for false, 1 for true): ";
    std::cin >> config.hasRed;

    std::cout << "Enter if you want the color green (0 for false, 1 for true): ";
    std::cin >> config.hasGreen;

    std::cout << "Enter if you want the color blue (0 for false, 1 for true): ";
    std::cin >> config.hasBlue;

    //creates a file with said parameters and stores it in the output directory
    std::ostringstream filename;
    filename << "../../output/" << config.width << "_" << config.height << "_"
             << (config.hasRed ? "1" : "0")
             << (config.hasGreen ? "1" : "0")
             << (config.hasBlue ? "1" : "0")
             << ".ppm";
    std::cout << filename.str();
    std::ofstream file(filename.str());
    
    //starts population the file
    file << "P3\n" << config.width << " " << config.height << "\n255\n";

    for (int j = 0; j < config.width; j++) {
        for (int i = 0; i < config.height; i++) {
            auto r = config.hasRed ? double(i) / (config.width - 1) : 0.0;
            auto g = config.hasGreen ? double(j) / (config.height - 1) : 0.0;
            auto b = config.hasBlue ? double (i + j) / (config.width + config.height - 2): 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cout << "Done\n";

    return 0;
}