#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "setUser.h"
#include "loadTables.h"
#include "help.h"
#include "login.h"
#include "csvParse.h"



// TODO MAKE THIS ALL TOKENIZED AND TRY TO AVOID A FOREVER LONG IF CASE



void print_prompt() {
    std::cout <<  loggedUser + "db >";
}

int main() {


std::array<std::string, 5> keywords = {"SELECT", "*", "FROM", "TEST"};





    while (true) {
        print_prompt();
        std::string input;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        std::vector<std::string> tokens;
        std::string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            continue;
        }

        const std::string& command = tokens[0];

        if (input == "HELP") {
            help();
            continue;
        }

        if (input == "EXIT" || input == "QUIT") {
            std::cout << "exiting db" << std::endl;
            break;
        }

        if (input == "MKUSR") {
            mkUser();
            continue;
        }

        if (input == "-V" || input == "-VERSION") {
            std::cout << "1.0.0" << std::endl;
            continue;
        }

        if (input == "GETUSR") {
            getUserString();
            continue;
        }

        if (input == "LOGIN") {
            loginUser();
            continue;
        }


        if (input == "TESTPARSE") {
            testParse();
            continue;
        }





        if (input == "\\s") {
            //listSpaces();
            continue;
        }

        bool containsKnownCommand = std::any_of(tokens.begin(), tokens.end(), [&](const std::string& t) {
            return std::find(keywords.begin(), keywords.end(), t) != keywords.end();
        });

        if (containsKnownCommand) {
            if (tokens.size() >= 3 &&
                tokens[0] == "SELECT" &&
                tokens[1] == "*" &&
                tokens[2] == "FROM") {
                std::cout << "COMMAND SUCCESSFULLY EXECUTED";

                continue;
            } else {
                std::cout << "COMMAND NOT EXECUTED";
                continue;
            }
        }




        std::cout << "unrecognized cmd"<< std::endl;
    }

    return 0;
}


