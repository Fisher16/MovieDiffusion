#ifndef _movie_hpp_
#define _movie_hpp_
#include <cstdlib>
#include <iostream>

class movie{
public:
    int id;
    double x,y;
    double vx,vy;
    double r,m;
    double F;

public:
    movie();
    movie(int,double, double, double, double);
    movie(int,double, double);
    ~movie();
    void setF(double);
    void setR(double);
    void setM(double);
    void print();

    void collision(movie&,double=0.0007);
    void nextPos(double=0.0007);
};



#endif
