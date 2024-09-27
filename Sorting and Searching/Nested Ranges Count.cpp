#include <bits/extc++.h>
using namespace std;
int main() {
    cin.tie(0), ios::sync_with_stdio(0), cout.tie(0);
    int N;
    cin >> N;

    vector<pair<int, int>>ranges;
    while (N--) {
        int a, b;
        cin >> a >> b;
        ranges.emplace_back(a, b);
    }
    for (int i = 0; i < (int) ranges.size(); i++) {
        int cnt=0;
        for (int j = 0; j < (int) ranges.size(); j++)
            cnt += i != j && ranges[i].first <= ranges[j].first && ranges[j].second <= ranges[i].second;
        cout << cnt << ' ';
    }
    cout << '\n';
    for (int i = 0; i < (int) ranges.size(); i++) {
        int cnt =0;
        for (int j = 0; j < (int)ranges.size(); j++)
            cnt += i != j && ranges[j].first <= ranges[i].first && ranges[i].second<= ranges[j].second;
        cout << cnt << ' ';
    }
}