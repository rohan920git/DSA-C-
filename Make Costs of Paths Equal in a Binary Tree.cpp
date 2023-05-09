class Solution {
    int solve(int index,int &ans, vector<int>& cost){
        if(index > cost.size()){
            return 0;
        }
        int left = solve(index*2 ,ans,cost);
        int right = solve(index*2+1,ans,cost);
        ans += abs(left -right);
        return max(left,right)+cost[index-1];
    }
    
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0 ;
    solve(1 , ans , cost);
        return ans;
    }
};
