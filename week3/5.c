#include<stdio.h>

int DFS(int x,int y,int n,int matrix[n][n],int visited[n][n])
{
	printf("\nDFS x:%d ,y:%d ",x,y);
	visited[x][y]=1;
	int x_move[8]={-1,0,1,1,1,0,-1,-1};
	int y_move[8]={1,1,1,0,-1,-1,-1,0};
	int num=1;
	for(int dir=0;dir<8;dir++)
	{
		if((x+x_move[dir]>=0 && x+x_move[dir]<n)&&(y+y_move[dir]>=0 && y+y_move[dir]<n) && visited[x+x_move[dir]][y+y_move[dir]]==0 && matrix[x+x_move[dir]][y+y_move[dir]]==1)
		{
			num+=DFS(x+x_move[dir],y+y_move[dir],n,matrix,visited);
		}
	}
	return num;
}

int	main()
{
	int n;
	scanf("%d",&n);
	
	int matrix[n][n];
	int visited[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
			visited[i][j]=0;
		}
	}
	
	//start from top left and move clockwise
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int temp=0;
			if(visited[i][j]==0 && matrix[i][j]==1)
			{
				temp=DFS(i,j,n,matrix,visited);
				printf("\ntemp:%d",temp);
				if(temp>count)
					count=temp;				
			}
		}
	}
	printf("\n\n%d",count);
	return 0;
}
