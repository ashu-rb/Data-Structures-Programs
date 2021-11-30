#include<bits/stdc++.h>
using namespace std;
int count(vector<int>a,int c,int t)

{
    int ct=0;

    if(c==a.size()){return 0;}
     count(a,c+1,subarr);
 count(a,c+1,subarr);

    return;
}
    int main()
{
    vector<int>a;
    int t;
    for(int i=0;i<a.size();i++){
        cin>>a[i];
    }

    cout<<count(a,a.size()-1,t);
    return 0;
}