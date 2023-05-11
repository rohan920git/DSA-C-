//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
    int row = matrix.size();
    int col = matrix[0].size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0 ; i < matrix.size() ; i++){
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi , matrix[i][matrix[0].size()-1]);
    }
    int desired = (row*col +1)/2;
     while(mini < maxi){
         int mid = mini + (maxi-mini)/2;
         int smaller = 0;
         for(int i= 0; i < row ;i++){
             int s = 0;
             int e = col-1;
             while(s < e){
                 int m = s+(e-s)/2;
                 if(matrix[i][m] <= mid){
                     s = m+1;
                 }
                 else{
                     e= m;
                 }
             }
             smaller += s;
                if(matrix[i][s] <= mid){
                    smaller++;
                } 
          }
          if(smaller  < desired ){
              mini = mid +1;
          }
          else{
              maxi= mid;
          }
         
     }
     return mini;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
