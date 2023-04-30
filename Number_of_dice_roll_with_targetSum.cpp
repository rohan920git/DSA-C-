#define MOD 1000000007
class Solution {
 int solve( int n ,int k , int target){
    if(target == 0 &&  n == 0){
        return 1;
    }
     if(target == 0 &&  n != 0 ){
         return 0;
     }
     if(target !=  0 && n == 0){
         return 0;
     }
     int ans = 0 ;
     for(int i = 1 ; i <= k ; i++ ){
         ans += solve( n-1 , k , target - i );
     }
     return ans;
 }
     int solveMem( int n ,int k , int target  ,vector<vector<int>> &dp){
    if(target == 0 &&  n == 0){
        return 1;
    }
     if(target == 0 &&  n != 0 ){
         return 0;
     }
     if(target !=  0 && n == 0){
         return 0;
     }
         if(target < 0){
             return 0;
         }
         if(dp[n][target] != -1){
             return dp[n][target];
         }
     int ans = 0 ;
     for(int i = 1 ; i <= k  ; i++ ){
         ans = (ans%MOD + solveMem( n-1 , k , target - i ,dp ))%MOD;
     }
         dp[n][target] = ans;
     return dp[n][target];
 }
     int solveTab( int n ,int k , int target){
 
           vector<int> curr(target+1 , 0 );
         vector<int>pre(target+1, 0);
         pre[0] = 1;
         for(int in = 1 ; in <= n ; in++){
             for(int jtarget = 1 ; jtarget <= target ; jtarget++ ){
                  long long ans = 0 ;
                     for(int i = 1 ; i <= k  ; i++ ){
                         if(jtarget - i >= 0)
                         ans = (ans%MOD + pre[jtarget - i]%MOD)%MOD;
                     }
                         curr[jtarget] = ans;
             }
             pre = curr;
         }
        return pre[target];
 }
public:
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1));
        // return solveMem(n , k , target , dp);
        return solveTab(n , k , target);
    }
};
