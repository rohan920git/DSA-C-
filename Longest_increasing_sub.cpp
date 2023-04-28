class Solution {
public:
    int solve(vector<int>&nums , int pre, int curr){
        if(curr >= nums.size()){
            return 0;
        }
        int exclude = solve(nums, pre , curr+1);
        int include = 0;
        if(pre == -1){
            include = 1+solve(nums, curr , curr+1);
        }
        else if(nums[pre] < nums[curr]){
            include = 1+solve(nums, curr , curr+1);
        }
        return max(include ,exclude);
    }
     int solveMem(vector<int>&nums , int curr, int pre , vector<vector<int>>&dp){
        if(curr >= nums.size()){
            return 0;
        }
        if(pre >= 0){
                    if(dp[curr][pre+1] != -1){
                        return dp[curr][pre+1];
                    }
        }
        int exclude = 0+solveMem(nums, curr+1 , pre,dp);
        int include = 0;
        if(pre == -1 ||  nums[pre] < nums[curr]){
            include = 1+solveMem(nums, curr+1 , curr ,dp);
        }
      
         
    dp[curr][pre+1]= max(include,exclude);
     return dp[curr][pre+1];
     }
     int solveTab(vector<int>&nums ){
         int n = nums.size();
       vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
         for(int curr = n-1 ; curr >= 0; curr--){
             for(int pre = curr-1 ; pre >= -1 ; pre--){
                   int exclude = 0+dp[curr+1][pre+1];
                    int include = 0;
                    if(pre == -1 ||  nums[pre] < nums[curr]){
                        include = 1 + dp[curr+1][curr+1];
                    }


                dp[curr][pre+1]= max(include,exclude);
                 
             }
         }
        return dp[0][0];         
     }
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // int pre = -1;
        // int curr = 0;
        // vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        // return solveMem(nums, curr, pre,dp);
        return solveTab(nums);
    }
};
