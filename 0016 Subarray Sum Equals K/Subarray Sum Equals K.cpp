class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> mp;
        mp.insert({0, 1});
        int sum = 0, ans = 0;
        
        for(auto& ele : nums)
        {
            sum += ele;
            if(mp.find(sum - k) != mp.end())
                ans += mp[sum - k];
            ++mp[sum];
        }
        
        return ans;
    }
};
