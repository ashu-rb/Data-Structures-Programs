#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    /*for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){     //      *
                                    //     **
                                    //    ***
            if(j<=n-i)cout<<" ";
             else cout<<"*";
             for(int k=1;k<=i;k++){
                 cout<<k;
             }
        
    }cout<<endl;
    }*/    for(int i=1;i<=n;i++){
             for(int j=1;j<=n-i;j++){cout<<" ";}
             
             for(int k=1;k<=i;k++){
                 cout<<k;
             }cout<<endl;
        
    
    }
    return 0;
}