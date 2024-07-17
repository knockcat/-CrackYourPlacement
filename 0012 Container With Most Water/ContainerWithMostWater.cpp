class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n-1];
        
        int i = 0, j = n-1, ans = 0;
        
        while(i < j)
        {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            
            int w = (j - i);
            int h = min(leftMax, rightMax);
            ans = max(ans, w * h);
            
            if(height[i] <= height[j])
                ++i;
            else
                --j;
        }
        
        return ans;
    }
};
