#pragma once
#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template<class T>
class Node
{
public:
	//���캯��
	Node() {};
	Node(T data_, Node* pred_, Node* succ_)
	{
		this->data = data_;
		this->pred = pred_;
		this->succ = succ_;
	};
	//��Ա
	T data;
	Node* pred;
	Node* succ;
};
