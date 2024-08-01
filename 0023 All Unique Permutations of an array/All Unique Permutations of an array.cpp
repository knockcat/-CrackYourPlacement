class Solution {
  public:
  
    void helper(int idx, int n, vector<int>& arr, set<vector<int>>& ans)
    {
        if(idx == n)
        {
            ans.insert(arr);
            return;
        }
        
        for(int i = idx; i < n; ++i)
        {
            swap(arr[i], arr[idx]);
            helper(idx+1, n, arr, ans);
            swap(arr[i], arr[idx]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        
        set<vector<int>> ans;
        helper(0, n, arr, ans);
        vector<vector<int>> res;
        for(auto& v : ans)
            res.push_back(v);
        
        sort(res.begin(), res.end());
        
        return res;
        
    }
};
