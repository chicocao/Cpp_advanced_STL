#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Player
{
public:
	Player() {

	}
	Player(string name,int score):name(name),score(score){}
	string name;
	int score;
};
//创建选手
void Create_Player(vector<Player> &v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		
		string name =(string) "选手：" + nameseed[i];
		Player p(name, 0);
		v.push_back(p);
	}
}
//打分
bool myCompare(int a, int b)
{
	if (a > b)
	{ //从大到小
		return true;
	}
	else
	{
		return false;
	}
}
void Set_Player_Score(vector<Player> &v) {
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int socre = 50 + rand() % 50;
			d.push_back(socre);
		}
		sort(d.begin(), d.end(), myCompare);
		d.pop_back();
		d.pop_front();
		int totalSocre = 0;
		for (deque<int>::iterator itt = d.begin(); itt != d.end(); itt++)
		{
			totalSocre += (*itt);
		}
		int scoreAvg = totalSocre / d.size();
		it->score = scoreAvg;
		//(*it).score = scoreAvg;两者等价
	}
}
void Show_Player_Score(vector<Player> &vPlayer)
{
	for (vector<Player>::iterator it = vPlayer.begin(); it != vPlayer.end(); it++) {
		cout << "姓名:" << it->name << " 分数:" << it->score << endl;
	}
	cout << endl;
}
int main(void)
{
	vector<Player> vPlayer;//存放选手信息
	Create_Player(vPlayer); //创建选手
	Set_Player_Score(vPlayer);
	Show_Player_Score(vPlayer);
	//评委打分案例(sort 算法排序)
	//创建 5 个选手(姓名，得分)，10 个评委对 5 个选手进行打分
	//得分规则：去除最高分，去除最低分，取出平均分
	//按得分对 5 名选手进行排名
	return 0;
}