class Solution {
public:
    int solve(vector<int> &nums , int x){
        if(x < 0){
            return 0;
        }
        if( x == 0){
            return nums[0];
        }
        int exclude = solve(nums , x - 1);
        int include = solve(nums,  x-2)+nums[x];
        return max(exclude, include);
    }
    int solve_dp(vector<int> &nums , int x ,vector<int> &dp){
        if(x < 0){
            return 0;
        }
        if( x == 0){
            return nums[0];
        }
        if(dp[x] != -1){
            return dp[x];
        }
        
        int exclude = solve(nums , x - 1);
        int include = solve(nums,  x-2)+nums[x];
        dp[x]=max(exclude, include);
        return dp[x];
    } 
    int solve_tab(vector<int> &nums){
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1; i < nums.size() ; i++){
            int exclude = prev1;
            int include = prev2 + nums[i];
            int ans = max(include, exclude);
         prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    } 
    int rob(vector<int>& nums) {
        
      return solve_tab(nums);  
    }
};
