#include<vector>
#define MOD 1000000007
long long int solve( int n , vector<long long int>&dp){
    if( n== 1)
        return 0;
    if(n == 2)
        return 1;
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = ( (n-1)%MOD * ((solve(n-1 ,dp)%MOD + solve(n-2 , dp)%MOD ))%MOD );
    return dp[n];
}
long long int solvetb( int n){
    vector<long long int > dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i = 3 ; i <= n ; i++){
        long long int sum = (dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
        long long int ans = ((i-1)*sum)%MOD;   
       dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
//    vector<long long int> dp(n+1,-1);
//     return solve(n,dp);
    return solvetb(n);
}
