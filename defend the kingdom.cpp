#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int main(){
    int t ;
    cin>>t;

  while(t--) { 
    int w;
    
    int h ;

    int n ;
    cin>>w>>h>>n;
    
    
     vector<int> width;
     vector<int> height;
     width.push_back(0);
     height.push_back(0);

    for(int i = 0 ; i < n ; i++){
        int x , y;
        cin>>x>>y;
        width.push_back(x);
        height.push_back(y);
    }
       width.push_back(w+1);
     height.push_back(h+1);
     sort(width.begin() , width.end());
     sort(height.begin() , height.end());
     int x = 0 ,  y= 0;
      for(int i = 0 ; i < width.size()-1; i++){
        x = max(x , width[i+1]-width[i]-1);
         y = max(y , height[i+1]-height[i]-1);
      }
    cout<<x*y<<endl;
    }
    return 0;
}
