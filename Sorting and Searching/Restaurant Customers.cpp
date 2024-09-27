#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>dis(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cin>>dis[i];
    }
    sort(begin(arr),end(arr));
    sort(begin(dis),end(dis));
    int i=0,j=0;
    int ans=0;
    int count=0;
    while(i<n && j<n)
    {
        if(arr[i]<dis[j])
        {count++;
        i++;
        }
        else 
        {
            count--;
            j++;
        }
        ans=max(ans,count);

    }
    cout<< ans;
    return 0;
}