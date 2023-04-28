class Solution {
public:
    int solve(vector<int>& satisfaction, int i , int cnt){
        int n = satisfaction.size();
        if( i >= n ){
            return 0;
        }
        int exclude = solve(satisfaction , i+1 , cnt);
        int include = satisfaction[i]*cnt + solve(satisfaction , i+1 , cnt+1);
            return max(exclude,include);
    }
     int solveMem(vector<int>& satisfaction, int i , int cnt,vector<vector<int>>&dp){
        int n = satisfaction.size();
        if( i >= n ){
            return 0;
        }
        if(dp[i][cnt] != -1){
            return dp[i][cnt];
        }
        int include = satisfaction[i]*(cnt+1) + solveMem(satisfaction , i+1 , cnt+1 , dp);
         int exclude = solveMem(satisfaction , i+1 , cnt ,dp);
        
         dp[i][cnt] = max(exclude,include);
         return dp[i][cnt];
    }
         int solveTab(vector<int>& satisfaction){
             int n = satisfaction.size();
             
         vector<int>curr(n+1 , 0) ;
             vector<int>next(n+1 , 0) ;
             for(int i = n-1 ; i  >= 0 ; i--){
                 for(int time = i ; time >= 0 ; time--){
                     int include = satisfaction[i]*(time+1) + next[time+1];
                         int exclude = next[time];

                         curr[time] = max(exclude,include);
                         
                 }
                 next = curr;
             }
             return curr[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        // int n = satisfaction.size();
     sort(satisfaction.begin(), satisfaction.end());
        // vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        // return solveMem(satisfaction, 0 , 0 , dp);
        return solveTab(satisfaction);
    }
};
