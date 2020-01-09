#ifndef D_DOCUMENT_H_
#define D_DOCUMENT_H_


#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <algorithm>
#include "figure.h"
#include <vector>
#include "factory.h"



struct document{
public:
    document() = default;

    void save_fig(std::ostream& os) const {
        for (size_t i = 0; i < figs.size(); ++i) {
            figs[i] -> print_dop(os);
        }
    }

    void load_fig(std::ifstream& is){
        while(!is.eof()){
            std::shared_ptr<fig> ptr;
            ptr = fact.fig_create_file(is);
            if(ptr == nullptr){
                break;
            }
            figs.push_back(ptr);
        }
    }


    void print_fig(std::ostream& os) const {
        if(figs.size() == 0) {
            os << "Empty\n";
            return;
        }
        for (size_t i = 0; i < figs.size(); ++i) {
            os << "figure " << i << ":" << "\n";
            figs[i] -> print(os);
            os << "center :" << "[" << figs[i] -> center().x << ", " << figs[i] -> center().y << "]" <<  "\n";
            os << "square :" << figs[i] -> square() << "\n";
        }
    }

    void add_fig(std::istream& is, size_t id){
        std::shared_ptr<fig> ptr = fact.fig_create(is);
        figs.insert(figs.begin() + id, ptr);
    }

    void erase_fig(size_t id){
        figs.erase(figs.begin() + id);
    }

    std::shared_ptr<fig> get_fig(size_t id) {
        if (id >= figs.size()) {
            return nullptr;
        }
        return figs[id];
    }

    void add_fig_dop(std::shared_ptr<fig>& ptr, size_t id){
        figs.insert(figs.begin() + id, ptr);
    }
    


private:
    factory fact;
    std::vector<std::shared_ptr<fig>> figs;
};



#endif
