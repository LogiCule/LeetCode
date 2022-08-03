/*
Links:
https://leetcode.com/problems/valid-sudoku/
https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1

Hashing approach:
FOr each row we traverse and check the count of each element and we return false if we see a duplicate
same process for the rows and the blocks we can reuse one table thus conserving memory

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            int freq[9]={};
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    freq[board[i][j]-49]++;
                    if(freq[board[i][j]-49]>1)
                        return 0;
                }
            }
            
        }
        for(int i=0;i<9;i++)
        {
            int freq[9]={};
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    freq[board[j][i]-49]++;
                    if(freq[board[j][i]-49]>1)
                        return 0;
                }
            }
            
        }
        for(int i=0;i<=6;i+=3)
        {
            for(int j=0;j<=6;j+=3)
            {
                int freq[9]={};
                for(int x=i;x<i+3;x++)
                {
                    for(int y=j;y<j+3;y++)
                    {
                        if(board[x][y]!='.')
                        {
                            freq[board[x][y]-49]++;
                            if(freq[board[x][y]-49]>1)
                            return 0;
                        }
                    }
                }
            }
        }
        
        return 1;
    }
};
