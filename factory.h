#ifndef D_FACTORY_H
#define D_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "trigon.h"
#include "rectangle.h"
#include "quadrate.h"
#include <string>

struct factory {
    std::shared_ptr<fig> fig_create(std::istream& is);
    std::shared_ptr<fig> fig_create_file(std::ifstream& is);

};


std::shared_ptr<fig> factory::fig_create(std::istream &is) {
    try {
        std::string comm;
        is >> comm;
        if (comm == "trigon") {
            return std::shared_ptr<fig>(new trigon(is));
        } else if (comm == "quadrate") {
            return std::shared_ptr<fig>(new quadrate(is));
        } else if (comm == "rectangle") {
            return std::shared_ptr<fig>(new rectangle(is));
        } else {
            throw "This is not a figure";
        }
    } catch (const char* f){
        std::cout << f << "\n";
        return nullptr;
    }
}

std::shared_ptr<fig> factory::fig_create_file(std::ifstream &is) {
    try {
        std::string comm;
        is >> comm;
        if (comm == "trigon") {
            return std::shared_ptr<fig>(new trigon(is));
        } else if (comm == "quadrate") {
            return std::shared_ptr<fig>(new quadrate(is));
        } else if (comm == "rectangle") {
            return std::shared_ptr<fig>(new rectangle(is));
        } else {
            throw " ";
        }
    } catch (const char* f){
        std::cout << f << "\n";
        return nullptr;
    }
}


#endif
