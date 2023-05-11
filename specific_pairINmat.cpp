#include <bits/stdc++.h> 
int findMaxValue(vector<vector<int>>& mat, int n) {
	int ans=INT_MIN;
	vector<vector<int>>dp=mat;
	for(int i=0;i<n;i++) {
		dp[0][i]=(i>0?min(dp[0][i-1],mat[0][i]):mat[0][i]);
	}
	for(int i=1;i<n;i++) {
		int tmp=INT_MAX;
		for(int j=0;j<n;j++) {
			tmp=min(tmp,mat[i][j]);
			dp[i][j]=min(tmp,dp[i-1][j]);
		}
	}
	for(int i=1;i<n;i++) {
		for(int j=1;j<n;j++) {
			ans=max(ans,mat[i][j]-dp[i-1][j-1]);
		}
	}
	return ans;
}
