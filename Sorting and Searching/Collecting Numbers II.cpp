#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> values(n + 1, 0);
    vector<int> idx(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        idx[values[i]] = i;
    }
    
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans += (idx[i] > idx[i + 1]);
    }
    
    int l, r;
    set<pair<int, int>> st;
    
    while (m--) {
        cin >> l >> r;
        
        if (values[l] + 1 <= n)
            st.insert({values[l], values[l] + 1});
        if (values[l] - 1 >= 1)
            st.insert({values[l] - 1, values[l]});
        if (values[r] + 1 <= n)
            st.insert({values[r], values[r] + 1});
        if (values[r] - 1 >= 1)
            st.insert({values[r] - 1, values[r]});
        
        for (pair<int, int> swapped : st)
            ans -= (idx[swapped.first] > idx[swapped.second]);
        
        swap(values[l], values[r]);
        idx[values[l]] = l;
        idx[values[r]] = r;
        
        for (pair<int, int> swapped : st)
            ans += (idx[swapped.first] > idx[swapped.second]);
        
        cout << ans << endl;
        st.clear();
    }

    return 0;
}
