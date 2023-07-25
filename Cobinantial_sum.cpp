//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
 struct VectorComparator {
    bool operator()(const std::vector<int>& v1, const std::vector<int>& v2) const {
        if (v1.size() != v2.size())
            return v1.size() < v2.size();

        // Compare lexicographically (element-wise)
        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i])
                return v1[i] < v2[i];
        }

        // If vectors are equal, return false
        return false;
    }
};
    void solve(vector<vector<int>>&ans , vector<int>temp , vector<int>&a ,int sum ,int target,map<vector<int>, int ,VectorComparator > &M){
        if(sum == target)
        {
          sort(temp.begin() ,temp.end());
          if(M.find(temp) == M.end()){
          ans.push_back(temp);
           M[temp]++;
          }
          
          
          return ;
        }
        if(sum > target){
            return;
        }
        for(int i = 0 ; i< a.size() ; i++){
            temp.push_back(a[i]);
            solve(ans, temp,a, sum+a[i] ,target,M);
            temp.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        map<vector<int>, int  , VectorComparator> vectorMap;
       vector<vector<int>>ans;
       vector<int>temp;
       solve(ans,temp,A,0,B,vectorMap);
       sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends
