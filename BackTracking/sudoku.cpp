#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int> > &board, int row, int col, int val)
{
    for(int i =0; i<board[0].size(); i++)
    {
        if(board[row][i]==val)
        {
            return false;
        }
        if(board[i][col]==val)
        {
            return false;
        }
        if(board[3*(i/3)+i/3][3*(i/3)+i%3]==val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int> > &board)
{
    int n = board[0].size();

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(board[i][j]==0)
            {
                for(int k = 1; k<=9; k++)
                {
                    if(isSafe(board, i, j, k))
                    {
                        board[i][j] = k;

                        bool solutionPossible = solve(board);

                        if(solutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            //backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudokuSolver(vector<vector<int> > &board)
{
    solve(board);
}
