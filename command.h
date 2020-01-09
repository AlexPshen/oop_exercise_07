#ifndef OOP7_COMMAND_H
#define OOP7_COMMAND_H
#include "document.h"

#include "document.h"

struct doc_oper : private document{
private:
    struct command{
        size_t id;
        std::shared_ptr<fig> ptr;
        std::string comm;
    };

    std::vector<std::shared_ptr<command>> opers;
public:
    void add(std::istream& is, size_t id){
        add_fig(is, id);
        std::shared_ptr<fig> fig = get_fig(id);
        std::shared_ptr<command> oper = std::make_shared<command>();
        oper -> id = id;
        oper -> ptr = fig;
        oper -> comm = "add";
        opers.push_back(oper);
    }

    void erase(size_t id){
        std::shared_ptr<fig> fig = get_fig(id);
        erase_fig(id);
        std::shared_ptr<command> oper = std::make_shared<command>();
        oper -> id = id;
        oper -> ptr = fig;
        oper -> comm = "erase";
        opers.push_back(oper);
    }

    void undo(){
        if(opers.size() == 0) {
            std::cout << "operations list is empty \n";
            return;
        }
        std::shared_ptr<command> oper = std::make_shared<command>();
        oper = opers.back();
        if(oper -> comm == "add"){
            erase_fig(oper -> id);
        } else if(oper -> comm == "erase"){
            add_fig_dop(oper -> ptr, oper -> id);
        } else {
            std::cout << "ERROR";
            opers.pop_back();
            return;
        }
        opers.pop_back();
    }

    void save(std::ostream& os){
        save_fig(os);
    }

    void load(std::ifstream& is){
        load_fig(is);
    }

    void print(std::ostream& os){
        print_fig(os);
    }
};

#endif //OOP7_COMMAND_H
