#include <algorithm>
#include <iostream>
#include <string>
#include "setUser.h"
#include "loadTables.h"
#include "help.h"



void print_prompt() {
    std::cout << "db >";
}

int main() {
    std::string input;



    while (true) {
        print_prompt();
        std::cin >> input;

        if (input == "HELP") {
            help();
            continue;
        }

        if (input == "EXIT" || input == "QUIT") {
            std::cout << "exiting db" << std::endl;
            break;
        }

        if (input == "SETUSR") {
            setUser();
            continue;
        }

        if (input == "\\s") {
            listSpaces();
            continue;
        }



        std::cout << "unrecognized cmd"<< std::endl;
    }

}


