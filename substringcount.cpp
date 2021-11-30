#include<bits/stdc++.h>
using namespace std;
int solve(string s,int l,int r ){
    if(r<l|| r==s.size()|| l<0){
        return 0;
    }
   
    int ans=solve(s,l,r-1)+solve(s,l+1,r)-solve(s,l+1,r-1);
    if(s[l]==s[r]) {return ans+1;}
    else {return ans;}
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s,0,s.size()-1);
    return 0;
}