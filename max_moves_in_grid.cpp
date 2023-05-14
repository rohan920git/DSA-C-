class Solution {
public:
    int solve(int i  , int j , vector<vector<int>>&grid ,vector<vector<int>>&dp){
        int row = grid.size();
        int col = grid[0].size();
        if( i >= row || j >= col){
            return INT_MIN;
            
        }
        if( dp[i][j] != -1){
            return dp[i][j];
        }
        int up = 0;
             if((i-1 >= 0 && j+1 < col) && grid[i-1][j+1] > grid[i][j]){
                 up =  1 + solve(i-1 ,j+1 ,grid,dp);
             }
       
       
        int right = 0 ;
         if((i >= 0 && j+1 < col) && grid[i][j+1] > grid[i][j]){
             right = 1 + solve(i,j+1,grid,dp);
         }
        
       int down = 0;
         if((i+1 < row && j+1 < col) && grid[i+1][j+1] > grid[i][j]){
           down = 1+solve(i+1, j+1,grid,dp);     
         }
            
        return dp[i][j]= max(up,max(right,down));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxRow = 0;
        int maxCol = 0;
       int ans = 0;
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1, -1));
        for(int i = 0; i < grid.size();i++){
           ans = max(ans, solve(i,0,grid,dp));
        }
    return ans;
    }
};
