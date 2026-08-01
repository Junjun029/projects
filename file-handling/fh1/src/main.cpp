#include <iostream>
#include <fstream>

int main() {
    std::fstream file;
    file.open("file.txt", std::ios::out);

    if (!file.is_open()) {
        std::cerr << "File can't be opened." << std::endl;
        return -1;
    }
        
    file.write("Sorry", 5);

    std::cout << "file.txt is open? : " << file.is_open() << "\n";

    return 0;
}
