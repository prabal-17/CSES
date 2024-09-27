#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ticket_price(n);
    vector<int> aval_price(n, 1);
    vector<int> user(m);
    vector<int> answers(m);

    for(int i = 0; i < n; i++) cin >> ticket_price[i];
    for(int i = 0; i < m; i++) cin >> user[i];

    sort(ticket_price.begin(), ticket_price.end());
    int idx;
    for(int i = 0; i < m; i++)
    {   
        int ans = -1;
        int low = 0, high = n - 1;

        // Binary search to find the largest ticket_price <= user[i]
        while(low <= high) {
            int mid = (low + high) / 2;
            if(ticket_price[mid] <= user[i]) {
                if(aval_price[mid]) {
                    ans = ticket_price[mid];
                    idx=mid;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(ans!=-1)aval_price[idx]=0;
        
        
        cout << ans << endl;
    }
    
    return 0;
}
