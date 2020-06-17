#pragma once
#include"Node.h"
#include<vector>
#include<iomanip>
template<class T>
class DLinkedList
{
public:
	DLinkedList();
	DLinkedList(const DLinkedList& d);
	~DLinkedList();//释放所有节点
	void init();//初始化
	int size();//打印链表大小
	bool empty();//判断是否为空
	Node<T>* find(int index);//查找
	T getdata(int index);//得到值
	Node<T>* first();//获得首末节点
	Node<T>* last();
	Node<T>* remove(int index);//删除
	void insertAsFirst(T data_);//将data_作为首节点插入
	void insertAsLast(T data_);//将data_作为末节点插入
	void sort();//按data排序
	void reverse();//前后倒置
	void merge(DLinkedList<T>& D2);//合并
	void show();//打印
private:
	int count = 0;
	Node<T>* head;

};


template<class T>
void DLinkedList<T>::init()//建立空表头
{
	head = new Node<T>();
	head->pred = head->succ = head;
}

template<class T>
DLinkedList<T>::DLinkedList()//构造函数
{
	init();
}
template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& d)//拷贝函数
{
	head = d.head;
	count = d.count;
}



template<class T>
DLinkedList<T>::~DLinkedList()//析构函数
{
	Node<T>* tmp;
	Node<T>* p = this->head->succ;
	while (p != NULL)
	{
		while (p != head && p != NULL)
		{
			tmp = p;
			p = p->succ;
			delete tmp;
		}
	}
	delete head;
	head = NULL;
}


template<class T>
int DLinkedList<T>::size()//链表大小
{
	return count;
}


template<class T>
bool DLinkedList<T>::empty()//判断是否为空
{
	if (head == head->succ)
		return true;
	else
		return false;
}


template<class T>
Node<T>* DLinkedList<T>::find(int index)//返回某一节点
{
	if (index < 0 || index >count)
	{
		cout << "the node isn't in the DoubleLinkedList" << endl;
		return NULL;
	}
	else if (index <= count)
	{
		int i = 0;
		Node<T>* pindex = head;
		while (i < index)
		{
			pindex = pindex->succ;
			i++;
		}
		return pindex;
	}
}


template<class T>
T  DLinkedList<T>::getdata(int index)//得到data
{
	return find(index)->data;
}
template<class T>
Node<T>* DLinkedList<T>::first()//返回首节点
{
	return find(1);
}


template<class T>
Node<T>* DLinkedList<T>::last()//返回末节点
{
	return find(count);
}


template<class T>
Node<T>* DLinkedList<T>::remove(int index)//删除
{
	Node<T>* pindex = find(index);
	pindex->succ->pred = pindex->pred;
	pindex->pred->succ = pindex->succ;
	count--;
	return pindex;
}


template<class T>
void DLinkedList<T>::insertAsFirst(T Data_)//将data_作为首节点插入
{
	if (!empty())
	{
		Node<T>* pnode = new Node<T>(Data_, head, head->succ);
		head->succ = pnode;
		pnode->succ->pred = pnode;
		count++;
	}
	else
	{
		Node<T>* pnode = new Node<T>(Data_, head, NULL);
		head->succ = pnode;
		count++;
	}
}


template<class T>
void DLinkedList<T>::insertAsLast(T Data_)//将data_作为末节点插入
{
	if (empty())
	{
		insertAsFirst(Data_);
	}
	else
	{
		Node<T>* pnode = new Node<T>(Data_, last(), NULL);
		last()->succ = pnode;
		count++;
	}
}


template<class T>
void myswap(T& x, T& y)//交换函数
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}


template<class T>
void DLinkedList<T>::sort()//排序
{
	for (int i = 1; i < count; i++)
	{
		int min = i;
		for (int j = i + 1; j <= count; j++)
		{
			if (find(j)->data < find(min)->data)
			{
				min = j;
			}
		}
		myswap(find(i)->data, find(min)->data);
	}
	cout << "对数据排序后，";
	show();
}


template<class T>
void DLinkedList<T>::reverse()//前后倒置
{
	for (int i = 1; i < count / 2; i++)
	{
		myswap(find(i)->data, find(count + 1 - i)->data);
	}
	cout << "链表反转后,";
	show();
}


template<class T>
void DLinkedList<T>::merge(DLinkedList<T>& D2)//合并函数
{
	this->find(this->count)->succ = D2.find(1);
	D2.find(1)->pred = this->find(this->count);
	D2.head->succ = NULL;
	this->count = this->count + D2.count;
	Node<T>* pnode = this->find(1);
	cout << "合并后：" << endl;
	for (int i = 0; i < this->count; i++)
	{
		cout << pnode->data << " ";
		pnode = pnode->succ;
	}
	cout << endl;
}


template<class T>
void DLinkedList<T>::show()//打印
{
	Node<T>* pindex = head->succ;
	cout << "打印数据：" << endl;
	for (int i = 1; i <= count; i++)
	{
		cout << pindex->data << " ";
		pindex = pindex->succ;
	}
	cout << endl;

}
