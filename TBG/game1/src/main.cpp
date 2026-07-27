#include <cctype>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "../include/terminal.cpp"

std::string filename = "../gamedata/savegame.txt";

void print_text(std::string imagename, int speed) {
    std::ifstream file(imagename);
    
    if(!file.is_open()) {
        std::cerr << "Error loading image.\n";
        return;
    }
    
    std::cout << "\n";
    
    std::string line;

    while(std::getline(file, line)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        std::cout << line << std::endl;
    }
}

void draw_image(std::string imagename) {
    std::string drawimage = "../include/ascii-view/ascii-view " + imagename;
    
    int result = std::system(drawimage.c_str());
}

int main() {
    lock_terminal_size(32, 114);
    std::ofstream file(filename);
    
    if(!file.is_open()) {
        std::cerr << "No savegame." << std::endl;
        return -1;
    }

    bool is_started = false;
    char select = ' ';

    while(!is_started) {
        draw_image("../resources/images/castle1.png");
        print_text("../resources/start-game.txt", 50);
        print_text("../resources/yes-no.txt", 50);

        std::cin >> select;

        select = std::tolower(select);

        if(select == 'y') {
            is_started = true;
            break;
        }
    }

    while(is_started) {

    }

}
