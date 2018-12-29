#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
//find算法
void test1()
{
	vector<int> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << "zhaodaole:" << *pos << endl;
	}
	else
	{
		cout << "meizhaodao" << endl;
	}
}
class student {
public:
	student(int id,int age):id(id),age(age){}
	int id;
	int age;
	bool operator==(const student & s) {
		return s.age == this->age&&s.id == this->id;
	}
};
//查找对象

void test2()
{
	vector<student>v;
	student s1(1, 2), s2(3, 4), s3(5, 6);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	vector<student>::iterator pos = find(v.begin(), v.end(), s2);
	if (pos != v.end())
	{
		cout << "zhaodao:" << pos->id << " " << pos->age << endl;
	}
	else
	{
		cout << "meiyouzhaodao" << endl;
	}
}
//find_if
class mycompare3 {
public:
	bool operator ()(int v) {
		return v > 5;
	}
};
bool mycompare3_1(int v) {
	return v > 5;
}
void test3() {
	vector<int> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator pos = find_if(v.begin(), v.end(), mycompare3_1);
	if (pos == v.end()) {
		cout << "没有找到!" << endl;
	}
	else {
		cout << "找到了:" << *pos << endl;
	}
}
//adjacent_find 查找相邻元素，并返回第一个重复的元素出现的位置
void test4()
{
	vector<int> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end()) {
		cout << "mei找到!" << endl;
	}
	else {
		cout << "找到:" << *pos << endl;
	}
}
//binary_search 二分查找法
//如果是降序的，可以用 binary_search(v.begin(), v.end(), greater<int>());
void test5() {
	vector<int> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	sort(v.begin(), v.end());
	bool res = binary_search(v.begin(), v.end(), 5);
	if (res) {
		cout << "查找到！" << endl;
	}
	else {
		cout << "没有查找到！" << endl;
	}
}
//count count_if
class mycompare6 {
public:
	bool operator()(int v) {
		return v > 2;
	}
};
void test6() {

	vector<int> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);

	//count算法
	int n = count(v.begin(), v.end(), 2);
	cout << "n:" << n << endl;
	//count_if

	n = count_if(v.begin(), v.end(), mycompare6());
	cout << "n:" << n << endl;

}
int main(void)
{
	test6();
	return 0;
}