/*
Links:
https://leetcode.com/problems/unique-paths/
https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1

Memoized solution to reach every point in the map
we will need the total steps we needed to reach the point above the current and one left to the current


*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m,vector<int>(n));
        for(int i =0;i<m;i++)
        {
            paths[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            paths[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                paths[i][j]=paths[i-1][j]+paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};
