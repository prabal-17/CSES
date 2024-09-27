#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long minimum_cost(int n, vector<int>& sticks) {
    // Sort the stick lengths
    sort(sticks.begin(), sticks.end());

    // Find the median
    int median = sticks[n / 2];

    // Calculate the total cost
    long long total_cost = 0;
    for (int stick : sticks) {
        total_cost += abs(stick - median);
    }

    return total_cost;
}

int main() {
    int n;
    cin >> n;

    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    cout << minimum_cost(n, sticks) << endl;

    return 0;
}
