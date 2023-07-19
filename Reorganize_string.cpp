class Solution {
public:
    string reorganizeString(string s) {
            unordered_map<char ,int>m;
    for(int i = 0 ; i < s.size() ; i++)m[s[i]]++;
   
      priority_queue<pair<int,int>>q;
     for(auto i : m){
         q.push({i.second,i.first});
     }
     string st = "";
     while(!q.empty()){
         auto t = q.top();
         q.pop();
         st += t.second;
         t.first--;
         if(!q.empty()){
             auto tt = q.top();
             q.pop();
             st += tt.second;
             tt.first--;
           if(tt.first){
               q.push({tt.first,tt.second});
           }
         }
         if(t.first){
             q.push({t.first,t.second});
         }
     }
     for(int i = 0 ; i< st.size()-1 ;i++){
         if(st[i] == st[i+1]){
             return "";
         }
     }
     return st;
    }
};
