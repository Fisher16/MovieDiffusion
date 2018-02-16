#include "movie.hpp"
#include <random>
#include <cmath>
using namespace std;
double M=1;
double R=0.1;
double T=300;




movie::~movie(){}

movie::movie(){
    id=0;
    x=0;
    y=0;
    vx=1;
    vy=1;
    r=R;
    m=M;
    F=0;
}

movie::movie(int ID,double X,double Y,double Vx,double Vy){
    id=ID;
    x=X;
    y=Y;
    vx=Vx;
    vy=Vy;
    r=R;
    m=M;
    F=0;
}

movie::movie(int ID,double X,double Y){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> NormDist(40,10);
    id=ID;
    x=X;
    y=Y;
    vx=NormDist(gen);
    vy=NormDist(gen)-60;
    r=R;
    m=M;
    F=0;
}

void movie::print(){
    cout<<id<<endl<<x<<" | "<<y<<endl<<vx<<" | "<<vy<<endl<<F<<endl;
}

void movie::collision(movie& m1,double dt){
    double d2=((x-m1.x)*(x-m1.x)+(y-m1.y)*(y-m1.y));
    if(d2<(4*r*r)&&d2>0){
//        cout<<"collision"<<endl;
        double nx=(m1.x-x)/sqrt(d2);
        double ny=(m1.y-y)/sqrt(d2);
        double p=1*(vx*nx+vy*ny-m1.vx*nx-m1.vy*ny);
        m1.vx+=p*nx;
        m1.vy+=p*ny;
        vx-=p*nx;
        vy-=p*ny;

        m1.x+=m1.vx*2*dt;
        m1.y+=m1.vy*2*dt;
        x+=vx*2*dt;
        y+=vy*2*dt;
    }
}

void movie::nextPos(double dt){
    x+=vx*dt;
    y+=vy*dt;
}

void movie::setF(double Force){
    F=Force;
}
