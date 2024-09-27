#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int maxMagnetsInGroup(int X, int Y, vector<int>& A) {
    // Step 1: Sort the magnets' array
    sort(A.begin(), A.end());

    // Step 2: Use a multimap where key is the magnetic strength and value is the count of magnets
    multimap<int, int> magnetGroups;

    // Initialize the first magnet as the top element
    magnetGroups.insert({A[0], 1});  // The first magnet forms a group of size 1

    int maxGroupSize = 1;  // Keep track of the largest group size

    // Step 3: Traverse the sorted magnets
    for (int i = 1; i < X; ++i) {
        // Traverse the multimap to find a suitable group (key) for the current magnet
        bool addedToExistingGroup = false;

        for (auto it = magnetGroups.begin(); it != magnetGroups.end(); ) {
            int existingMagnetStrength = it->first;
            int groupSize = it->second;

            // If the difference between the current magnet and the existing key is >= Y
            if (A[i] - existingMagnetStrength >= Y) {
                // Update the group by incrementing the count
                magnetGroups.erase(it); // Remove the old key
                magnetGroups.insert({A[i], groupSize + 1});
                
                // Update the maximum group size
                maxGroupSize = max(maxGroupSize, groupSize + 1);
                addedToExistingGroup = true;
                break;
            }
            ++it;
        }

        // If no suitable group was found, create a new group with the current magnet
        if (!addedToExistingGroup) {
            magnetGroups.insert({A[i], 1});
        }
    }

    return maxGroupSize;
}

int main() {
    // Example 1
    int X1 = 12;
    int Y1 = 3;
    vector<int> A1 = {1, 5, 6, 1, 8, 3, 12, 2, 13, 7, 9, 11};
    cout << "Example 1: " << maxMagnetsInGroup(X1, Y1, A1) << endl;

    // Example 2
    int X2 = 10;
    int Y2 = 4;
    vector<int> A2 = {1, 5, 6, 1, 8, 3, 12, 2, 13, 7};
    cout << "Example 2: " << maxMagnetsInGroup(X2, Y2, A2) << endl;

    return 0;
}
