#include<iostream>
//#include<string>
//#include<vector>
//#include<iterator>

using namespace std;
////////////////////////
struct point
{
	int x, y, z;
	point() {}
	point(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
	point operator+(point v) { return point(x + v.x, y + v.y, z + v.z); }
	bool operator==(point v) { return x == v.x && y == v.y && z == v.z; }
};
//////////////////////
int map[60][60][60] = { 0 };
char mapc[60][60][60] = { 0 };
//bool mapAdded[20][20] = { 0 };
int A, B, C;
//vector<point> draw;
//vector<point> drawFront;
class set
{
public:
	int q = 0;
	point *pts = new point[216000];

	point operator[](int i)
	{
		return pts[i];
	}
	void push_back(point v)
	{
		pts[q++] = v;
	}
	int size()
	{
		return q;
	}
	bool empty()
	{
		if (q)return false;
		else return true;
	}
};
set draw, drawFront;
bool inSize(point v)
{
	return v.x >= 0 && v.x < A && v.y >= 0 && v.y < B && v.z >= 0 && v.z < C;
}
void AddDraw()
{
	point sur[6] = { point(1,0,0),point(-1,0,0),point(0,1,0),point(0,-1,0),point(0,0,1),point(0,0,-1) };
	for (int k = 0; k < A*B*C; k++)
	{
		for (int l = 0; l < drawFront.size(); l++)
			for (int i = 0; i < 6; i++)
			{
				point d = drawFront[l] + sur[i];
				//A = X, B = Y, C = Z
				if (inSize(d) && map[d.x][d.y][d.z] == 0 && mapc[d.x][d.y][d.z] == 0)
				{
					map[d.x][d.y][d.z] = map[drawFront[l].x][drawFront[l].y][drawFront[l].z] + 1;
					draw.push_back(d);
				}
			}
		if (draw.empty())break;

		//memcpy(&drawFront, &draw, sizeof(draw));
		drawFront.pts = draw.pts;
		drawFront.q = draw.q;
		draw.q = 0;
	}
}
int main()
{
	//AddDraw();
	int length;
	int time;
	int T;
	scanf("%d", &length);

	while (length--)
	{
		memset(map, 0, sizeof(int)*A*B*C);
		map[0][0][0] = 1;
		drawFront.q = 0;
		draw.q = 0;
		drawFront.push_back(point(0, 0, 0));
		scanf("%d%d%d%d", &A, &B, &C, &T);
		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++)
				for (int c = 0; c < C; c++)
					scanf("%d", &mapc[a][b][c]);
		if (mapc[A - 1][B - 1][C - 1] || mapc[0][0][0])
		{
			printf("-1\n");
			continue;
		}
		else
		{
			AddDraw();
			time = map[A - 1][B - 1][C - 1] - 1;
			if (time <= T && time >= 0)
				printf("%d\n", time);
			else printf("-1\n");
		}
	}
	return 0;
}