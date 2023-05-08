//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mini(int candies[], int N ,int K){
        int i = 0;
        int ans = 0;
        int temp =0;
        int j = N;
        while(i < j ){
            ans += candies[i++];
            temp = K;
            while(j >= i && temp !=0 ){
                j--;
                temp--;
            }
        }
        return ans;
    }
    int maxi(int candies[], int N ,int K){
        int i = N-1;
        int ans = 0;
        int temp =0;
        int j= -1;
        while(i > j ){
            ans += candies[i--];
            temp = K;
            while( j <= i && temp != 0 ){
                j++;
                temp--;
            }
        }
        return ans;
    }
    
    vector<int> candyStore(int candies[], int N, int K)
    {
      vector<int> ans;
      sort(candies,candies+N);
    
      ans.push_back(mini(candies,N,K));
      ans.push_back(maxi(candies,N,K));
      return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
