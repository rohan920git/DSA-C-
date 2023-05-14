class Solution {
public:
int maxCrossingSum(vector<int>& nums, int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + nums[i];
        left_sum = max(left_sum,sum);
    }
 
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + nums[i];
        right_sum = max(right_sum,sum);
    }
    return max(left_sum + right_sum, max(left_sum, right_sum));
}
 

int maxSubArraySum(vector<int>& nums, int l, int h)
{
    if (l == h)
        return nums[l];
    int m = (l + h) / 2;
    int left = maxSubArraySum(nums, l, m);
    int right = maxSubArraySum(nums, m + 1, h);
    int total =maxCrossingSum(nums, l, m, h);
                    return max(left, max(right,total));
}
    
    int maxSubArray(vector<int>& nums) {
        // Using Divide and Conquer
        int low=0;
        int high=nums.size()-1;
        int ans=maxSubArraySum(nums,low,high);
        return ans;
    }
};
