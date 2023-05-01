class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index , bool swaped){
       if(index >= nums1.size()){
           return 0;
       }
       int ans = 1e9;
       int pre1 = nums1[index-1];
       int pre2 = nums2[index-1];
        if(swaped){
            swap(pre1, pre2);
     }
        
       if(nums1[index] > pre1 && nums2[index]  > pre2){
         ans = solve(nums1 , nums2 , index+1 , 0);
      }
      if(nums1[index] > pre2 && nums2[index] >pre1){
          ans = min(ans, 1+ solve(nums1 ,nums2, index+1 , 1));
      }
        return ans;
    }
      int solveMem(vector<int>& nums1, vector<int>& nums2,int index , bool swaped ,vector<vector<int>>&dp){
       if(index >= nums1.size()){
           return 0;
       }
       if(dp[index][swaped] != -1){
           return dp[index][swaped];
       }
       int ans = 1e9;
       int pre1 = nums1[index-1];
       int pre2 = nums2[index-1];
        if(swaped){
            swap(pre1, pre2);
     }
        
       if(nums1[index] > pre1 && nums2[index]  > pre2){
         ans = solve(nums1 , nums2 , index+1 , 0);
      }
      if(nums1[index] > pre2 && nums2[index] >pre1){
          ans = min(ans, 1+ solve(nums1 ,nums2, index+1 , 1));
      }
         dp[index][swaped] = ans;
        return ans;
    }
     int solveTab(vector<int>& nums1, vector<int>& nums2){
              
              vector<int>next(3 , 0);
              vector<int>curr(3 , 0);
         for(int index = nums1.size()-1 ; index >=1  ; index--){
             for(int swaped = 0 ; swaped < 2 ; swaped++){
                 int ans = 1e9;
                   int pre1 = nums1[index-1];
                   int pre2 = nums2[index-1];
                    if(swaped){
                        swap(pre1, pre2);
                 }

                   if(nums1[index] > pre1 && nums2[index]  > pre2){
                     ans =  next [0];
                  }
                  if(nums1[index] > pre2 && nums2[index] >pre1){
                      ans = min(ans,1+ next[1]);
                  }
                     curr[swaped] = ans;
             }
             next = curr;
         }
        return curr[1];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
                vector<vector<int>>dp(nums1.size()+1 ,vector<int>(3, -1));
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin() , -1);
         return solveTab(nums1 ,nums2);
    }
};
