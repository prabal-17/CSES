#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>desired_apartment(n);
    vector<int>actual_apartment(m);
    vector<int>aval_apartment(m,1);
    for(int i=0;i<n;i++)cin>>desired_apartment[i];
    for(int i=0;i<m;i++)cin>>actual_apartment[i];
    sort(desired_apartment.begin(),desired_apartment.end());
    sort(actual_apartment.begin(),actual_apartment.end());
    int i=0;
    int count=0;
    int prev=0;
    while(i<n){
        int desired=desired_apartment[i];
        int j=prev;
        while(j<m && desired+k >=actual_apartment[j])
        {
            if((actual_apartment[j]<= (desired+k) && actual_apartment[j]>= (desired-k) )&& aval_apartment[j])
            {
                count++;
                aval_apartment[j]=0;
                break;
            }
            j++;
            prev=j;
        }
        i++;
    }
    cout<<count;
    return 0;
}