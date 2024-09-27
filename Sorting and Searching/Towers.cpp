#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    multiset<int> mst;
    for(int i=0;i<n;i++)
    {
         auto it = mst.upper_bound(arr[i]);
        if (it != mst.end()) {
            mst.erase(it);  
        }
        mst.insert(arr[i]);
        
    }
    cout<<mst.size();
    return 0;
}