class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = -1;
        int right = 0;
        // we are find index which is  a[i] < a[i+1]
        // then from back of the array we have to find a[i] > a[index]
        //than swap it in sort the right of index;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] < nums[i+1]){
                left = i;
            }
        }
        for(int i = nums.size()-1 ; i > left ;i--){
            if(left == -1){
                break;
                           }
            if(nums[i] > nums[left] ){
                right = i;
                break;
            }
        }
        if(left != -1)
        swap(nums[left], nums[right]);
        
        reverse(nums.begin()+left+1,nums.end());
    }
};
