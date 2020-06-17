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
	~DLinkedList();//�ͷ����нڵ�
	void init();//��ʼ��
	int size();//��ӡ�����С
	bool empty();//�ж��Ƿ�Ϊ��
	Node<T>* find(int index);//����
	T getdata(int index);//�õ�ֵ
	Node<T>* first();//�����ĩ�ڵ�
	Node<T>* last();
	Node<T>* remove(int index);//ɾ��
	void insertAsFirst(T data_);//��data_��Ϊ�׽ڵ����
	void insertAsLast(T data_);//��data_��Ϊĩ�ڵ����
	void sort();//��data����
	void reverse();//ǰ����
	void merge(DLinkedList<T>& D2);//�ϲ�
	void show();//��ӡ
private:
	int count = 0;
	Node<T>* head;

};


template<class T>
void DLinkedList<T>::init()//�����ձ�ͷ
{
	head = new Node<T>();
	head->pred = head->succ = head;
}

template<class T>
DLinkedList<T>::DLinkedList()//���캯��
{
	init();
}
template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& d)//��������
{
	head = d.head;
	count = d.count;
}



template<class T>
DLinkedList<T>::~DLinkedList()//��������
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
int DLinkedList<T>::size()//�����С
{
	return count;
}


template<class T>
bool DLinkedList<T>::empty()//�ж��Ƿ�Ϊ��
{
	if (head == head->succ)
		return true;
	else
		return false;
}


template<class T>
Node<T>* DLinkedList<T>::find(int index)//����ĳһ�ڵ�
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
T  DLinkedList<T>::getdata(int index)//�õ�data
{
	return find(index)->data;
}
template<class T>
Node<T>* DLinkedList<T>::first()//�����׽ڵ�
{
	return find(1);
}


template<class T>
Node<T>* DLinkedList<T>::last()//����ĩ�ڵ�
{
	return find(count);
}


template<class T>
Node<T>* DLinkedList<T>::remove(int index)//ɾ��
{
	Node<T>* pindex = find(index);
	pindex->succ->pred = pindex->pred;
	pindex->pred->succ = pindex->succ;
	count--;
	return pindex;
}


template<class T>
void DLinkedList<T>::insertAsFirst(T Data_)//��data_��Ϊ�׽ڵ����
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
void DLinkedList<T>::insertAsLast(T Data_)//��data_��Ϊĩ�ڵ����
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
void myswap(T& x, T& y)//��������
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}


template<class T>
void DLinkedList<T>::sort()//����
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
	cout << "�����������";
	show();
}


template<class T>
void DLinkedList<T>::reverse()//ǰ����
{
	for (int i = 1; i < count / 2; i++)
	{
		myswap(find(i)->data, find(count + 1 - i)->data);
	}
	cout << "����ת��,";
	show();
}


template<class T>
void DLinkedList<T>::merge(DLinkedList<T>& D2)//�ϲ�����
{
	this->find(this->count)->succ = D2.find(1);
	D2.find(1)->pred = this->find(this->count);
	D2.head->succ = NULL;
	this->count = this->count + D2.count;
	Node<T>* pnode = this->find(1);
	cout << "�ϲ���" << endl;
	for (int i = 0; i < this->count; i++)
	{
		cout << pnode->data << " ";
		pnode = pnode->succ;
	}
	cout << endl;
}


template<class T>
void DLinkedList<T>::show()//��ӡ
{
	Node<T>* pindex = head->succ;
	cout << "��ӡ���ݣ�" << endl;
	for (int i = 1; i <= count; i++)
	{
		cout << pindex->data << " ";
		pindex = pindex->succ;
	}
	cout << endl;

}
