class Solution {
public:
    bool solve(vector<int>& nums , int index, int sum ){
        if(sum == 0){
            return true;
        }
        if( sum < 0 || index >= nums.size()){
            return false;
        }
        int exclude = solve(nums,index+1,sum);
        int include = solve(nums,index+1, sum-nums[index]);
        if(exclude || include){
            return true;
        }
        return false;
    }
    bool solveMem(vector<int>& nums , int index, int sum,vector<vector<int>>&dp ){
        if(sum == 0){
            return dp[index][sum] = 1;
        }
        if( sum < 0 || index >= nums.size()){
            return 0;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        int exclude = solveMem(nums,index+1,sum,dp);
        int include = solveMem(nums,index+1, sum-nums[index],dp);
        if(exclude || include){
         dp[index][sum] =  1;
        return dp[index] [sum];
        }
       return dp[index][sum] = 0;
    }
        bool solveTab(vector<int>& nums , int tsum){
            int n = nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(tsum+1,0));
            for(int i = 0 ; i < nums.size()+1 ; i++){
                dp[i][0]=1;
            }
        for(int index = n-1 ; index >= 0 ; index--){
        
          for(int sum = 0; sum <= tsum ; sum++){
                int exclude = dp[index+1][sum];
                int include = 0 ;
                 if(sum-nums[index] >= 0 )
                include = dp[index+1][sum-nums[index]];
                if(exclude || include){
                 dp[index][sum] =  1;
        
                }
                else{
               dp[index][sum] = 0;
                }
            }
        }
            return dp[0][tsum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        for(int i = 0; i < nums.size() ; i++){
            sum += nums[i];
        }
      if(sum % 2 ){
          return 0;
      }
        // vector<vector<int>>dp(nums.size()+1,vector<int>((sum/2)+1,-1));
        // return solveMem(nums,0 ,sum/2,dp);
        return solveTab(nums,sum/2);
    }
};
