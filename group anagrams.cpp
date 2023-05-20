class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i = 0; int j =0;
        
     map<string,int>m;
        int k = 0;
        for(int i = 0 ; i< strs.size();i++){
            string st = strs[i];
             sort(st.begin(),st.end());
            if(m.find(st) == m.end()){
                m[st]=k;
                k++;
            }
        }
        vector<vector<string>>ans(m.size());
       while (i < strs.size() && j < strs.size()){
           string st = strs[i];
           string temp = st;
           sort(st.begin(),st.end());
           if(m.find(st) != m.end()){
    
              int index = m[st];
               ans[index].push_back(temp);
           }
           i++;
       }
        return ans;
    }
};
