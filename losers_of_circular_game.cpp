class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int temp = 1;
        unordered_map<int,int>m;
      
        
        for(int i = 1 ; m[temp] <= 0  ;i++){
            m[temp]++;
        temp = i*k + temp;
         if(temp > n ){
             temp = temp%(n) ;
             if(temp == 0){
                 temp =n;
             }
         }
        
        }
        vector<int>ans;
        for(int i = 1 ; i <= n ; i++){
            if(m.find(i) == m.end()){
                ans.push_back(i);
            }
        }
    return ans;
    }
};
