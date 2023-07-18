#include<iostream>
#include<vector>
using namespace std;
int main(){
    int c ; 
    cin>>c;
    int i = 1;
    while( i <=  c){
        int n , k ,b ,t ;
        cin>> n >> k >> b>>t;
        vector<int>pos;
        vector<int>sp;
        for(int i = 0 ; i < n ; i++){
        int a ;
        cin>>a;
        pos.push_back(a);
        }
        for(int i = 0 ; i < n ; i++){
        int a ;
        cin>>a;
        sp.push_back(a);
        }
         int ans = 0 ; 
         int nextC  = 0;

         for(int i = n-1 ;i >= 0 ; i--){
           int maxPos = pos[i]+sp[i]*t;
           if(k == 0 )break;
           if(maxPos >= b){
              ans += nextC;
              k--;
           }
           else{
            nextC++;
           }
         }
         cout<< "Case #"<<i<<": ";
         if(nextC == n || k ){
            cout<<"IMPOSSIBLE"<<endl;
         }
         else{
            cout<<ans<<endl;
         }
         i++;
    }
    return 0;
}
