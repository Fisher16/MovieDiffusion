#include "user.hpp"
#include <random>
#include <cmath>
using namespace std;
double uM=2;
double uR=0.2;




user::~user(){
    //vector destroyed automatically
}

user::user(){
    id=0;
    x=0;
    y=0;
    vx=1;
    vy=1;
    r=uR;
    m=uM;
}

user::user(int ID,double X,double Y,double Vx,double Vy){
    id=ID;
    x=X;
    y=Y;
    vx=Vx;
    vy=Vy;
    r=uR;
    m=uM;

}

user::user(int ID,double X,double Y){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> NormDist(40,10);
    id=ID;
    x=X;
    y=Y;
    vx=NormDist(gen);
    vy=NormDist(gen)-60;
    r=uR;
    m=uM;
}

void user::print(){
    cout<<id<<endl<<x<<" | "<<y<<endl<<vx<<" | "<<vy<<endl;
}

void user::collision(movie& m1,double dt){
    double d2=((x-m1.x)*(x-m1.x)+(y-m1.y)*(y-m1.y));
    //YForce
    if(sqrt(vx*vx+vy*vy)<1000){
        if(y-m1.y>0)vy+=-m1.F/d2/m;
        else vy-=-m1.F/d2/m;
        if(y-m1.x>0)vx+=-m1.F/d2/m;
        else vx-=-m1.F/d2/m;
    }
    if(d2<(4*r*r)&&d2>0){
//        cout<<"collision"<<endl;
        interactions.push_back(m1.id);
        double nx=(m1.x-x)/sqrt(d2);
        double ny=(m1.y-y)/sqrt(d2);
        double p=2/(m+m1.m)*(vx*nx+vy*ny-m1.vx*nx-m1.vy*ny);
        m1.vx+=p*m1.m*nx;
        m1.vy+=p*m1.m*ny;
        vx-=p*m*nx;
        vy-=p*m*ny;

        m1.x+=m1.vx*2*dt;
        m1.y+=m1.vy*2*dt;
        x+=vx*2*dt;
        y+=vy*2*dt;
    }
}

void user::nextPos(double dt){
    x+=vx*dt;
    y+=vy*dt;
}

void user::border(double a, double b){
    if(x<a){vx*=-1;x=a;}
    if(x>b){vx*=-1;x=b;}
    if(y<a){vy*=-1;y=a;}
    if(y>b){vy*=-1;y=b;}
}
