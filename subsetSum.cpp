//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int> &arr, int &sum,int currSum , int index,vector<vector<int>>&dp){
        if(index >= arr.size() || currSum > sum){
            return 0;
        }
    
        if(dp[currSum][index] != -1){
            return dp[currSum][index];
        }
        
        int Tempsum = arr[index] + currSum;
        if(Tempsum == sum ){
            return 1;
        }
        bool include = solve(arr,sum,Tempsum,index+1,dp);
        bool exclude = solve(arr, sum , currSum ,index+1,dp);
      if((include || exclude)){
          dp[currSum][index] =1 ;
      }
      else {
          dp[currSum][index] = 0;
      }
      return dp[currSum][index];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int maxi = -23;
        for(int i = 0; i < arr.size() ; i++){
            maxi = max(maxi,arr[i]);
        }
        vector<vector<int>>dp( sum+maxi ,vector<int>(arr.size(), -1));
        return solve(arr, sum , 0 , 0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
