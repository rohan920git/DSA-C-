class Solution {
public:
    string countAndSay(int n) {
      if(n == 1 )return "1";
      if(n == 2) return "11";
      string s1 = "11";
        for(int i = 3 ; i <= n ;i++){
            string t1 = "";
            int cnt = 1;
            s1 = s1+'&';
            for(int j =1 ; j < s1.size() ; j++){
                if(s1[j] != s1[j-1]){
                    t1 = t1+ to_string(cnt);
                    t1 = t1 + s1[j-1];
                    cnt = 1;
                }
                else{
                    cnt++;
                }
                
            }
              s1 = t1;
        }
    return s1;
    }
};
