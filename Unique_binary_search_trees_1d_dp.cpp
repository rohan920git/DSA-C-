class Solution {
public:
    int solve( int n ){
        if( n <= 1){
            return 1;
        }
        int ans = 0;
        for(int i = 1 ; i<= n ; i++){
         ans += solve( i-1 )*solve(n-i);
        }
        return ans;
    }
      int solveMem( int n,vector<int>&dp ){
        if( n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        for(int i = 1 ; i<= n ; i++){
         ans += solveMem( i-1,dp )*solveMem(n-i,dp);
        }
          dp[n]=ans;
        return dp[n];
    }
      int solveTab( int n ){
       vector<int>dp(n+1,0);
          dp[0]=1;
          dp[1]=1;
   
        for(int  N = 2; N <= n ; N++){   
            int ans = 0;
        for(int i = 1; i<= N; i++){
                 ans += dp[i-1]*dp[N-i];
                 
                 }
            dp[N]=ans;        
        }
          
      
          return dp[n];
    }
    int numTrees(int n) {
      // vector<int>dp(n+1, -1);
      //   return solveMem(n ,dp);
        return solveTab(n);
    }
};
