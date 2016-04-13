#ifndef CALCULATEGIRTH_H
#define CALCULATEGIRTH_H

#endif // CALCULATEGIRTH_H
#include <list>
using namespace std;
#ifndef STRUCTNODE
#define STRUCTNODE
struct node{
    float x;
    float y;
    float z;
};
#endif

float calculateGirth(const list<struct node> pclList,float height,float span,list<struct node> & pclOutList);
