#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_T main() {
  int t;
  cin>>t;
  while(t--){
	int n,q;
	cin>>n>>q;
	
	vector<pair<int ,int>>arr;
	for(int i = 0 ; i< n ; i++){
		int a , b;
		cin>>a>>b;
		arr.push_back({a,b});
	}
	sort(arr.begin(), arr.end());
	int  index = 0 ;
	for(int i = 1 ; i< arr.size(); i++){
		if(arr[index].second >= arr[i].first){
			arr[index].second = max(arr[index].second, arr[i].second);
		}
		else{
			index++;
			arr[index] = arr[i];
		}
	}
	
	while(q--){
		int k ; 
		cin>>k;
		int ans = -1;
		for(int i = 0 ;i <= index ;i++){
			if((arr[i].second - arr[i].first+1) >= k){
				ans = arr[i].first + k -1;
			    break;
			}
			else{
				k = k-(arr[i].second - arr[i].first +1);
			}
		}
		cout<<ans<<endl;
	}
  }
}
