#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
#include<string>
using namespace std;

//map容器初始化
void test()
{
	map<int, string> mymap;//默认构造
	map<int, string> mymap2（mymap）;//拷贝构造
}

//map插入操作
void test2()
{
	map<int, int>mymap;

	//第一种，用pair
	pair<int, int>par(1, 5);
	mymap.insert(par);//或者mymap.insert(pair<int,int>par(1,2);
	//第二种
	mymap.insert(make_pair(2, 10));
	
	pair<map<int, int>::iterator, bool> ret = mymap.insert(make_pair(2, 10));
	if (ret.second) {
		cout << "插入成功!" << endl;
	}
	else {
		cout << "插入失败!" << endl;
	}
	
	//第三种
	mymap.insert(map<int, int>::value_type(1, 2));
	//第四种
	mymap[4] = 20;

	//四种插入方式区别：
	//如果Key存在，会修改容器指定key元素的值
	mymap[2] = 100;
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << "key:" << (*it).first << " value:" << (*it).second << endl;
	}
	cout << endl;
	//如果你访问的Key不存在，他会帮你这个数据给你插入进去
	cout << "key:" << mymap[20] << endl;
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	cout << endl;
	ret = mymap.insert(map<int, int>::value_type(2, 10));
	if (ret.second) {
		cout << "插入成功!" << endl;
	}
	else {
		cout << "插入失败!" << endl;
	}
}

//删除和查找
void test3()
{
	map<int, int> mymap;
	mymap.insert(make_pair(1, 2));
	mymap.insert(make_pair(2, 3));
	mymap.insert(make_pair(3, 4));
	/*
	mymap.erase(2);  //根据Key删除元素
	print(mymap);
	mymap.erase(mymap.begin()); //删除第一个元素
	print(mymap);
	mymap.erase(mymap.begin(),mymap.end()); // mymap.clear
	cout << "map size:" << mymap.size() << endl;
	*/


	//查找
	map<int, int>::iterator pos = mymap.find(3);
	if (pos == mymap.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "查找到:" << pos->first << " value:" << pos->second << endl;
	}

	cout << "---------------" << endl;
	pos = mymap.lower_bound(2);
	if (pos == mymap.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "查找到:" << pos->first << " value:" << pos->second << endl;
	}

	pos = mymap.upper_bound(2);
	if (pos == mymap.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "查找到:" << pos->first << " value:" << pos->second << endl;
	}

	pair<map<int, int>::iterator, map<int, int>::iterator> pos2 = mymap.equal_range(2);
	if (pos2.first == mymap.end()) {  //第一个迭代器
		cout << "没有找到!" << endl;
	}
	else {
		cout << "查找到:" << pos2.first->first << " value:" << pos2.first->second << endl;
	}

	if (pos2.second == mymap.end()) { //第二个迭代器
		cout << "没有找到!" << endl;
	}
	else {
		cout << "查找到:" << pos2.second->first << " value:" << pos2.second->second << endl;
	}
}
int main(void)
{
	test3();
}