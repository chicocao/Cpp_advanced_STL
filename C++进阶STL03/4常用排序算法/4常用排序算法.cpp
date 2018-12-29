#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
//merge算法
//也可以指定从大到小还是从小到大
void print(int v) {
	cout << "v:" << v << endl;
}
void test1() {
	vector<int> v1, v2, v3;
	v1.push_back(6);
	v1.push_back(2);
	v1.push_back(8);
	v1.push_back(4);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(6);
	v2.push_back(4);
	sort(v1.begin(), v1.end(), greater<int>());
	//从大到小排序
	sort(v2.begin(), v2.end(), greater<int>());
	v3.resize(v1.size()+ v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(),greater<int>());
	for_each(v3.begin(), v3.end(), print);
}
//sort算法
void test3() {
	vector<int> v;
	v.push_back(6);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);

	sort(v.begin(), v.end(), greater<int>());//从大到小排序  默认从小到大
}
//random_shuffle  洗牌  将容器中得元素 顺序打乱
void test4() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "xipaiqian" << endl;
	for_each(v.begin(), v.end(), print);
	random_shuffle(v.begin(), v.end());
	cout << "xipaihou" << endl;
	for_each(v.begin(), v.end(), print);
}
//reverse 反转容器中得元素
void test5() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "fanzhuanqian" << endl;
	for_each(v.begin(), v.end(), print);
	reverse(v.begin(), v.end());
	cout << "fanzhuanhou" << endl;
	for_each(v.begin(), v.end(), print);

}
void main(void)
{
	test5();
}