#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n ;
     cin>>n;
     while(true){
         vector<pair<int,int>>b;
         vector<pair<int,int>>s;
         for(int i = 0 ; i < n ; i++){
            int a ; 
            cin>> a;
            if(a >= 0)b.push_back({a,i});
            else {
                s.push_back({a,i});
            }
         }
         long long int ans = 0 ; 
         int i = 0 , j = 0 ;
         while( i < b.size() && j < s.size()){
            int x = min(b[i].first , -s[j].first);
            b[i].first -= x;
            s[j].first  += x;
            int y = abs(b[i].second - s[j].second);
            ans += x*y;
            if(b[i].first == 0) i++;
            if(s[j].first == 0 )j++;
         }

         cout<<ans<<endl;
         cin>>n;
         if(n == 0 )break;
       }
 return 0;   
}
