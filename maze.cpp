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
}Pos;//x,y�y��
typedef struct
{
	int n;//�g�c�j�p
	Pos start, end;//�_��y��
	int maze[N][N]; //�g�c���G�ϡC-1-->��F0-->�q��
}Maze;
//�q�ɮ�Ū���g�c
void CreateMaze(Maze& m)
{
	fstream inFile("map.txt", ios::in);
	if (!inFile)cout << "�ɮ׶}�ҥ��ѡI" << endl;

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
//-2->�w���L�F-3->���q
//�P�_��e�I�O�_�s�b�q���A�q�A��^�Ĥ@�ӥi�q���y�СF���q�A��^�]-1�A-1�^
Pos Pass(Maze m, Pos curpos)
{
	Pos nextpos;
	//��l�ƪ�ܵL�q��
	nextpos.x = 0;
	nextpos.y = 0;

	int x, y;
	x = curpos.x;
	y = curpos.y;
	//�C���������Ǭd�ߡA���L�����Q�аO�� 1�A�ҥH���|�A��
	//���ӧڭ̤H���F��n�_���ѷӡA�G���}�Cx�¤U�Ay�¥k�A�ҥH���`�N��V
	if (m.maze[x][y + 1] == 1)//�F
	{
		nextpos.x = x;
		nextpos.y = y + 1;
	}
	else if (m.maze[x + 1][y] == 1)//�n
	{
		nextpos.x = x + 1;
		nextpos.y = y;
	}
	else if (m.maze[x][y - 1] == 1)//��
	{
		nextpos.x = x;
		nextpos.y = y - 1;
	}
	else if (m.maze[x - 1][y] == 1)//�_
	{
		nextpos.x = x - 1;
		nextpos.y = y;
	}
	return nextpos;
}
void MazePath(Maze m)
{
	Pos curpos, nextpos;//��e��m�A�U�Ӧ�m
	stack<Pos> path_stack;//���|��

	curpos = m.start;//cout<<m.end.x<<m.end.y;
	do {//cout<<"curpos: "<<curpos.x<<" "<<curpos.y<<endl;
		nextpos = Pass(m, curpos); //cout<<"nextpos: "<<nextpos.x<<" "<<nextpos.y<<endl;

	//�W�Ťjbug�A����I����e�I�B��|�P���Q�S�ťծɡA��e�����U�@���I�۵M��^�šA��ܤ��i�q�A�]�N�䤣����I�F
	//�ҥH���ӥ��P�_��e�I�O�_�����I�A�O���ܥߨ�h�X�A�_�h�P�_�O�_�s�b�q���A�s�b��e�I�N�J�̡F�_�h�N��e�m��-3�A�u�X�̳��@����e�I
		if (curpos.x == m.end.x && curpos.y == m.end.y)//��e�I�����I
		{
			path_stack.push(curpos);//��e�I�J���|��
			m.maze[curpos.x][curpos.y] = 2;//���L�аO��-2
			break;
		}
		if (nextpos.x != 0)//��ܥi�q
		{

			path_stack.push(curpos);//��e�I�J���|��
			m.maze[curpos.x][curpos.y] = 2;//��s�g�c�a�ϡA��ܸ��I�w�g�L
			curpos = nextpos;//��e�I��s���U�@���I
		}
		else
		{
			m.maze[curpos.x][curpos.y] = 3;//��ܷ�e�I���q
			curpos = path_stack.top();//��e�I��s���̳�����
			path_stack.pop();//�R���̳�
		}
	} while (!path_stack.empty());

	//�H�U�ȶȬO���F�i�ܦӳB�z�ĪG
	if (path_stack.empty())cout << "�����@���I" << endl;
	else
	{
		stack<Pos>tmp_stack;
		int ord = 0;
		//�Q�аO��1�������O���|�W���I�A���b�̤��@�w�O���|�W���I
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
	for (int i = 0; i < 23; i++)//���աG�H�Ҧ��I�����I
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
