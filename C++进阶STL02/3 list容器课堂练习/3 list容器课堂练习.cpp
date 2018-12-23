#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>

using namespace std;


void print(list<int>&l)
{
	for (list<int>::iterator it=l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}
}
//list容器初始化
void test1()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	list<int>l2(l);
	list<int>l3(10, 5);
	list<int>l4(l.begin(), l.end());
	print(l4);
}
//list容器插入删除
void test2()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_front(3);
	l.push_front(4);
	print(l);
	cout << "--------------" << endl;
	l.insert(l.begin()++, 5);
	cout << "--------------" << endl;
	l.insert(l.begin()++, 6,6);
	print(l);
	cout << "--------------" << endl;
	l.remove(6);
	print(l);
	cout << "--------------" << endl;
	l.erase(l.begin(), l.end());
	print(l);
}
//list大小和赋值操作
void test3()
{
	list<int> mylist;
	cout<<"mylist:size"<<mylist.size()<<endl;
	cout<<"mylist:size"<<mylist.size()<<endl;
	for (int i = 0; i < 5; i++)
	{
		mylist.push_back(i + 10);
	}
	cout << "mylist" << endl;
	print(mylist);
	cout << "mylist:size" << mylist.size() << endl;
	list<int>mylist2;
	mylist2.assign(++(mylist.begin()), --(mylist.end()));
	cout << "mylist2" << endl;
	print(mylist2);
	cout << "mylist2.assign(6, 6);" << endl;
		mylist2.assign(6, 6);
		print(mylist2);

		list<int> mylist3 = mylist2;
		cout << mylist3.front() << endl;
		cout << mylist3.back() << endl;
		//reverse 反转容器的元素
		mylist3.reverse();
		print(mylist3);
}
bool mycompare(int v1, int v2) {
	return v1 > v2;
}
//list容器排序
void test4() {

	list<int> mylist;
	mylist.push_back(2);
	mylist.push_back(8);
	mylist.push_back(5);
	mylist.push_back(9);

	print(mylist);
	mylist.sort(); //默认从小到大
	print(mylist);
	mylist.sort(mycompare);
	print(mylist);

}
int main(void)
{
	test3();
	return 0;
}