#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a, int b) {
    return (a%MOD + b%MOD)%MOD;
}
int multi(int a, int b) {
    return (a%MOD * 1ll* b%MOD)%MOD;
}
int solve(int n , int k ){
    if(n == 1 ){
        return k;
    }
    if(n == 2 ){
        return add(k,multi(k,k-1));
    }
    int ans = add(multi(solve(n-2,k),k-1) ,multi(solve(n-1,k),k-1) );
    return ans;
}
int solve_tab(int n , int k , vector<int>&dp){
    if(n == 1 ){
        return k;
    }
    if(n == 2 ){
        return add(k,multi(k,k-1));
    }
    if (dp[n] != -1) {
    return dp[n];
    }
    dp[n]= add(multi(solve_tab(n-2,k,dp),k-1) ,multi(solve_tab(n-1,k,dp),k-1) );
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1 , -1);
return solve_tab(n , k,dp);
}
