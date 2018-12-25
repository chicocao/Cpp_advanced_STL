#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<set>

using namespace std;

//打印set
void print(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << endl;
	}
}
//初始化set
void test1()
{
	set<int> myset;
	set<int> myset2(myset);
	
}
//插入和删除
void test2()
{ 
	set<int> myset;
	myset.insert(4);
	myset.insert(3);
	myset.insert(1);
	myset.insert(2);
	print(myset);
	cout << "------------" << endl;
	myset.erase(myset.begin());
	myset.erase(2);
	print(myset);
	cout << "------------" << endl;
	myset.erase(myset.begin(), myset.end());
	print(myset);
}
template<class T>
class mycompare
{
public:

	bool operator()(T a, T b)const
	{
		return a > b;//从大到小就是大于
	}
};


//查找
void test3()
{
	set<int, mycompare<int>>myset;
	myset.insert(1);
	myset.insert(3);
	myset.insert(2);
	myset.insert(4);
	//print(myset);类型不对，参考定义时的声明
	for (set<int, mycompare<int>>::iterator it = myset.begin(); it != myset.end(); it++)
	{
		cout << *it << endl;
	}
	set<int, mycompare<int>>::iterator pos = myset.find(2);
	if (pos == myset.end()) {
		cout << "没找到" << endl;
	}
	else
	{
		cout << "已找到" << *pos << endl;
	}
}

class Teacher {
public:
	Teacher(int id, int age) :id(id), age(age) {}
	int id;
	int age;
};

class mycompare04 {//查找时是根据operator中的比对数据查找的
					//此时查找依据是id，与对象其他属性无关
public:
	bool operator()(Teacher t1, Teacher t2)const {
		return t1.id > t2.id;
	}
};
void test4() {

	set<Teacher, mycompare04> myset;
	Teacher t1(1, 2), t2(3, 4), t3(5, 6);

	myset.insert(t1);
	myset.insert(t2);
	myset.insert(t3);
	for (set<Teacher, mycompare04>::iterator it = myset.begin(); it != myset.end(); it++) {
		cout << it->id << " " << it->age << endl;
	}
	cout << endl;
	set<Teacher, mycompare04>::iterator pos = myset.find(Teacher(3, 4));
	if (pos == myset.end()) {
		cout << "没有查找到!" << endl;
	}
	else {
		cout << "查找到:" << pos->id << ":" << pos->age << endl;
	}
}
void test5() {

	set<int> myset;
	myset.insert(10);
	myset.insert(5);
	myset.insert(1);
	myset.insert(8);

	set<int>::iterator pos = myset.lower_bound(5);  //返回大于等于5 迭代器
	if (pos == myset.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "找到：" << *pos << endl;
	}

	pos = myset.upper_bound(5);
	if (pos == myset.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "找到：" << *pos << endl;
	}

	pair<set<int>::iterator, set<int>::iterator> pos2 = myset.equal_range(5);
	
	//first是lower_bound
	//second是upper_bound
	if (pos2.first == myset.end()) {
		cout << "meiyouzhaodao!" << endl;
	}
	else {
		cout << "zhaodao!" << *(pos2.first) << endl;
	}

	if (pos2.second == myset.end()) {
		cout << "meiyouzhaodao!" << endl;
	}
	else {
		cout << "zhaodao!" << *(pos2.second) << endl;
	}

}
int main(void)
{
	test5();
}