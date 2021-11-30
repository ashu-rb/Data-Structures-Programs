#include<bits/stdc++.h>
using namespace std;
int part(vector<int>&a,int f,int l){
    int p=a[0];
    int pp=f,ct=0;
     for(int i=f;i<l;i++)
    {
    	if(a[i]>=p)
        {
            swap(a[i],a[pp]);
            ct++;
}  }
    swap(a[pp],a[l]);
    
  

     return pp+ct;
 }
 void quicksort(vector<int>&a,int f,int l)
 {
    if(f<l)
    {
         int pp=part(a,f,l);
             quicksort(a,f,pp-1);
             quicksort(a,pp+1,l);
    }
}
int main(){
    vector<int>a={2,7,1,9,10,3,13};
    int n=a.size();
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){cout<<a[i]<<" ";}
}
