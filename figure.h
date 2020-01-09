#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include "point.h"

struct fig{
    virtual point center() const = 0;
    virtual double square() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void print_dop(std::ostream& os) const = 0;
    virtual ~fig () {}                                                                      
};

#endif
