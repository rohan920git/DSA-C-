class Solution {
public:
    bool solve(int index , string s, vector<string>&wordDict,unordered_map<string , bool>&map,vector<int>&dp){
        if(index >= s.size()) return 1;
         string temp;
        if(dp[index] != -1){
            return dp[index];
        }
        for(int j = index ; j < s.size() ; j++){
           temp += s[j];
          if(map.find(temp) != map.end()){
              if(solve(j+1, s,wordDict,map,dp)){
                   dp[index]=1;
                  return 1;                             }
              
          }
        
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<int>dp(s.size()+1,-1);
       unordered_map<string,bool>map;
        for(auto i : wordDict){
        map[i]=true;
        }
        return solve(0 , s,wordDict,map,dp);
    }
};
