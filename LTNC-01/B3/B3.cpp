#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a;
    long b;
    char c;
    float x;
    double t;
    cin >> a >> b >> c >> x >> t;
    cout << a << endl << b << endl << c << endl;
    cout << fixed << setprecision(3) << x << endl;
    cout << fixed << setprecision(8) << t;

    return 0;
}
