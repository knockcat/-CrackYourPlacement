class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minCost = INT_MAX, profit = 0;
        
        for(auto& ele : prices)
        {
            minCost = min(minCost, ele);
            profit = max(profit, ele - minCost);
        }
        
        return profit;
    }
};
