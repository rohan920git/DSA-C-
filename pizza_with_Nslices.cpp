class Solution {
public:
    int solve(vector<int>& slices ,int i , int endindex , int n  ){
        if( n == 0  || i > endindex ){
            return 0;
        }
     int exclude = solve(  slices , i +1  , endindex , n);
     int include = slices[i] + solve(slices , i+2 , endindex,n-1);
        return max(exclude , include);
    }
     int solveMem(vector<int>& slices ,int i , int endindex , int n,vector<vector<int>>&dp ){
        if( n == 0  || i > endindex ){
            return 0;
        }
         if(dp[i][n] != -1){
             return dp[i][n];
         }
     int exclude = solveMem(  slices , i +1  , endindex , n, dp);
     int include = slices[i] + solveMem(slices , i+2 , endindex,n-1,dp);
        return dp[i][n]= max(exclude , include);
    }
    int solveTab(vector<int>& slices) {
     int k = slices.size();
   
          vector<int>curr1((k/3)+2 , 0);
          vector<int>next1((k/3)+2 , 0);
          vector<int>next2((k/3)+2 , 0);
      
        vector<int>curr2((k/3)+2 , 0);
          vector<int>next21((k/3)+2 , 0);
          vector<int>next22((k/3)+2 , 0);
        for(int i = k - 2 ; i >= 0 ; i--){
            for(int n = 1 ; n <= k/3 ; n++){
                int exclude =  next1[n];
                 int include = slices[i] + next2[n-1];
                curr1[n]= max(exclude , include);
            
            }
           next2 = next1;
            next1 = curr1;
        }
        int case1 =  curr1[k/3];
        for(int i = k - 1 ; i >= 1 ; i--){
            for(int n = 1 ; n <= k/3 ; n++){
                int exclude =  next21[n];
                 int include = slices[i] + next22[n-1];
                curr2[n]= max(exclude , include);
            
            }
            next22 = next21;
            next21 = curr2;
        }
        int case2 = curr2[k/3];
      return max(case1 ,case2);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
       //  vector<vector<int>>dp1(k , vector<int>((k/3)+1 , -1));
       //   vector<vector<int>>dp2(k , vector<int>((k/3)+1 , -1));
       //  int case1  = solveMem(slices, 0 , k-2 , k/3,dp1);
       //  int case2  = solveMem(slices, 1 , k-1 , k/3,dp2);
       // return  max(case1, case2);
        return solveTab(slices);
    }
};
