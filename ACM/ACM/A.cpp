#include<iostream>
using namespace std;

void acm0()
{
	int c;
	int rmb[6] = { 100,50,10,5,2,1 };
	while (cin >> c)
	{
		if (!c) break;
		//int *m = new int[c];
		int rmbc = 0;
		for (size_t i = 0; i < c; i++)
		{
			int te;
			cin >> te;
			for (size_t j = 0; j < 6; j++)
			{
				rmbc += te / rmb[j];
				te %= rmb[j];
			}
		}
		cout << rmbc << endl;
	}
}

int statCount;
int GetNum(int nowCount=1)
{
	if (nowCount == statCount)return 1;
	if (nowCount > statCount)return 0;
	return GetNum(nowCount + 1) + GetNum(nowCount + 2);
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> statCount;
		int num = 3;
		for (size_t i = 0; i < statCount; i++)
		{
			num = (num - 1) * 2;
		}
		cout << num<<endl;
	}
	return 0;
}