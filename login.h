#ifndef LOGIN_H
#define LOGIN_H
#include <fstream>
#include "setUser.h"
#include <string>
#include <iomanip>
#include <iostream>

int loginUser() {
    std::cout << "Enter your username: ";
    std::string username;
    std::cin >> username;

    std::cout << "Enter your password: ";
    std::string password;
    std::cin >> password;

    std::ifstream file("password.txt");
    std:: string storedUsername;
    std::string storedHash;

    if (!file.is_open()) {
        return false;
    };

    while (file >> storedUsername >> storedHash) {
        if (storedUsername == username && storedHash == password) {
            std::cout << "SUCCESSFULLY LOGIN" << std::endl;
            return true;
        } else {
            std::cout << "INVALID USERNAME" << std::endl;
            return false;
        }
    }


}

#endif