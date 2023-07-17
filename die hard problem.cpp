#include<iostream>
using namespace std;
int main(){
    int t; 
    cin>>t;
    while(t--){
        int h ;  
        cin>>h;
        int a ; 
        cin>>a;
        int cnt = 0 ; 
        bool canGo = true;
        while( h > 0  && a > 0  ){
            if(canGo){
                h = h + 3;
                a = a + 2;
                cnt++;
                canGo = false;
            }
            else if( (h - 5 > 0 )  && (a - 10 > 0 )){
                h = h-5;
                a = a-10;
                cnt++;
                canGo = true;
            }
            else if(h-20 > 0){
               h = h-20;
               a = a+5;
               cnt++;
               canGo = true;
            }
            else{
                break;
            }
        }
      cout<<cnt<<endl;
    }
    return 0;
}
