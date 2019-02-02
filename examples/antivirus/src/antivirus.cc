#include <iostream>
#include <cstdlib>

#include <buckler/buckler.hpp>
#include <buckler/base.hpp>


int main(int argc, char* argv[]) {
    if (argc < 1) {
        std::cerr << "[err] argument not found." << std::endl;
        std::exit(1);
    }

    std::vector<unsigned char> buffer = {};

    std::fstream fs;

    fs.open(argv[1], std::ios::in | std::ios::binary);
    char data;

    if (fs.fail()) {
        std::cerr << "failed to open file\n" << std::endl;
        std::exit(1);
    }

    while(!fs.eof()){
        fs.read(&data, sizeof(char));
        buffer.push_back(data);
    }
    buffer.pop_back();

    auto target = buckler::Target(buffer);
    auto buckler = buckler::Buckler(target);

    buckler.Load();

    auto result = buckler.Scan();
    if (result.has_hit) {
        std::cout << "`" << argv[1]
            << "` is malware." << std::endl;
    } else {
        std::cout << "`"<< argv[1]
            << "` is not malware." << std::endl;
    }
}
