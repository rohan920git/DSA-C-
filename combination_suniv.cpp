class Solution {
public:
    int solve(vector<int>&nums, int target){
        if(target == 0 ){
            return 1;
        }
        if(target < 0 ){
            return 0;
        }
         int ans = 0 ;
         for(int i = 0 ; i < nums.size() ; i++){
         ans += solve(nums, target- nums[i] );
         }
        return ans;
    }
     int solveTab(vector<int>&nums, int target){
         vector<int>dp(target+2, 0);
         dp[0]=1;
         for(int i = 1 ; i<= target ; i++){
             long long ans = 0 ;
         for(int j = 0 ; j < nums.size() ; j++){
             if( i - nums[j] >= 0 )
             ans += dp[i - nums[j]];
         }
             dp[i]=ans;
         }
      return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int>dp(target+1,-1);
        return solveTab(nums,target);
    }
};
