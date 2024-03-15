#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int libraryFine(int d1, int d2, int m1, int m2, int y1, int y2) {
    if (y2 > y1)
        return 0;
    if (y1 > y2)
        return 10000;
    else if (y2 == y1 && m1 > m2)
        return abs(m2 - m1) * 500;
    else if (y2 == y1 && m2 == m1 && d2 < d1)
        return abs(d2 - d1) * 15;
    else
        return 0;
}

int main() {
    int d1, d2, m1, m2, y1, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;
    cout << libraryFine(d1, d2, m1, m2, y1, y2);
    return 0;
}
