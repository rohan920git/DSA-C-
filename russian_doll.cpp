 static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
       if(v1[0]==v2[0]) return v1[1] > v2[1];
      return v1[0] < v2[0];
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end() , sortcol); 
       //  vector<vector<int>>dp(n+1 , vector<int>(n , -1));
       // return  solveMem(envelopes, -1 ,0,dp);
        // return solveTab(envelopes);
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i = 1 ; i < n ; i++){
            int elem = envelopes[i][1];
            if(elem > ans.back()){
                ans.push_back(elem);
            }
            else{
            int index = lower_bound(ans.begin() , ans.end()  , elem) - ans.begin();
            ans[index]= elem;
            }
        }
    return ans.size();
    }
