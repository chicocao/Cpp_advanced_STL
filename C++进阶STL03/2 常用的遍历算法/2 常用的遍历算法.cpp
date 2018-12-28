#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;

//for_each算法
class print {
public:
	print():count(0){}
	void operator()(int v)
	{
		count++;
		cout << "v:" << v << endl;
	}
	int count;
};
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	print p1;
	//p1只是复制了一份，所以不会改变p1中的count
	//p2是返回来的函数对象，把count为10的对象给了p2，
	//所以，p2.count为10
	print p2 = for_each(v.begin(), v.end(), p1);
	cout << endl;
	cout <<"p1.count:"<< p1.count << endl;
	cout << "p2.count:" << p2.count << endl;
}
//transform算法
class myplus100 {
public:
	int operator()(int v) {
		return v + 100;
	}
};

class myminute {
public:
	int operator()(int v1, int v2) {
		return v2 - v1;
	}
};
void test2() {

	//第一种情况  一个容器中得元素经过运算 把结果放进目标容器中(v2)
	/*

	vector<int> v1,v2;
	for (int i = 0; i < 10; i++){
	v1.push_back(i);
	}


	v2.resize(v1.size());

	for_each(v2.begin(), v2.end(), print());
	cout << endl;
	transform(v1.begin(), v1.end(), v2.begin(), myplus100());

	for_each(v2.begin(), v2.end(), print());
	cout << endl;
	*/


	//第二种方式
	vector<int> v1, v2, v3;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	cout << "v1size():" << v1.size() << endl;
	v3.resize(v1.size());
	for_each(v3.begin(), v3.end(), print());
	cout << endl;
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), myminute());
	for_each(v3.begin(), v3.end(), print());
	cout << endl;

}


int main(void)
{
	test2();
	return 0;
}