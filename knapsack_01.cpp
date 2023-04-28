#include <bits/stdc++.h>
// int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight){
//     if( n == 0){
//         if(weight[0] <= maxWeight){
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }
//         int include = 0;
//         if(weight[n] <= maxWeight){
//             include = value[n]+solve(weight , value , n - 1 , maxWeight -
//             weight[n]);
//         }
//         int exclude = solve(weight , value , n - 1 , maxWeight);
//      return max(include , exclude);

// }
// int solveDP(vector<int> &weight, vector<int> &value, int n, int maxWeight,
// vector< vector<int>> &dp){
//     if( n == 0){
//         if(weight[0] <= maxWeight){
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }
//      if(dp[n][maxWeight] != -1){
//          return dp[n][maxWeight];
//      }
//         int include = 0;
//         if(weight[n] <= maxWeight){
//             include = value[n]+solveDP(weight , value , n - 1 , maxWeight -
//             weight[n] , dp);
//         }
//         int exclude = solveDP(weight , value , n - 1 , maxWeight,dp);
//     dp[n][maxWeight] = max(include , exclude);
//      return dp[n][maxWeight];

// }
int solveTab(vector<int> &weight, vector<int> &value, int n, int maxWeight) {

  vector<int> pre(maxWeight + 1, 0);

  for (int w = weight[0]; w <= maxWeight; w++) {
    if (weight[0] <= maxWeight)
      pre[w] = value[0];
    else
      pre[w] = 0;
  }
  for (int index = 1; index < n; index++) {
    for (int w = maxWeight; w >= 0; w--) {
      int include = 0;
      if (weight[index] <= w) {
        include = value[index] + pre[w - weight[index]];
      }
      int exclude = pre[w];
      pre[w] = max(include, exclude);
    }
  }
  return pre[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // solve(weight , value , n-1 , maxWeight);
  //      vector<vector<int> > dp(n,vector<int>(maxWeight + 1 , -1));
  //      return solveDP(weight , value , n-1 , maxWeight , dp);
  return solveTab(weight, value, n, maxWeight);
}
