// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
 
//     int n, k;
//     cin >> n >> k;
//     vector<int> v(n);
//     unordered_map<int, int> mp;
 
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }
 
//     for (int i = 0; i < n; i++) {
//         if (mp.find(k - v[i]) != mp.end()) {
//             cout << mp[k - v[i]] + 1 << " " << i + 1 << endl;  // 1-based indexing
//             return 0;  // Exit after finding the first pair
//         }
//         mp[v[i]] = i;
//     }
 
//     cout << "IMPOSSIBLE" << endl;
//     return 0;}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, target;
	cin >> n >> target;

	vector<pair<int, int> > values;
	// append the element and its index
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		values.push_back({x, i + 1});
	}

	sort(values.begin(), values.end());
	int left = 0;
	int right = n - 1;
	while (left < right) {
		// adjust left and right pointers
		if (values[left].first + values[right].first > target) {
			right--;
		} else if (values[left].first + values[right].first < target) {
			left++;
		} else if (values[left].first + values[right].first == target) {
			cout << values[left].second << " " << values[right].second << endl;
			return 0;
		}
	}

	// print IMPOSSIBLE if we haven't found a pair
	cout << "IMPOSSIBLE" << endl;
}