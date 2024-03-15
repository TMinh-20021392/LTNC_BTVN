#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a;
    string b;
    char temp;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl;
    cout << a + b << endl;
    temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b;
    return 0;
}
