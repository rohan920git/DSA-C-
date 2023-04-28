class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i , int j , int &maxi){
        if( i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        int right = solve(matrix , i, j+1 , maxi);
        int digo  = solve(matrix , i+1 , j+1 ,maxi);
        int down = solve(matrix, i+1, j, maxi);
        
        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(digo,down));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
     int solveMem(vector<vector<char>>& matrix, int i , int j , int &maxi,vector<vector<int>>&dp){
        if( i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
         if(dp[i][j] != -1){
             return dp[i][j];
         }
        int right = solveMem(matrix , i, j+1 , maxi,dp);
        int digo  = solveMem(matrix , i+1 , j+1 ,maxi,dp);
        int down = solveMem(matrix, i+1, j, maxi,dp);
        
        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(digo,down));
            dp[i][j]=ans;
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
       int solveTab(vector<vector<char>>& matrix){
           int maxi = 0;
      vector<vector<int>>dp(matrix.size()+1, vector<int>(matrix[0].size() +1 ,0)); 
      int row = matrix.size(); 
      int col = matrix[0].size(); 
                 for(int i = row-1 ; i >= 0 ; i--){
                     for(int j = col -1 ; j >= 0 ; j--){
                    int right = dp[i][j+1]; 
                           int digo  = dp [i+1][j+1];
        int down = dp[i+1][j];
        
        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(digo,down));
            dp[i][j]=ans;
            maxi = max(maxi, ans);
        
        }
    
                     }
                 }
                            
                                                                                                                                                                                                                                                             return maxi*maxi;  
    }
    int maximalSquare(vector<vector<char>>& matrix) {
     int maxi  = 0;
    // solve(matrix , 0 , 0 , maxi);
        vector<vector<int>> dp(matrix.size()+1 , vector<int>(matrix[0].size()+1,-1));
        
    // solveMem(matrix ,0,0,maxi ,dp);
    //     return maxi*maxi;
        return solveTab(matrix);
    }
};
