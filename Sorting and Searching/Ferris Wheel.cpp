#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    int count=0;
    while(i<=j)
    {
        if(arr[i]+arr[j]<=x)
        {count++;
        i++;
        j--;
        }
        else if(arr[i]+arr[j]>x)
        {
            count++;
            j--;
        }
        else i++;
    }
    cout<<count;

    return 0;
}