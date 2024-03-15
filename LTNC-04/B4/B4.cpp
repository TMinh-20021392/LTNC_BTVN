#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a;
    int k[n];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        vector<int> Row;
        for (int j = 0; j < k[i]; j++) {
            int row;
            cin >> row;
            Row.push_back(row);
        }
        a.push_back(Row);
    }
    for (int x = 0; x < q; x++) {
        int i, j;
        cin >> i >> j;
        cout << a[i][j] << endl;
    }
    return 0;
}
