#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "figure.h"
#include "factory.h"
#include "command.h"

int main() {
    factory fact;
    std::unique_ptr<doc_oper> doc = std::make_unique<doc_oper>();
    while(1){
        std::string command;
        std::cin >> command;
        if(command == "save"){
            std::string path;
            std::cin >> path;
            std::ofstream os(path);
            doc -> save(os);
            os.close();
        }else if(command=="load"){
            std::string path;
            std::cin >> path;
            std::ifstream is(path);
            if(is) {
                doc -> load(is);
            }else {
                std::cout << "No such file\n";
            }
            is.close();
        }else if(command=="add"){
            size_t id;
            std::cin >> id;
            doc -> add(std::cin, id);
        }else if(command=="erase"){
            size_t id;
            std::cin >> id;
            doc -> erase(id);
        }else if(command=="print"){
            doc -> print(std::cout);
        }else if(command == "undo"){
            doc -> undo();
        } else if(command == "exit"){
            break;
        }
    }
    return 0;
}

