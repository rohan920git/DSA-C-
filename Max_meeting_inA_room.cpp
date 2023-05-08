//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     static bool cmp(pair<int,pair<int,int>>p1 , pair<int,pair<int,int>>p2){
        return p1.second.first < p2.second.first;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
          vector<pair<int,pair<int,int>>>p;
     for(int i  = 0 ; i < S.size() ; i++){
         p.push_back({S[i],{F[i],i}});
     }
     sort(p.begin(), p.end(), cmp);
      vector<int>ans;
      ans.push_back(p[0].second.second +1 );
      int preEnd = p[0].second.first;
     for(int i = 1 ;i < S.size(); i++){
         if(p[i].first > preEnd){
             preEnd = p[i].second.first;
             ans.push_back(p[i].second.second + 1);
             
         }
     }
       sort(ans.begin() ,ans.end());
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
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
