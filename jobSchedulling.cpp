// #define int long lont int
class Solution {
public:
    static bool cmp (vector<int>a ,vector<int> b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        else{
            return a[1] < b[1];
        }
    }
    int solve(vector<vector<int>>&arr , int index,vector<int>&start,vector<int>&dp){
        if(index >= arr.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int a = arr[index][0];
        int b = arr[index][1];
        int c = arr[index][2];
        int next = lower_bound(start.begin(),start.end(),b)-start.begin();
          int include = c+solve(arr, next,start,dp);  
        
        int exclude = solve(arr, index+1,start,dp);
        return dp[index] = max(include,exclude);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>arr;
        for(int i = 0 ;i < startTime.size() ; i++){
            int s = startTime[i];
            int e = endTime[i];
            int w = profit[i];
            arr.push_back({s,e,w});
        }
        sort(arr.begin(),arr.end(),cmp);
        sort(startTime.begin(),startTime.end());
        int last= INT_MIN;
        for(auto i :arr){
            last = max(last,i[1]);
        }
            for(auto i :arr){
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        vector<int>dp(arr.size()+1,-1);
       return solve(arr, 0,startTime,dp);
        // return 0;
    }
};
