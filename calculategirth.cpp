#include <iostream>
#include <math.h>
#include "calculategirth.h"
#include "Link.class.h"
#include "convelHull.func.h"

using namespace std;

double distanceOfTwoPoint(double x1,double y1,double z1,double x2,double y2,double z2)
{
    double dx=x2-x1;
    double dy=y2-y1;
    double dz=z2-z1;
    return sqrt(dx*dx+dy*dy+dz*dz);
}
void calculateGirth(Link * link,double * girth,int curve=1)//当curve==1时，计算的是曲线的长度，当curve==0时，计算的是围长
{
    *girth=0.0;
    Node * tmp=link->pointOfSpecificElement(1);
    Node * tmp2=tmp;
    if(tmp2==NULL) return;
    while(tmp!=NULL && tmp->next!=NULL)
    {
        *girth+=distanceOfTwoPoint(tmp->x,tmp->y,tmp->z,tmp->next->x,tmp->next->y,tmp->next->z);
        tmp=tmp->next;
    }
    if(curve==0)
    {
        *girth+=distanceOfTwoPoint(tmp->x,tmp->y,tmp->z,tmp2->x,tmp2->y,tmp2->z);
    }
}

void calculateSpecificHeight(Link * link_bodyNoArm,double height,float span,double * girth,Link * link_out)//获取特定高度位置的围长
{
    Link * link_tmp=new Link();
    {//构建特定高度的链表
        Node * tmp=link_bodyNoArm->pointOfSpecificElement(1);
        while(tmp!=NULL)
        {
            if(tmp->y>height-span && tmp->y<height+span)
            {
                link_tmp->add(tmp->x,tmp->y,tmp->z);
                //link_out->add(tmp->x,tmp->y,tmp->z);
            }
            tmp=tmp->next;
        }
    }

    /*char * filename="tmppcllist.txt.asc";
    FILE * fp=fopen(filename,"w");

    Node * tmptmp=link_tmp->pointOfSpecificElement(1);
    while(tmptmp!=NULL)
    {
        fprintf(fp,"%lf %lf %lf\n",tmptmp->x,tmptmp->z,0.0);
        tmptmp=tmptmp->next;
    }
    fclose(fp);*/

    //link_out->copy(link_tmp);
    {//使用凸包算法计算围长
        convelHull(link_tmp,5);
        //link_out->copy(link_tmp);
        //pinghua2(link_tmp,PINGHUA);
        calculateGirth(link_tmp,girth,0);
    }
    link_out->copy(link_tmp);
    //saveToFile(link_tmp,filename2);
    delete link_tmp;
}

float calculateGirth(list<node> pclList,float height,float span,list<struct node> & pclOutList)
{
    double girth=0.0;
    Link * tmpLink=new Link();
    Link * linkOut=new Link();
    list<node>::iterator it;
    for(it=pclList.begin();it!=pclList.end();++it)
    {
        tmpLink->add((*it).x,(*it).y,(*it).z);
    }


    calculateSpecificHeight(tmpLink,height,span,&girth,linkOut);
    Node * tmp=linkOut->pointOfSpecificElement(1);
    struct node tmpNode;
    while(tmp!=NULL)
    {
        tmpNode.x=tmp->x;tmpNode.y=tmp->y;tmpNode.z=tmp->z;
        pclOutList.push_back(tmpNode);
        tmp=tmp->next;
    }
    delete tmpLink;
    delete linkOut;
    return girth;
}
