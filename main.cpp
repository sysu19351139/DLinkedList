#include"DLinkedList.h"
#include<fstream>

int main()
{
	DLinkedList<int>D1;
	ifstream myfile;
	myfile.open("IntegerData.txt");//传入“IntegerData.txt”
	if (myfile.fail())
	{
		cerr << "传入文件失败" << endl;
		return -1;
	}
	string str, all;
	while (getline(myfile, str))
	{
		all += str;
	}
	string _data, num;
	string::size_type start = all.find_first_of(":", 37);
	while (start != string::npos)//识别节点
	{
		num.assign(all, start - 2, 2);
		if (num == "10")
		{
			_data.assign(all, start + 1, 2);
			int data_ = stoi(_data);
			D1.insertAsLast(data_);
		}
		else
		{
			if ("0" <= num.assign(all, start + 2, 1) && num.assign(all, start + 2, 1) <= "9")
			{
				_data.assign(all, start + 1, 2);
				int data_ = stoi(_data);
				D1.insertAsLast(data_);
			}
			else
			{
				_data.assign(all, start + 1, 1);
				int data_ = stoi(_data);
				D1.insertAsLast(data_);
			}
		}
		start = all.find_first_of(":", start + 1);
	}
	cout << "IntegerData.txt";
	D1.show();
	cout << endl;
	D1.reverse();
	cout << "\n再次";
	D1.reverse();
	DLinkedList<int>D2;
	ifstream myfile2;//读取Merge.txt
	myfile2.open("Merge.txt");
	if (myfile2.fail())
	{
		cout << "传入文件失败" << endl;
	}
	string str2, all2;
	while (getline(myfile2, str2))
	{
		all2 += str2;
	}
	string::size_type start_ = all2.find_first_of(":", 37);
	while (start_ != string::npos)//识别节点
	{
		_data.assign(all2, start_ + 1, 1);
		int data_ = stoi(_data);
		D2.insertAsLast(data_);
		start_ = all2.find_first_of(":", start_ + 1);
	}
	cout << endl;
	cout << "MergeData.txt";
	D2.show();//打印函数
	cout << endl;
	D1.merge(D2);//合并函数
	cout << endl;
	D1.sort();//排序函数
	cout << "\n删除第一个节点后,";//删除函数
	D1.remove(1);
	D1.show();
	cout << "\n向前插入5";//试用向前插入函数
	D1.insertAsFirst(5);
	D1.show();
	cout << "\n第一个节点数据是：" << D1.getdata(1);
}
