class Solution {
public:
    int countBinarySubstrings(string s) {
      vector<int>count;
        s.push_back(-1);
    int cnt =1;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == s[i-1]){
                cnt++;
            }
            else{
                count.push_back(cnt);
                cnt = 1;
            }
        }
        int ans = 0;
        for(int i = 1 ; i < count.size(); i++){
            ans += min(count[i],count[i-1]);
        }
        return ans;
    }
};
