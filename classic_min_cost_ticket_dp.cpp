class Solution {
public:
    int solve(vector<int>&days , vector<int>&costs , int index){
        if(index >= days.size()){
            return 0;
        }
        int n = days.size();
        //creating 1 day pass
        int op1 = costs[0]+ solve(days,costs, index+1);
        // 7 days pass
        int i ;
        for( i = index ; i< n && days[i] < days[index]+7 ;i++);
        int op2 = costs[1] + solve(days,costs, i);
        //30days pass
        for( i = index ; i< n && days[i] < days[index]+ 30 ;i++);
        int op3 = costs[2] + solve(days,costs, i);
        return min(op1, min(op2, op3));
    }
    int solveDP(vector<int>&days , vector<int>&costs , int index ,vector<int>&dp){
        if(index >= days.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int n = days.size();
        //creating 1 day pass
        int op1 = costs[0]+ solveDP(days,costs, index+1,dp);
        // 7 days pass
        int i ;
        for( i = index ; i< n && days[i] < days[index]+7 ;i++);
        int op2 = costs[1] + solveDP(days,costs, i,dp);
        //30days pass
        for( i = index ; i< n && days[i] < days[index]+ 30 ;i++);
        int op3 = costs[2] + solveDP(days,costs, i,dp);
       dp[index] = min(op1, min(op2, op3));
        return dp[index];
    }
        int solveTab(vector<int>&days , vector<int>&costs){
           int n = days.size();
           vector<int>dp(days.size() +1 , INT_MAX);
            dp[n]=0;
            for(int k = n-1 ; k >= 0 ; k--){
                //solution 
                int op1 = costs[0]+ dp[k+1];
        // 7 days pass
        int i ;
        for( i = k ; i< n && days[i] < days[k]+7 ;i++);
        int op2 = costs[1] +dp[i];
        //30days pass
        for( i = k; i< n && days[i] < days[k]+ 30 ;i++);
        int op3 = costs[2] + dp[i];
       dp[k] = min(op1, min(op2, op3));
            }
            return dp[0];
    }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     // vector<int>dp(days.size()+1 , -1);
    //     // return solveDP(days, costs, 0,dp);
    //     return solveTab(days, costs);
    // }
      int mincostTickets(vector<int>& days, vector<int>& costs) {
         int ans = 0;
          queue<pair<int,int>>week;
          queue<pair<int,int>>month;
          for(int day : days){
              while(!week.empty() &&  week.front().first + 7 <= day){
                  week.pop();
              }
              while(!month.empty() &&  month.front().first + 30 <= day){
                  month.pop();
              }
              //2nd push
              week.push({day,ans +costs[1]});
              month.push({day,ans +costs[2]});
              // ans update
             ans = min(ans+costs[0], min(week.front().second, month.front().second));
          }
          return ans;
    }
};
