#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void findIndex(vector<int>& v, int x) {
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it != v.end() && *it == x) {
        // If the element is found
        cout << "Yes " << it - v.begin() + 1;
    }
    else {
        it = lower_bound(v.begin(), v.end(), x + 1);
        cout << "No " << it - v.begin() + 1;
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int q, x;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x;
        findIndex(numbers, x);
    }
    return 0;
}
