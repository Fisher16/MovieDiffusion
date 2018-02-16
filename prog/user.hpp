#ifndef _user_hpp_
#define _user_hpp_
#include <cstdlib>
#include <iostream>
#include <vector>
#include "movie.hpp"

class user{
public:
    int id;
    double x,y;
    double vx,vy;
    double r,m;
    std::vector<int> interactions;

public:
    user();
    user(int,double, double, double, double);
    user(int,double, double);
    ~user();
    void setR(double);
    void setM(double);
    void print();

    void collision(movie&,double=0.001);
    void border(double,double);
    void nextPos(double=0.001);
};



#endif
