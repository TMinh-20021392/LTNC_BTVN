#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, sum = 0;
    cin >> n;
    int a[n], b[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum -= a[i];
    }
    for (int i = 0; i < n + 1; i++) {
        cin >> b[i];
        sum += b[i];
    }
    cout << sum;
    return 0;
}
