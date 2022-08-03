/*
Link: https://leetcode.com/problems/n-queens-ii/

Brute Force Approach:
using recursion we can create all possible queen placements and then after each combination is created we can validate 
and increase the count

BackTracking with hashing to build only valid formations:
This time we make only those combinations that are valid so before adding a queen to the bored we verify 
if any queen has been added to that diagonal or that column or not.
since those are the only ways the queen can conflict each other.
*/
class Solution {
public:
    int ans;
    void setBoard(int n,int i,int row[],unordered_map<int,int> &diagL,unordered_map<int,int> &diagR)
    {
        if(i==n)
        {
            ans++;
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(row[j]==0 && diagL[i+j]==0 && diagR[i-j]==0)
            {
                row[j]=1;
                diagL[i+j]=1;
                diagR[i-j]=1;
                setBoard(n,i+1,row,diagL,diagR);
                row[j]=0;
                diagL[i+j]=0;
                diagR[i-j]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int row[9]={};
        ans=0;
        unordered_map<int,int> diagL;
        unordered_map<int,int> diagR;
        setBoard(n,0,row,diagL,diagR);
        return ans;
    }
};
