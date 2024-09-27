#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int maxMagnetsInGroup(int X, int Y, vector<int>& A) {
    // Step 1: Sort the magnets' array
    sort(A.begin(), A.end());

    // Step 2: Use a map where key is the magnetic strength and value is the count of magnets
    map<int, int> magnetGroups;

    // Initialize the first magnet as a group
    magnetGroups[A[0]] = 1;

    int maxGroupSize = 1;  // Keep track of the largest group size

    // Step 3: Traverse the sorted magnets
    for (int i = 1; i < X; ++i) {
        bool addedToExistingGroup = false;
        
        // Step 4: Traverse the map to find a suitable group (key) for the current magnet
        for (auto it = magnetGroups.begin(); it != magnetGroups.end(); ++it) {
            int existingMagnetStrength = it->first;
            int groupSize = it->second;

            // If the difference between the current magnet and the existing key is >= Y
            if (A[i] - existingMagnetStrength >= Y) {
                // Step 5: Update the group by incrementing the count
                magnetGroups[A[i]] = groupSize + 1;
                
                // Remove the old key as we have transferred the group to the new key
                magnetGroups.erase(existingMagnetStrength);
                
                // Update the maximum group size
                maxGroupSize = max(maxGroupSize, magnetGroups[A[i]]);
                addedToExistingGroup = true;
                break;
            }
        }

        // If no suitable group was found, create a new group with the current magnet
        if (!addedToExistingGroup) {
            magnetGroups[A[i]] = 1;
        }
    }

    // Step 6: Find the maximum count in the map (the largest group size)
    for (const auto& entry : magnetGroups) {
        maxGroupSize = max(maxGroupSize, entry.second);
    }

    return maxGroupSize;
}

int main() {
    // Example 1
    int X1 = 12;
    int Y1 = 3;
    vector<int> A1;
    A1.push_back(1);
    A1.push_back(5);
    A1.push_back(6);
    A1.push_back(1);
    A1.push_back(8);
    A1.push_back(3);
    A1.push_back(12);
    A1.push_back(2);
    A1.push_back(13);
    A1.push_back(7);
    A1.push_back(9);
    A1.push_back(11);
    cout << "Example 1: " << maxMagnetsInGroup(X1, Y1, A1) << endl;

    // Example 2
    int X2 = 10;
    int Y2 = 4;
    vector<int> A2;
    A2.push_back(1);
    A2.push_back(5);
    A2.push_back(6);
    A2.push_back(1);
    A2.push_back(8);
    A2.push_back(3);
    A2.push_back(12);
    A2.push_back(2);
    A2.push_back(13);
    A2.push_back(7);
    cout << "Example 2: " << maxMagnetsInGroup(X2, Y2, A2) << endl;

    return 0;
}
