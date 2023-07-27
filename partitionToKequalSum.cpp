class Solution {
public:
    bool solve(vector<int> &nums ,int tempNum , int k , int t,vector<bool> &visited , int index){
        if(k == 0){
            return true;
        }
        if(tempNum > t){
            return false;
        }
        if(tempNum == t){
           return solve(nums,0 , k-1 , t ,visited, 0);
        }
        for(int i = index ; i < nums.size() ; i++){
            if(!visited[i]){
                visited[i]=true;
                if(solve(nums,tempNum+nums[i],k,t,visited, index+1))return true;
                visited[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }
        if(sum % k ){
            return false;
        }
       vector<bool>visited(nums.size() ,false);
       return solve(nums,0 , k,sum/k,visited);
    }
};
