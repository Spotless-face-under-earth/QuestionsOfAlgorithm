#include<iostream>
#include<deque>
int N;//所有待排序的人数
class man
{
public:
	int* manPre=new int[N];
	int foreGirl;
};
class woman
{
public:
	int* womanPre=new int[N];
	int* manOrder=new int[N];
	int perBoy;
	bool isSingle;
};
using namespace std;
int main()
{
	printf("%s\n","请输入配对人数:");
	scanf_s("%d",&N);
	man* manFile=new man[N];
	woman* woFile=new woman[N];
	printf("请输入男生喜好：");
	for (int manNum = 0;manNum < N;manNum++)//男生喜好表的初始化
	{
		for (int manLove = 0;manLove < N;manLove++)
		{
			scanf_s("%d", &manFile[manNum].manPre[manLove]);
		}
	}
	printf("请输入女生喜好：");
	for (int woNum = 0;woNum < N;woNum++)//女生喜好表的初始化
	{
		for (int woLove = 0;woLove < N;woLove++)
		{
			scanf_s("%d",&woFile[woNum].womanPre[woLove]);
			int temp = woFile[woNum].womanPre[woLove];//转化女性的喜爱表
			woFile[woNum].manOrder[temp] = woLove;
		}
		woFile[woNum].isSingle = true;
	}
	deque<int>manque;
	for (int i = 0;i < N;i++) 
	{
		manque.push_back(i);
	}
	while (!manque.empty())
	{
		int tempMan = manque.front();
		for (int tempNum = 0;tempNum < N;tempNum++)
		{
			int tempWo = manFile[tempMan].manPre[tempNum];
			if (woFile[tempWo].isSingle)
			{
				manFile[tempMan].foreGirl = tempWo;
				if (!woFile[tempWo].isSingle)
				{
					manque.push_back(woFile[tempWo].perBoy);
				}
				woFile[tempWo].perBoy = tempMan;
				woFile[tempWo].isSingle = false;
				break;
			}
			else if(woFile[tempWo].manOrder[tempMan] < woFile[tempWo].manOrder[woFile[tempWo].perBoy])
			{
				manFile[tempMan].foreGirl = tempWo;
				if (!woFile[tempWo].isSingle)
				{
					manque.push_back(woFile[tempWo].perBoy);
					woFile[tempWo].perBoy = tempMan;
				}
				break;
			}
			else{}
		}
		manque.pop_front();
	}
	printf("%d\n", N);
	for (int i = 0;i < N;i++)
	{
		printf("%d", i);printf(" ");printf("%d\n", manFile[i].foreGirl);
	}
}