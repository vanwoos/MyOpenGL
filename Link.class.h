#include <stdio.h>
#include <stdlib.h>

typedef struct nodetmp{//一维链表使用的
	double x, y, z;
        struct nodetmp * next;
}Node;

class Link{//有头节点的链表类
private:

public:
	Node * data=NULL;
private:
	void init()//初始化链表
	{
		this->data=NULL;
		this->data=new Node;
		this->data->x=this->data->y=this->data->z=0.0;
		this->data->next=NULL;
	}
	
	void destroy()//清除链表占用的空间，包括头节点，所以之后链表不能再继续使用
	{
		this->clear();
		delete this->data;
		this->data=NULL;
	}
	
	void check()//检验链表是否有效
	{
		if(this->data==NULL)
		{
			cout<<"链表未正确初始化或已经被销毁"<<endl;
			exit(0);
		}
	}
	
public:

	void add(double x,double y,double z)//增加一个节点
	{
		this->check();
		Node * tmp=new Node;
		tmp->x=x;tmp->y=y;tmp->z=z;
		tmp->next=this->data->next;
		this->data->next=tmp;
	}
	
	void del(Node * prev)//删除一个节点
	{
		this->check();
		Node * tmp=prev->next;
		prev->next=prev->next->next;
		delete tmp;
	}
	
	void insert(Node * prev,double x,double y,double z)//在某个元素的后面插入一个节点
	{
		this->check();
		Node * tmp=new Node;
		tmp->x=x;tmp->y=y;tmp->z=z;
		tmp->next=prev->next;
		prev->next=tmp;
	}
	
	int count()//统计链表中节点的数目
	{
		this->check();
		int i=0;
		Node * tmp=this->data->next;;
		while(tmp!=NULL)
		{
			tmp=tmp->next;
			++i;
		}
		return i;
	}
	
	Node * pointOfSpecificElement(int n)//获取指向特定第几个元素的指针
	{
		Node * tmp=this->data;
		while(tmp!=NULL)
		{
			if(n<=0) break;
			--n;
			tmp=tmp->next;
		}
		return tmp;
	}
	
	void clear()//清空链表中的所有元素，不包括头节点
	{
		this->check();
		while(!this->empty())
		{
			this->del(this->data);
		}
	}
	
	void copy(Link * link,int n=1)//将参数链表中从第n个开始的元素拷贝增加到this链表，头节点作为第0个
	{
		Node * tmp=link->pointOfSpecificElement(n);
		while(tmp!=NULL)
		{
			this->add(tmp->x,tmp->y,tmp->z);
			tmp=tmp->next;
		}
	}
	
	
	bool empty()//链表是否为空
	{
		this->check();
		return (this->data->next==NULL);
	}
	
	Link()
	{
		this->init();
	}
	virtual ~Link()
	{
		this->destroy();
	}
};
