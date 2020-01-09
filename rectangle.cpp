#include<iostream>
#include<vector>
#include<cmath>
#include<string.h>

#include "rectangle.h"
#include "figure.h"

void rectangle::print(std::ostream& os) const{
    os << "rectangle: ";
    os << "(" << top1.x << ", " << top1.y << ")" << " ";
    os << "(" << top2.x << ", " << top2.y << ")" << " "; 
    os << "(" << top3.x << ", " << top3.y << ")" << " ";
    os << "(" << top4.x << ", " << top4.y << ")" << " ";  
    os << '\n';
}

void rectangle::print_dop(std::ostream& os) const{
    os << "quadrate ";
    os << top1.x << " " << top1.y << " ";
    os << top2.x << " " << top2.y << " "; 
    os << top3.x << " " << top3.y << " ";
    os << top4.x << " " << top4.y << " ";  
    os << '\n';
}

double rectangle::square() const{
    double scalar1 = scalar_mult(top2, top1, top3);
    double scalar2 = scalar_mult(top2, top1, top4); 
    double scalar3 = scalar_mult(top3, top1, top4);
    double mid1, mid2;
    if(scalar1 == 0){
        mid1 = segment_length(top1, top2);
        mid2 = segment_length(top1, top3);
    } else if(scalar2 == 0){
        mid1 = segment_length(top1, top2);
        mid2 = segment_length(top1, top4);
    } else if(scalar3 == 0){
        mid1 = segment_length(top1, top3);
        mid2 = segment_length(top1, top4);
    }
    return mid1 * mid2;
}


point rectangle::center() const{
    double scalar1 = scalar_mult(top2, top1, top3);
    double scalar2 = scalar_mult(top2, top1, top4); 
    double scalar3 = scalar_mult(top3, top1, top4);
    double midx, midy;
    if(scalar1 == 0){
        midx = (top3.x + top2.x) * 0.5;
        midy = (top3.y + top2.y) * 0.5;
    } else if(scalar2 == 0){
        midx = (top4.x + top2.x) * 0.5;
        midy = (top4.y + top2.y) * 0.5;
    } else if(scalar3 == 0){
        midx = (top3.x + top4.x) * 0.5;
        midy = (top3.y + top4.y) * 0.5;
    }
    return point{midx, midy};
}

