class Solution {
public:
    int solve(vector<int>&nums , int diff , int index){
        if( index <= 0){
            return 0;
        }
      int ans= 0;
        for(int j = index - 1 ; j >=0 ; j--){
           if(nums[index] - nums[j] == diff){
               ans  = max( ans, 1+ solve(nums, diff , j));
           }
        }
        
    return ans;
    }
    int solveMem(vector<int>&nums , int diff , int index , unordered_map<int,int>dp[]){
        if( index < 0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
      int ans= 0;
        for(int j = index - 1 ; j >=0 ; j--){
           if(nums[index] - nums[j] == diff){
               ans  = max( ans, 1+ solveMem(nums , diff , j ,dp));
           }
        }
       \
    return dp[index][diff] =ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
          if(nums.size() <=2 ){
              return nums.size();
          }
        
        int ans = 0;
        unordered_map<int,int>dp[nums.size()+1];
            for(int i = 0 ; i < nums.size() ;i++){
            for(int j = i+1 ; j < nums.size()  ; j++){
                ans = max(ans, 2 + solveMem(nums, nums[j]-nums[i], i,dp));
            }
        }
  return ans;
    }
};
