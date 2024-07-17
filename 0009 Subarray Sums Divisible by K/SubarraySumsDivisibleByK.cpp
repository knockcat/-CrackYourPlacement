class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     
        map<int,int> mp; 
        mp.insert({0, 1});
        int sum = 0, ans = 0;
        
        for(auto& ele : nums)
        {
            sum += ele;
            int rem = ((sum % k) + k)%k;
            if(mp.find(rem) != mp.end()) 
                ans += mp[rem];
            ++mp[rem];
        }
        
        return ans;
        
    }
};
