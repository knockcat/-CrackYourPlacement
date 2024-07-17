class Solution {
public:
    
    int helper(int idx, bool buy, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(idx == prices.size())
            return 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        int ans = 0;
        
        if(buy)
            ans = max(-prices[idx] + helper(idx+1, buy^1, prices, dp), helper(idx+1, buy, prices, dp));
        else
            ans = max(helper(idx+1, buy, prices, dp), prices[idx] + helper(idx+1, buy^1, prices, dp));
        
        return dp[idx][buy] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        return helper(0, 1, prices, dp);
        
    }
};
