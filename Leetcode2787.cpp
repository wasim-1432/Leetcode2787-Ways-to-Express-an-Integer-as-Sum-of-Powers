class Solution {
public:
    const int MOD=1e9+7;
    int Solve(int i,int n,int x,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(i==coins.size())
        {
            return 0;
        }
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }
        int take=0;
        long long p=pow(coins[i],x);
        if(pow(coins[i],x)<=n)
        {
            take=Solve(i+1,n-p,x,coins,dp);
        }
        int notake=Solve(i+1,n,x,coins,dp);
        dp[i][n]=(take+notake)%MOD;
        return dp[i][n];
    }
    int numberOfWays(int n, int x) {
        int i=1;
        vector<int> ans;
        while(i<=n)
        {
            ans.push_back(i);
            i++;
        }
        vector<vector<int>> dp(ans.size(),vector<int>(n+1,-1));
        return Solve(0,n,x,ans,dp);
    }
};