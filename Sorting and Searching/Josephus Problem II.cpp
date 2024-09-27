#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void Josephus(ordered_set &children, int k, int index)
{
    if (children.size() == 1)
    {
        cout << *(children.find_by_order(0));
        return;
    }
    index = (index + k) % children.size();
    cout << *(children.find_by_order(index)) << " ";
    children.erase(*(children.find_by_order(index)));
    Josephus(children, k, index);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, k =0, index = 0;
    cin >> n >> k;
    ordered_set children;
    for (int i = 1; i <= n; i++)
        children.insert(i);
    Josephus(children, k, index);
}