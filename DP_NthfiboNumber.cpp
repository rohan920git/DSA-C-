//solved using dp
#include <bits/stdc++.h>
#define LOG 1000000007
int solve(int n ,vector<int> &ans) {
  if (n <= 2 ) {
ans[n]=1;
  return ans[n];
}

 if(ans[n] != -1){
     return ans[n];
 }

  ans[n] = (solve(n-1,ans)%LOG + solve(n-2,ans)%LOG)%LOG;
 return ans[n];
}
int solve_tab(int n ){
    vector<int>dp(n+1);
    dp[1]=1;
    dp[2]=1;
    for(int i = 3 ;i <= n ; i++){
        dp[i]=(dp[i-1]%LOG+dp[i-2]%LOG)%LOG;
    }
    return dp[n];
}
int fibonacciNumber(int n){
    // vector<int>ans(n+1, -1);
    // solve(n ,ans);
return solve_tab(n); 
}
