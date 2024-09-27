#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Use a list for efficient erasure
    list<int> person;
    for (int i = 1; i <= n; i++) {
        person.push_back(i);
    }

    auto it = person.begin();
    int count = 0;

    // Continue until only one person is left
    while (n > 0) {
        // Move iterator forward by 2 steps
        for (int i = 0; i < 1; i++) {
            it++;
            if (it == person.end()) {
                it = person.begin(); // Wrap around if at end
            }
        }
        // Print the current person
        cout << *it << " ";
        // Erase the current element and get the next valid iterator
        it = person.erase(it);
        if (it == person.end()) {
            it = person.begin(); // Wrap around if at end after erase
        }
        n--;
    }
    
    return 0;
}
