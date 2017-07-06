#include<iostream>
#include<vector>
#include<algorithm>

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
		for (int i = 0; i < c; i++)
		{
			int te;
			cin >> te;
			for (int j = 0; j < 6; j++)
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

struct line
{
	int beg, end;
	int mix = 0;
	line(){}
	line(int _beg, int _end) { beg = _beg; end = _end; }
	bool haveSame(line l)
	{
		if (beg<end && l.beg<l.end)
		{
			bool a = beg < l.end;
			bool b = end < l.beg;
			if (a || b)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if(beg>end && l.beg<l.end)
		{
			line a(beg, 23);
			line b(0, end);
			bool rt1 = a.haveSame(l);
			bool rt2 = b.haveSame(l);
			return rt1 || rt2;
		}
		else if (beg<end && l.beg>l.end)
		{
			line a(l.beg, 23);
			line b(0, l.end);
			bool rt1 = haveSame(a);
			bool rt2 = haveSame(b);
			return rt1 || rt2;
		}
		else
		{
			return true;
		}
	}
};
int main()
{
	int n;
	while (cin>>n)
	{
		if (!n) break;
		line *p = new line[n];
		int mixCount[24];
		memset(mixCount, 0, sizeof(mixCount));
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].beg >> p[i].end;

			if (p[i].beg < p[i].end)
			{
				for (int j = p[i].beg; j <= p[i].end; j++)
				{
					mixCount[j]++;
				}
			}
			else
			{
				for (int j = p[i].beg; j <= 23; j++)
				{
					mixCount[j]++;
				}
				for (int j = 0; j <= p[i].end; j++)
				{
					mixCount[j]++;
				}
			}	

		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == i)continue;
				if (p[i].haveSame(p[j]))
				{
					p[i].mix++;
				}
			}
		}
		//sort(p, &p[n - 1] + 1,p->mix < (&p[n - 1] + 1)->mix);
		//reverse(p, &p[n - 1] + 1);
		int mx = mixCount[0];
		for (int i = 1; i < 24; i++)
		{
			if (mx < mixCount[i])mx = mixCount[i];
		}
		/*int num = n - mx;
		cout << num << endl;
*/
		int num = n;
		while(1)//for(int i = 0;i<n;i++)
		{

			bool ok = true;
			for (int i = 0; i < 24; i++)
			{
				if (mixCount[i]>1)
				{
					ok = false;
					break;
				}
			}
			if (ok)break;

			int mixMaxIndex = 0;
			for (int i = 1; i < n; i++)
			{
				if (p[mixMaxIndex].mix < p[i].mix)
				{
					mixMaxIndex = i;
				}
			}
			p[mixMaxIndex].mix = 0;
			if (p[mixMaxIndex].beg<p[mixMaxIndex].end)
			{
				for (int i = p[mixMaxIndex].beg; i <= p[mixMaxIndex].end; i++)
				{
					mixCount[i]--;
				}
			}
			else
			{
				for (int i = p[mixMaxIndex].beg; i <=23; i++)
				{
					mixCount[i]--;
				}
				for (int i = 0; i <= p[mixMaxIndex].end; i++)
				{
					mixCount[i]--;
				}
			}
			num--;
		}

		cout << num<<endl;
	}
	
	return 0;
}