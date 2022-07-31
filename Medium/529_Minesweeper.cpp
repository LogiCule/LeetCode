/*
Link: https://leetcode.com/problems/minesweeper/

FloodFill Approach:
https://en.wikipedia.org/wiki/Flood_fill

We need to define our boundry when to stop painting the minesweeper box.
which will be when we have the box with no adcent bombs
we reveal it and ask the neighbors to reveal themselves recursively.
*/

class Solution {
public:
    void dfs(vector<vector<char>>& board, int x,int y,int first_click=0)
    {
        int click[2] = {x,y};
        if(click[0]<0 || click[0]<0)
            return ;
        if(click[0]>=board.size() || click[1]>=board[0].size())
            return ;
        if(board[click[0]][click[1]]=='M')
        {
            if(first_click)
                board[click[0]][click[1]]='X';
            return ;
        }
        if(board[click[0]][click[1]]!='E')
            return ;
        board[click[0]][click[1]]='B';
        int count=0;
        if(click[0]>0 && click[1]>0)
        {
            count+= (board[click[0]-1][click[1]-1]=='M');
        }
        if(click[0]>0)
        {
            count+= (board[click[0]-1][click[1]]=='M');
        }
        if(click[1]>0)
        {
            count+= (board[click[0]][click[1]-1]=='M');
        }
        if(click[0]<board.size()-1 && click[1]>0)
        {
            count+= (board[click[0]+1][click[1]-1]=='M');
        }
        if(click[0]>0 && click[1]<board[0].size()-1)
        {
            count+= (board[click[0]-1][click[1]+1]=='M');
        }
        if(click[0]<board.size()-1 && click[1]<board[0].size()-1)
        {
            count+= (board[click[0]+1][click[1]+1]=='M');
        }
        if(click[0]<board.size()-1)
        {
            count+= (board[click[0]+1][click[1]]=='M');
        }
        if(click[1]<board[0].size()-1)
        {
            count+= (board[click[0]][click[1]+1]=='M');
        }
        if(count>0)
        {
            board[click[0]][click[1]] = '0'+count;
            return;
        }
        dfs(board,x+1,y);
        dfs(board,x,y+1);
        dfs(board,x-1,y);
        dfs(board,x,y-1);
        dfs(board,x+1,y+1);
        dfs(board,x-1,y+1);
        dfs(board,x-1,y-1);
        dfs(board,x+1,y-1);
        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board,click[0],click[1],1);
        return board;
        
        
    }
};
