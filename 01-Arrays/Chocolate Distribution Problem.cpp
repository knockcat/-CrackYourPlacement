class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        sort(a.begin(), a.end());
        
        int i = 0, j = 0;
        
        long long int ans = INT_MAX;
        
        while(j < n)
        {
            if(j - i + 1 == m)
            {
                ans = min(ans, a[j] - a[i]);
                ++i;
            }
            ++j;
        }
        
        return ans;
        
    }   
};
