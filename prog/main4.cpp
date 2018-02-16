#include "movie.hpp"
#include "user.hpp"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

void test1(){
        movie m1;
        movie m2(123,5,7);
        movie m3(321,-2,-2,1,1);
        m1.print();
        m2.print();
        m3.print();
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

}
void genXY(vector<movie> mVec,string fName){
    ofstream o;
    o.open(fName);
    for (auto& i : mVec)o<<i.x<<" "<<i.y<<endl;
    o.close();
}

int main(){

    vector<movie> mList;
    int n=16000;
    //Generation
    string line;
    ifstream ifile( "mdb49.csv" );
    ifile>>line;
    cout<<line<<endl;
    for(int i=0;i<n;++i){
        //#avg,id,popularity,profit,ratio,title
        getline( ifile, line , ',');
        double avgX=stod(line);
        getline( ifile, line , ',');
        int id=stoi(line);
        getline( ifile, line , ',');
        double popularity=stod(line);
        getline( ifile, line , ',');
        double profit=stod(line);
//        cout<<"profitok"<<endl;
        getline( ifile, line , ',');
//        cout<<line<<endl;
        double ratio=stod(line);
//        cout<<i<<endl;
        getline( ifile, line);

        double fluctuations=(double)rand()/RAND_MAX;
        avgX*=5;
        double F=2*avgX+5*profit+25*ratio+2*fluctuations;

        movie* m=new movie(id,avgX,F);
        m->setF(F);
        mList.push_back(*m);
        //cout<<avgX<<" "<<id<<" "<<popularity<<" "<<profit<<" "<<line<<" "<<fluctuations<<endl;
    }
    genXY(mList,"xy16kt0");
//    movie* test0=new movie(000,0,0,0,0);
//    mList.push_back(*test0);
//    for(int i=50;i<100;++i)mList[i].print();
    ofstream ofile;
    ofile.open("d16k.txt");
    double dt=0.001;

//max force 140
    double a=-150;
    double b=150;
//usercreation
    user u1(49,50,50);

    for(double t=0;t<10;t+=dt){
        for (auto& i : mList) {
            for (auto& j : mList)i.collision(j,dt);
            i.nextPos(dt);
//            if((int)(t*10)%10&&i.id<25)ofile<<t<<" "<<i.x<<" "<<i.y<<endl;
            if(i.x<a){i.vx*=-1;i.x=a;}
		    if(i.x>b){i.vx*=-1;i.x=b;}
            if(i.y<a){i.vy*=-1;i.y=a;}
		    if(i.y>b){i.vy*=-1;i.y=b;}
        }
        for (auto& i : mList)u1.collision(i,dt);
        u1.nextPos(dt);
        u1.border(a,b);
        ofile<<u1.x<<" "<<u1.y<<endl;
    }
    ofile.close();
    cout<<u1.interactions.size()<<"test"<<endl<<"nul"<<endl;
    u1.print();
    ofstream o;
    o.open("interactions16k.txt");
    for (auto i = u1.interactions.begin(); i != u1.interactions.end(); ++i)
    o<<*i<<endl;
    o.close();
    genXY(mList,"xy16ktend");

    return 0;
}
