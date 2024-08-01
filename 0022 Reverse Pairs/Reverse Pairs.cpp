using ll = long long;

class Solution {
public:
    
    int merge(int low, int mid, int high, vector<int>& nums, vector<int>& arr)
    {
        int i = low, j = mid+1, k = low;
        
        int ans = 0;
        
        for(int i = low; i <= mid; ++i)
        {
            while(j <= high and nums[i] > (ll)2 * nums[j])
            {
                ans += (mid - i + 1);
                ++j;
            }
        }
        
        j = mid+1;
        
        while(i <= mid and j <= high)
        {
            if(nums[i] <= nums[j])
                arr[k++] = nums[i++];
            else
                arr[k++] = nums[j++];
        }
        
        while(i <= mid)
            arr[k++] = nums[i++];
        
        while(j <= high)
            arr[k++] = nums[j++];
        
        for(int i = low; i <= high; ++i)
            nums[i] = arr[i];
        
        return ans;
    }
    
    int mergeSort(int low, int high, vector<int>& nums, vector<int>& arr)
    {
        int ans = 0;
        if(low < high)
        {
            int mid = (low + high) / 2;
            ans += mergeSort(low, mid, nums, arr);
            ans += mergeSort(mid+1, high, nums, arr);
            ans += merge(low, mid, high, nums, arr);
        }
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
     
        int n = nums.size();
        
        vector<int> arr(n);
        
        return mergeSort(0, n-1, nums, arr);

    }
};
