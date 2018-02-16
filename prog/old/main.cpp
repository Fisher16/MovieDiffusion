#include "movie.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

int main(){
/*    movie m1;
    movie m2(123,5,7);
    movie m3(321,-2,-2,1,1);
//    m1.print();
//    m2.print();
//    m3.print();
    movie m4(456,2,-2,-1,1);
    ofstream ofile;
    ofile.open("d3.txt");
    double dt=0.0007;
    for(double t=0;t<3;t+=dt){
        m4.nextPos(dt);
        m3.nextPos(dt);
        m4.collision(m3);
        ofile<<t<<" "<<m4.x<<" "<<m4.y<<" ";
        ofile<<m3.x<<" "<<m3.y<<endl;
    }
    ofile.close();
*/
    list<movie> mList;
    int n=50;
    //Generation
    for(int i=0;i<n;++i){
        movie* m=new movie((double)i,(double)(i*2),(double)(i*2));
        mList.push_back(*m);
    }


    ofstream ofile;
    ofile.open("d4.txt");
    double dt=0.0007;

    for(double t=0;t<3;t+=dt){
        for (auto& i : mList) {
            for (auto& j : mList)i.collision(j);
            i.nextPos();
        }
        ofile<<(mList.front()).x<<" "<<(mList.front()).y<<endl;
    }
    ofile.close();
    return 0;
}
