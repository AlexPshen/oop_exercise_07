#ifndef OOP7_COMMAND_H
#define OOP7_COMMAND_H
#include "document.h"

#include "document.h"

struct doc_oper : private document{
private:
    struct command{
        size_t id;
        std::shared_ptr<fig> ptr;
        virtual void undo(document &doc) = 0;
    };

    std::vector<std::shared_ptr<command>> opers;

    struct add_com : public command{
        void undo(document &doc) override {
            doc.erase_fig(id);
        }
    };
    
    struct remove_com : public command{
        void undo(document &doc) override {
            doc.add_fig_dop(ptr, id);
        }
    };

public:

    void add(std::istream& is, size_t id){
        add_fig(is, id);
        std::shared_ptr<fig> fig = get_fig(id);
        std::shared_ptr<add_com> op = std::make_shared<add_com>();
        op -> id = id;
        op -> ptr = fig;
        opers.push_back(op);
    }

    void erase(size_t id){
        std::shared_ptr<fig> fig = get_fig(id);
        erase_fig(id);
        std::shared_ptr<remove_com> op = std::make_shared<remove_com>();
        op -> id = id;
        op -> ptr = fig;
        opers.push_back(op);
    }

    void undo(){
        if(opers.size() == 0){
            std::cout << "EMPTY";
            return;
        }
        opers[opers.size() - 1] -> undo(*this);
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
