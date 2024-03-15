#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void actionSet(set<int>& s, int y, int x) {
    if (y == 1) {
        s.insert(x);
    }
    else if (y == 2) {
        s.erase(x);
    }
    else {
        set<int>::iterator itr = s.find(x);
        if (itr != s.end() && *itr == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, y, x;
    cin >> q;
    set<int>s;
    for (int i = 0;i < q;i++) {
        cin >> y >> x;
        actionSet(s, y, x);
    }
    return 0;
}
