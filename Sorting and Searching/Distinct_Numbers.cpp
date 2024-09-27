#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    // unordered_set<int>st;
    // st.insert(arr.begin(),arr.end());
    // cout<<st.size();
    sort(arr.begin(),arr.end());
    
   
    int i=0;
    int count=0;
    while(i<n)
    {
        int curr=arr[i];
        while(curr==arr[i])
        {
            i++;
        }
        count++;

    }
    cout<<count;

    return 0;
}