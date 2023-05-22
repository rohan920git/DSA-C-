class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int candi  = -1; 
        for(int i = 0 ; i < nums.size() ; i++){
            if(vote == 0 ){
                candi = nums[i];
                vote++;
            }
            else {
                if(candi == nums[i]){
                    vote++;
                }
                else{
                    vote--;
                }
                
            }
        }
       int count = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            if(candi == nums[i]){
                count++;
            }
        }
    if(count > nums.size()/2){
        return candi;
    }
    return -1;
    }
};
