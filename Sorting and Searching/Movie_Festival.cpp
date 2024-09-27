#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > movie(n);
    
    for (int i = 0; i < n; i++) {
        cin >> movie[i].first >> movie[i].second;
    }
    
    sort(movie.begin(), movie.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return a.second < b.second;
    });
    
    int start = 0, count = 0;
    
    for (int i = 0; i < n; i++) {
        if (movie[i].first >= start) {
            count++;
            start = movie[i].second;
        }
    }
    
    cout << count;
    return 0;
}
