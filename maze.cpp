#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stack>
#include<fstream>
#include<iomanip>
#define N 23
typedef struct
{
	int x, y;
}Pos;//x,y座標
typedef struct
{
	int n;//迷宮大小
	Pos start, end;//起止座標
	int maze[N][N]; //迷宮分佈圖。-1-->牆；0-->通路
}Maze;
//從檔案讀取迷宮
void CreateMaze(Maze& m)
{
	fstream inFile("map.txt", ios::in);
	if (!inFile)cout << "檔案開啟失敗！" << endl;

	inFile >> m.n;
	inFile >> m.start.x >> m.start.y;
	inFile >> m.end.x >> m.end.y;

	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			inFile >> m.maze[i][j];
		}
	}
	inFile.close();
	cout << m.n << endl;
	cout << m.start.x << m.start.y << endl;
	cout << m.end.x << m.end.y << endl;

	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			cout << m.maze[i][j] << " ";
		}
		cout << endl;
	}
}
//-2->已走過；-3->不通
//判斷當前點是否存在通路，通，返回第一個可通的座標；不通，返回（-1，-1）
Pos Pass(Maze m, Pos curpos)
{
	Pos nextpos;
	//初始化表示無通路
	nextpos.x = 0;
	nextpos.y = 0;

	int x, y;
	x = curpos.x;
	y = curpos.y;
	//每次都按順序查詢，走過的路被標記為 1，所以不會再走
	//按照我們人的東西南北為參照，二維陣列x朝下，y朝右，所以應注意方向
	if (m.maze[x][y + 1] == 1)//東
	{
		nextpos.x = x;
		nextpos.y = y + 1;
	}
	else if (m.maze[x + 1][y] == 1)//南
	{
		nextpos.x = x + 1;
		nextpos.y = y;
	}
	else if (m.maze[x][y - 1] == 1)//西
	{
		nextpos.x = x;
		nextpos.y = y - 1;
	}
	else if (m.maze[x - 1][y] == 1)//北
	{
		nextpos.x = x - 1;
		nextpos.y = y;
	}
	return nextpos;
}
void MazePath(Maze m)
{
	Pos curpos, nextpos;//當前位置，下個位置
	stack<Pos> path_stack;//路徑棧

	curpos = m.start;//cout<<m.end.x<<m.end.y;
	do {//cout<<"curpos: "<<curpos.x<<" "<<curpos.y<<endl;
		nextpos = Pass(m, curpos); //cout<<"nextpos: "<<nextpos.x<<" "<<nextpos.y<<endl;

	//超級大bug，當終點為當前點且其四周都被沒空白時，當前的的下一個點自然返回空，表示不可通，也就找不到終點了
	//所以應該先判斷當前點是否為終點，是的話立刻退出，否則判斷是否存在通路，存在當前點就入棧；否則將當前置為-3，彈出棧頂作為當前點
		if (curpos.x == m.end.x && curpos.y == m.end.y)//當前點為終點
		{
			path_stack.push(curpos);//當前點入路徑棧
			m.maze[curpos.x][curpos.y] = 2;//走過標記為-2
			break;
		}
		if (nextpos.x != 0)//表示可通
		{

			path_stack.push(curpos);//當前點入路徑棧
			m.maze[curpos.x][curpos.y] = 2;//更新迷宮地圖，表示該點已經過
			curpos = nextpos;//當前點更新為下一個點
		}
		else
		{
			m.maze[curpos.x][curpos.y] = 3;//表示當前點不通
			curpos = path_stack.top();//當前點更新為棧頂元素
			path_stack.pop();//刪除棧頂
		}
	} while (!path_stack.empty());

	//以下僅僅是為了展示而處理效果
	if (path_stack.empty())cout << "死路一條！" << endl;
	else
	{
		stack<Pos>tmp_stack;
		int ord = 0;
		//被標記為1的不全是路徑上的點，但在棧中一定是路徑上的點
		while (!path_stack.empty())
		{
			curpos = path_stack.top();
			path_stack.pop();
			tmp_stack.push(curpos);
			//	m.maze[curpos.x][curpos.y] = 5;
		}

		while (!tmp_stack.empty())
		{
			ord++;
			curpos = tmp_stack.top();
			tmp_stack.pop();
			//	tmp_stack.push(curpos);
			m.maze[curpos.x][curpos.y] = ord;
		}

		cout << endl;
		for (int i = 0; i < m.n; i++)
		{
			for (int j = 0; j < m.n; j++)
			{
				if (m.maze[i][j] > 0)
				{
					cout << setw(2) << m.maze[i][j] << " ";
				}
				else cout << setw(2) << " # ";

			}
			cout << endl;
		}
	}
}
int main()
{
	Maze m;
	CreateMaze(m);
	for (int i = 0; i < 23; i++)//測試：以所有點為終點
	{
		for (int j = 0; j < 23; j++)
		{
			m.end.x = i;
			m.end.y = j;
			cout << "i: " << i << " j: " << j << endl;
			MazePath(m);
		}
	}
	//	MazePath(m);
	return 0;
}
