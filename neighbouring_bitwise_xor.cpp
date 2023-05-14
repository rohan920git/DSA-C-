class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
     vector<int>ans1;
        vector<int>ans2;
        ans1.push_back(0);
        ans2.push_back(1);
        for(int i = 0; i< derived.size()-1 ; i++){
            if(derived[i] == 0){
                if(ans1[i] == 0){
                    ans1.push_back(0);
                }
                else{
                    ans1.push_back(1);
                }
               
            }
            else{
                  if(ans1[i] == 0){
                    ans1.push_back(1);
                }
                else{
                    ans1.push_back(0);
                }
                
                
            }
        }
        if(ans1[0] ^ ans1[derived.size()-1] == derived[derived.size()-1])
            return true;
        
        return false;
    }
};
