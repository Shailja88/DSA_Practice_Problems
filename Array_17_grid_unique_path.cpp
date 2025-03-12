// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
//m*n using dp Tc=O(m*n) Sc=o(n*m)
    int fun(int i,int j,int m,int n,vector<vector<int>>&dp){
          if(i==m && j==n)return 1;
          if(i>m || j>n)return 0;
          if(dp[i][j]!=-1)return dp[i][j];
          int down=fun(i+1,j,m,n,dp);
          int right=fun(i,j+1,m,n,dp);
          return dp[i][j]=down+right;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(0,0,m-1,n-1,dp);
    }
};

//using combinations
//tc=O(log(min(m,n)))
//sc=O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=min(m-1,n-1);
        long long ans=1;
        for(int i=1;i<=r;i++){
              ans=(ans*(N--))/i;
        }
        return ans;
    }
};
