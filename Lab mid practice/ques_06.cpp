#include<iostream>
using namespace std;

bool isSafe(int maze[][4], int x, int y)
{
    if(x<0 || y<0 || x>=4 || y>=4 || (maze[x][y]==1 && maze[x+1][y+1]==1) || (maze[x][y] == 1 && maze[x-1][y+1]==1))
    {
        return false;
    }
    return true;
}

bool flagDeploy(int maze[][4], int x, int y)
{
    if(x==4 || y==4)
    {
        return true;
    }
    
    if(isSafe(maze, x, y))
    {
        maze[x][y] = 1;
        
        if(flagDeploy(maze, x+1, y))
        {
            return true;
        }
        if(flagDeploy(maze, x, y+1))
        {
            return true;
        }
        maze[x][y] = 0;
        return false;
    }
    
    return false;
}

int main()
{
    int maze[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    
    flagDeploy(maze, 0, 0);
    
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<4; j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
