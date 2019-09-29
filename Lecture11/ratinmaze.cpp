#include<iostream>
using namespace std;

bool ratInMaze(char maze[][5],int i,int j,int n,int m,int sol[][10])
{
	if(i==n-1 && j==m-1)
	{
		sol[i][j]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		// return true;	
		return false;
	}

	sol[i][j]=1;
	if(j+1<m && maze[i][j+1]!='X')
	{
		bool kyaRightMaiRakhPaye=ratInMaze(maze,i,j+1,n,m,sol);
		if(kyaRightMaiRakhPaye)
		{
			return true;
		}
	}

	if(i+1<n && maze[i+1][j]!='X')
	{
		bool kyaDownwardRakhPaye=ratInMaze(maze,i+1,j,n,m,sol);
		if(kyaDownwardRakhPaye)
		{
			return true;
		}

	}

	sol[i][j]=0;
	return false;
}


int main()
{
	char maze[4][5]={{"OOXX"},{"OOOO"},{"OOXX"},{"OOOO"}};
	int sol[10][10]={0};
	ratInMaze(maze,0,0,4,4,sol);
	return 0;
}