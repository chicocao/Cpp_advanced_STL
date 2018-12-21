#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<deque>

using namespace std;
//deque容器初始化
void test1()
{
	deque<int> v1;//默认构造函数
	deque<int> v2(10, 5);//带参数构造函数
	deque<int> v3(v2.begin(), v2.end());
	deque<int> v4(v2); //拷贝构造
}
//deque赋值操作
void test2()
{
	deque<int> v1(10, 3);
	deque<int> v2;
	v2.assign(10, 3);//赋值
	v2.assign(v1.begin(), v1.end());
	v2 = v1;//重载=赋值
}

//大小操作
void test3()
{
	deque<int> v1(10, 3);
	cout << v1.size() << endl;
	if (v1.empty)
	{
		cout << "kong" << endl;
	}
	else
	{
		cout << "bu kong" << endl;
	}
	v1.resize(5);
	v1.resize(15);
}
//deque插入和删除
void test4() {

	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);


	//第一种遍历方式
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;

	//第二种遍历方式
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	//第三种方式
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	//删除元素
	/*
		while (d.size() > 0){
		cout << d.back() << "被删除!" << endl;
		d.pop_back();
	}
	cout << "大小:" << d.size() << endl;
	*/


	//头删除
	while (!d.empty()) {
		cout << d.front() << "被删除!" << endl;
		d.pop_front();
	}


}

//deque容器插入
void test6() {

	deque<int> d;
	d.insert(d.begin(), 100); //头插法
	d.insert(d.end(), 200); //尾差法

	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main(void)
{
	test1();
}