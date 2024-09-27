#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, f=1;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {cin>>v[i];
    if(v[i]>0&& f==1)f=0;
    }
    long long  ans=INT_MIN;
    long long  sum_till_length=0;
    if(f==1)
    {
        cout<<*max_element(v.begin(),v.end());
        
    }
    else {for(int i=0;i<n;i++){
        sum_till_length+=v[i];
        if(sum_till_length>0)
        {
            ans=max(ans,sum_till_length);
        }
        else 
        {
            sum_till_length=0;
        }
    }
    cout<<ans;}


    return 0;
}