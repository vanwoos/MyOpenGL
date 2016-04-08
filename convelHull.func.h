int RightOrLeft(double x1,double y1,double x2,double y2,double x3,double y3)//判断第三个点在前两个点连成的直线的哪个位置，-1 左边，0，直线上，1 右边
{
	int result;
	if(x1-x2<0.000001 && x1-x2>-0.000001 && y1-y2<0.000001 && y1-y2>-0.000001)
	{
		return 1;
	}
	double X=(y3-y1)*(x2-x1)/(y2-y1)+x1;

	if(X-x3<-0.000001)
	{
		result=1;
	}
	else if(X-x3>0.000001)
	{
		result=-1;
	}
	else{
		result=0;
	}
	if(y2-y1<-0.000001)
	{
		result=-result;
	}
	return result;
}


/*
*该函数对link的所有点进行二维凸包运算
*link中的每个节点保存了一个点的三维坐标，二维凸包运输只会选取其中的两个坐标进行运算
*具体选取哪两个坐标由该函数的type参数决定
*type的合法取值为 3 5 6，取三代表选取yz坐标（3的二进制为011），取5代表选取xz坐标，取6代表选取xy坐标
*执行完凸包运算之后，link中的节点将被修改，所以如有必要，应该手动在调用该函数之前备份参数链表
*运算执行完之后，link的节点的z坐标将被清零，xy坐标将依据type的取值，对应于原始链表的某两个坐标
*
*/
void convelHull(Link * link,int type=5)//对link中的元素进行二维凸包运算，执行后link中只有x,y值有效
{
	if(link->count()<1)
	{
		printf("Warning: no node in link\n");
		return;
		//exit(-1);
	}
	Link * link_tmp=new Link();
	{//对利用link的某两个坐标构造link_tmp
		Node * tmp=link->pointOfSpecificElement(1);
		if(type==3)
		{
			while(tmp!=NULL)
			{
				//此处将link的三维坐标系的某两个映射到函数内使用的link_tmp中，之后的操作将对link_tmp的x,y成员进行操作
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				//可以在此处修改需要对原始的link链表中的哪两个坐标进行凸包运算
				link_tmp->add(tmp->y,tmp->z,0.0);
				//进行凸包运算之后，link的z坐标将被清零，例如此处，link的xy坐标分别对应原始的xz坐标
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				tmp=tmp->next;
			}
		}
		else if(type==5)
		{
			while(tmp!=NULL)
			{
				//此处将link的三维坐标系的某两个映射到函数内使用的link_tmp中，之后的操作将对link_tmp的x,y成员进行操作
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				//可以在此处修改需要对原始的link链表中的哪两个坐标进行凸包运算
				link_tmp->add(tmp->x,tmp->z,0.0);
				//进行凸包运算之后，link的z坐标将被清零，例如此处，link的xy坐标分别对应原始的xz坐标
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				tmp=tmp->next;
			}
		}
		else if(type==6)
		{
			while(tmp!=NULL)
			{
				//此处将link的三维坐标系的某两个映射到函数内使用的link_tmp中，之后的操作将对link_tmp的x,y成员进行操作
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				//可以在此处修改需要对原始的link链表中的哪两个坐标进行凸包运算
				link_tmp->add(tmp->x,tmp->y,0.0);
				//进行凸包运算之后，link的z坐标将被清零，例如此处，link的xy坐标分别对应原始的xz坐标
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				tmp=tmp->next;
			}
		}
		else{
			printf("参数不符合规范\n");
			exit(-1);
		}
	}//link_tmp已经构造完成
	{//将link_tmp中y坐标最小的点放到链表的第一个位置
		Node * tmp=link_tmp->pointOfSpecificElement(0);
		Node * tmp2=tmp;
		while(tmp!=NULL && tmp->next!=NULL)
		{
			if(tmp->next->y<tmp2->next->y)
			{
				tmp2=tmp;
			}
			tmp=tmp->next;
		}//tmp2指向y坐标最小的节点的前一个节点
		link_tmp->add(tmp2->next->x,tmp2->next->y,tmp2->next->z);
		link_tmp->del(tmp2);
	}//y坐标最小的元素已经是链表的第一个节点
	Node trans;//保存此时平移的距离，以便于最后把它们平移回来
	{//所有点平移，使link_tmp第一个节点的坐标是坐标原点
		trans.x=link_tmp->pointOfSpecificElement(1)->x;
		trans.y=link_tmp->pointOfSpecificElement(1)->y;
		//trans.z=link_tmp->pointOfSpecificElement(1)->z;
		Node * tmp=link_tmp->pointOfSpecificElement(1);
		while(tmp!=NULL)
		{
			tmp->x-=trans.x;
			tmp->y-=trans.y;
			//tmp->z-=trans.z;
			tmp=tmp->next;
		}
	}//所有点的平移完成
	{//从第二个点开始按与第一个点的距离从小到大排序
		Node * tmp1=link_tmp->pointOfSpecificElement(0);
		Node * tmp2=tmp1->next;
		while(tmp2!=NULL)
		{
			//使用z成员保存其到原点的距离
			tmp2->z=sqrt((tmp2->x* tmp2->x)+(tmp2->y*tmp2->y));
			tmp2=tmp2->next;
		}
		tmp2=tmp1->next;
		//int count=0;
		while(tmp2!=NULL && tmp2->next!=NULL)
		{//保证只有第一个点在坐标原点
			if(tmp2->next->z==0.0)
			{
				link_tmp->del(tmp2);
				//++count;
				continue;
			}
			tmp2=tmp2->next;
		}
		//printf("去重次数：%d\n",count);
		/*if(link_tmp->count()<3)
		{
			printf("对链表进行去重操作之后导致链表中剩余元素不足三个，无法进行后续运算\n");
			exit(-1);
		}*/
		tmp2=tmp1->next->next;
		while(tmp2!=NULL)
		{
			Node * minDis=tmp2;
			Node * tmp3=tmp2;
			while(tmp3!=NULL)
			{
				if(tmp3->z-minDis->z<-0.000001)
				{
					minDis=tmp3;
				}
				tmp3=tmp3->next;
			}
			if(minDis!=tmp2)
			{
				Node tmp;
				tmp.x=minDis->x;
				tmp.y=minDis->y;
				tmp.z=minDis->z;
				minDis->x=tmp2->x;
				minDis->y=tmp2->y;
				minDis->z=tmp2->z;
				tmp2->x=tmp.x;
				tmp2->y=tmp.y;
				tmp2->z=tmp.z;
			}
			tmp2=tmp2->next;
		}
	}//按照距离排序完成
	/*{//输出排序完的点的顺序
		Node * tmp=link_tmp->pointOfSpecificElement(1);
		printf("距离排序后的点（%d）：\n",link_tmp->count());
		while(tmp!=NULL)
		{
			printf("%.10f %.10f %.10f\n",tmp->x+trans.x,tmp->y+trans.y,tmp->z);
			tmp=tmp->next;
		}
	}*/
	{//从第二个点开始按与第一个点的幅角从小到大排序
		Node * tmp1=link_tmp->pointOfSpecificElement(1);
		Node * tmp2=tmp1->next;
		while(tmp2!=NULL)
		{
			//使用z成员保存其幅角
			tmp2->z=acos((tmp2->x/tmp2->z));
			tmp2=tmp2->next;
		}
		tmp2=tmp1->next;
		while(tmp2!=NULL)
		{
			Node * tmp3=tmp2->next;
			Node * tmp4=tmp1->next;
			while(tmp3!=NULL)
			{
				if(tmp4->next->z-tmp4->z<-0.000001)
				{
					Node tmp;
					tmp.x=tmp4->x;
					tmp.y=tmp4->y;
					tmp.z=tmp4->z;
					tmp4->x=tmp4->next->x;
					tmp4->y=tmp4->next->y;
					tmp4->z=tmp4->next->z;
					tmp4->next->x=tmp.x;
					tmp4->next->y=tmp.y;
					tmp4->next->z=tmp.z;
				}
				tmp4=tmp4->next;
				tmp3=tmp3->next;
			}
			tmp2=tmp2->next;
		}
	}//按照幅角排序完成
	/*{//输出排序完的点的顺序
		Node * tmp=link_tmp->pointOfSpecificElement(1);
		printf("幅角排序后的点（%d）：\n",link_tmp->count());
		while(tmp!=NULL)
		{
			printf("%.10f %.10f %.10f\n",tmp->x+trans.x,tmp->y+trans.y,tmp->z);
			tmp=tmp->next;
		}
	}*/
	{//对其进行求凸包运算
		Link * stk_tmp=new Link();
		Node * tmp=link_tmp->pointOfSpecificElement(1);
		stk_tmp->add(tmp->x,tmp->y,0.0);
		tmp=tmp->next;
		if(tmp!=NULL) stk_tmp->add(tmp->x,tmp->y,0.0);
		if(link_tmp->count()>=3)
		{
			Node * stkTop=stk_tmp->pointOfSpecificElement(1);//指向栈顶元素
			Node * stkNext=stkTop->next;//指向栈顶的下一个元素
			Node * current=tmp->next;//指向当前点
			//int count1=0,count2=0;
			while(1)
			{
				if(RightOrLeft(stkNext->x,stkNext->y,stkTop->x,stkTop->y,current->x,current->y)==1)
				{
					//++count1;
					stk_tmp->del(stk_tmp->pointOfSpecificElement(0));
					stkTop=stk_tmp->pointOfSpecificElement(1);
					stkNext=stkTop->next;
				}
				else{
					//++count2;
					stk_tmp->add(current->x,current->y,0.0);
					//cout<<"入栈"<<current->x+trans.x<<" "<<current->y+trans.y<<endl;
					stkTop=stk_tmp->pointOfSpecificElement(1);
					stkNext=stkTop->next;
					if(current->next==NULL) break;
					else{
						current=current->next;
					}
				}
			}//end of while
		}
		//printf("入栈次数：%d\n",count2);
		//printf("出栈次数：%d\n",count1);
		//现在栈 stk_tmp中保存有凸包上的点
		{//对凸包上的点平移到原位置
			Node * tmp=stk_tmp->pointOfSpecificElement(1);
			while(tmp!=NULL)
			{
				tmp->x+=trans.x;
				tmp->y+=trans.y;
				//tmp->z+=trans.z;
				tmp=tmp->next;
			}
		}//平移到原位置完成
		delete link_tmp;
		link->clear();
		link->copy(stk_tmp);
		delete stk_tmp;
	}//凸包运算完成
}// end of function convelHull
