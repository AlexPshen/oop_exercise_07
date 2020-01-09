#ifndef _TRIGON_H_
#define _TRIGON_H_

#include <iostream>
#include "figure.h"
#include "point.h"

struct trigon : public fig{
private:
    point l, r, top;
public:
    trigon(std::istream& is){
        is >> l.x >> l.y >> r.x >> r.y >> top.x >> top.y;
        if((top.x - l.x) * (r.y - l.y) == (top.y - l.y) * (r.x - l.x)){
            throw std::logic_error("It is not trigon");
        }
    }

    point center() const override;
    double square() const override;
    void print(std::ostream& os) const override;
    void print_dop(std::ostream& os) const override;
        
};

#endif
