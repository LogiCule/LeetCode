/*
Links: 
https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
https://leetcode.com/problems/n-queens/

Brute Force Approach:
using recursion we can create all possible queen placements and then after each combination is created we can validate and add it to the overall answer list
or print it.

BackTracking with hashing to build only valid formations:
This time we make only those combinations that are valid so before adding a queen to the bored we verify 
if any queen has been added to that diagonal or that column or not.
since those are the only ways the queen can conflict each other.
*/
class Solution {
public:
    vector<vector<string>> ans;
    void setBoard(vector<string> &arr,int i,int row[],unordered_map<int,int> &diagL,unordered_map<int,int> &diagR)
    {
        if(i==arr.size())
        {
            ans.push_back(arr);
            return;
        }
        for(int j=0;j<arr.size();j++)
        {
            if(row[j]==0 && diagL[i+j]==0 && diagR[i-j]==0)
            {
                row[j]=1;
                diagL[i+j]=1;
                diagR[i-j]=1;
                arr[i][j]='Q';
                setBoard(arr,i+1,row,diagL,diagR);
                row[j]=0;
                diagL[i+j]=0;
                diagR[i-j]=0;
                arr[i][j]='.';
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        int row[9]={};
        unordered_map<int,int> diagL;
        unordered_map<int,int> diagR;
        vector<string> arr(n,string(n,'.'));
        setBoard(arr,0,row,diagL,diagR);
        return ans;
    }
};
