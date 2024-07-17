class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; ++i)
        {
            if(i != 0 and nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j < n; ++j)
            {
                if(j != i+1 and nums[j] == nums[j-1])
                    continue;
                
                int k = j+1, l = n-1;
                
                while(k < l)
                {
                    if((long long) nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        while(k < l and nums[k] == nums[k-1])
                            ++k;
                    }
                    else if((long long) nums[i] + nums[j] + nums[k] + nums[l] < target)
                        ++k;
                    else
                        --l;
                }
            }
        }
        
        return ans;
    }
};
