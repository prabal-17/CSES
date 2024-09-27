// #include <bits/stdc++.h>
// using namespace std;
// struct ranges
// {
//     int l,r,index;
//     bool operator <(const ranges &other) const
//     {
//         if(l==other.l)
//             return r>other.r;
//         return l<other.l;
//     }
// };
// int main() {
//     int n;
//     cin >> n;
//     // TLE
//     // // Using multimap to store t as the key and {index, s} as the value
//     // multimap<int, pair<int, int>> mp;
//     // vector<int> arr1(n, 0); // First result array
//     // vector<int> arr2(n, 0); // Second result array

//     // // Reading input pairs and storing them in the multimap
//     // for (int i = 0; i < n; i++) {
//     //     int t, s;
//     //     cin >> t >> s;
//     //     mp.insert({t, {i, s}}); // Insert multiple values for the same key 't'
//     // }

//     // // Set to keep track of the previous elements in sorted order by s_value
//     // set<pair<int, int>> prev_elements; // {s_value, index}

//     // // Traversing through the multimap in sorted order by key
//     // for (auto it1 = mp.begin(); it1 != mp.end(); ++it1) {
//     //     int current_t = it1->first;
//     //     int index = it1->second.first;   // Current index
//     //     int s_value = it1->second.second; // Current s_value

//     //     // Use lower_bound to efficiently find elements in prev_elements where prev_s >= s_value
//     //     auto it = prev_elements.lower_bound({s_value, -1}); // Find the first element where prev_s >= s_value
        
//     //     // Iterate through all valid previous elements
//     //     for (auto it2 = it; it2 != prev_elements.end(); ++it2) {
//     //         int prev_s = it2->first;
//     //         int prev_index = it2->second;

//     //         // Update arr1 and arr2 as per the condition
//     //         arr1[prev_index] = 1; // Update arr1 for the previous index
//     //         arr2[index] = 1;      // Update arr2 for the current index
//     //     }

//     //     // Store the current element in the set
//     //     prev_elements.insert({s_value, index});
//     // }

//     // // Output the result arrays
//     // for (int i = 0; i < n; i++) {
//     //     cout << arr1[i] << " ";
//     // }
//     // cout << endl;

//     // for (int i = 0; i < n; i++) {
//     //     cout << arr2[i] << " ";
//     // }
//     vector<ranges>arr(n);
//     vector<bool>contained(n);
//     vector<bool>contains(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i].l;
//         cin>>arr[i].r;
//         arr[i].index=i;
//     }
//     sort(arr.begin(),arr.end());
//     int maxend=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i].r<=maxend)
//         {
//             contained[arr[i].index]=true;
//         }
//         maxend=max(maxend,arr[i].r);
//     }
//      int minend=1e9;
//     for(int i=n-1;i>=0;i--)
//     {
//         if(arr[i].r > minend)
//         {
//             contains[arr[i].index]=true;
//         }
//         minend=min(minend,arr[i].r);
//     }
//     for(int i=0;i<n;i++)cout<<contains[i]<<" ";
//     cout<<endl;
//     for(int i=0;i<n;i++)cout<<contained[i]<<" ";


//     return 0;
// }


// 2nd 


// #include <bits/stdc++.h>
// using namespace std;

// // Struct to define the ranges
// struct ranges {
//     int l, r, index; // Left and right range, and the index

//     // Overloading the less-than operator for sorting
//     bool operator <(const ranges &other) const {
//         if (l == other.l)
//             return r > other.r;
//         return l < other.l;
//     }
// };

// int main() {
//     int n;
//     cin >> n;

//     // Declare a vector of 'ranges' to store the ranges along with their index
//     vector<ranges> arr(n);

//     // Declare vectors to store whether a range is contained or contains another
//     vector<bool> contained(n, false); // Initialize with false
//     vector<bool> contains(n, false);  // Initialize with false

//     // Input the ranges and store their indices
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i].l >> arr[i].r;
//         arr[i].index = i; // Store the original index
//     }

//     // Sort the ranges based on the custom comparator defined in the struct
//     sort(arr.begin(), arr.end());

//     // Determine which ranges are contained within others
//     int maxend = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i].r <= maxend) {
//             contained[arr[i].index] = true;
//         }
//         maxend = max(maxend, arr[i].r);
//     }

//     // Determine which ranges contain others
//     int minend = 1e9;
//     for (int i = n - 1; i >= 0; i--) {
//         if (arr[i].r > minend) {
//             contains[arr[i].index] = true;
//         }
//         minend = min(minend, arr[i].r);
//     }

//     // Output the result for 'contains'
//     for (int i = 0; i < n; i++) {
//         cout << contains[i] << " ";
//     }
//     cout << endl;

//     // Output the result for 'contained'
//     for (int i = 0; i < n; i++) {
//         cout << contained[i] << " ";
//     }

//     return 0;
// }
// C++ Code for CSES - Nested Ranges Check

/*
Problem Name: Nested Ranges Check
Problem Link: https://cses.fi/problemset/task/2168
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second

map<int,int> mp;
const int N = 2e5+1;
int T[N+1]={0};
void update(int n, int x, int val){
    for(;x<=n; x+=x&-x) T[x]+=val;
}
int query(int x){
    int s=0;
    for(;x>0;x-=x&-x) s+=T[x];
    return s;
}

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    if (a.F.F == b.F.F)
        return a.F.S > b.F.S;
    return a.F.F < b.F.F;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n; cin>>n;
    set<int> b;
    vector<pair<pair<int,int>, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin>>x>>y;
        v[i].S = i;
        v[i].F = {x, y};
        b.insert(y);
    }
    int cnt = 0;
    for (auto i: b) {
        mp[i] = ++cnt;
    }
    sort(v.begin(), v.end(), comp);
    update(cnt, mp[v[n-1].F.S], 1);
    int ans[n] = {0};
    for (int i = n-2; i >= 0; i--) {
        ans[v[i].S] += query(mp[v[i].F.S]);
        update(cnt, mp[v[i].F.S], 1);
    }

    for (int i = 0; i < n; i++)
        cout<<(ans[i] > 0)<<' ';

    memset(ans, 0, sizeof ans);
    memset(T, 0, sizeof T);
    update(cnt, 1, 1);
    update(cnt, mp[v[0].F.S] + 1, -1);
    for (int i = 1; i < n; i++) {
        ans[v[i].S] += query(mp[v[i].F.S]);
        update(cnt, 1, 1);
        update(cnt, mp[v[i].F.S] + 1, -1);
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
        cout<<(ans[i] > 0)<<' ';
}

