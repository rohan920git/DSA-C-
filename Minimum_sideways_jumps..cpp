class Solution {
public:
    int solve(vector<int>&obstacles, int lane , int point){
        if(point == obstacles.size()-1){
            return 0;
        }
       
        if(obstacles[point+1] != lane){
           return solve(obstacles, lane ,point +1); 
        }  
        else{
             int ans = INT_MAX;
            for(int i = 1 ; i<= 3 ;i++){
                if(i != lane){
                if(obstacles[point] != i){
                    ans = min(ans , 1+solve(obstacles, i , point+1));
                }
                }
            }
         return ans;
         }
    
    }
    
    int solveMem(vector<int>&obstacles, int lane , int point,vector<vector<int>>&dp){
        if(point == obstacles.size()){
            return 0;
        }
       if(dp[lane][point] != -1){
           return dp[lane][point];
       }
        if(obstacles[point+1] != lane){
            dp[lane][point] = solveMem(obstacles, lane ,point +1,dp);
           return dp[lane][point];
        }  
        else{
             int ans = INT_MAX;
            for(int i = 1 ; i<= 3 ;i++){
                if(i != lane){
                if(obstacles[point] != i){
                    ans = min(ans , 1+solveMem(obstacles, i , point+1,dp));
                }
                }
            }
            dp[lane][point]=ans;
         return ans;
         }
    
    }
      int solveTab(vector<int>&obstacles){
        int n = obstacles.size();
          vector<int>curr(4, 0);
          vector<int>next(4, 0);
          next[0] = 0 ;
          next[1] = 0 ;
          next[2] = 0 ;
          next[3] = 0 ;
          for(int point = n-2 ; point >= 0 ; point--){
              for(int lane = 1 ; lane <=3; lane++){
                          if(obstacles[point+1] != lane){
                                curr[lane] = next[lane];
                         
                            }  
                            else{
                                 int ans = INT_MAX;
                                for(int i = 1 ; i<= 3 ;i++){
                                    if(i != lane){
                                    if(obstacles[point] != i){
                                        ans = min(ans , 1 + next[i] );
                                    }
                                    }
                                }
                                curr[lane]=ans;
                               
                             }
                   next = curr;
                  
              }
          }
          return min(curr[2],min(curr[1]+1 ,curr[2]+1 ) );
    }
    int minSideJumps(vector<int>& obstacles) {

        
        return solveTab(obstacles);
    }
};
