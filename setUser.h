#ifndef SETUSER_H
#define SETUSER_H
#include <fstream>

#include <string>
#include <iomanip>
#include <iostream>


struct user {
    std::string username;
    std::string password;
};

inline user currentUser;


inline void setUser() {


    std::cout<<"set username"<<std::endl;
    std::cin >> currentUser.username;

    std::cout<<"set password"<<std::endl;
    std::cin >> currentUser.password;

    std::cout<< currentUser.username + currentUser.password <<std::endl;

    if (std::ofstream userPassw("password.txt"); userPassw.is_open()) {
        std::hash<std::string> stringHash;
        userPassw << stringHash(currentUser.password);
        userPassw << stringHash(currentUser.username);
        userPassw.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }



    }







#endif