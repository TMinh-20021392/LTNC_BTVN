#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int q, y, t;
    string x;
    cin >> q;
    map<string, int>m;
    for (int i = 0;i < q;i++) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            map<string, int>::iterator itr = m.find(x);
            if (itr != m.end()) m[x] += y;
            else m.insert(make_pair(x, y));
        }
        else if (t == 2) {
            cin >> x;
            m.erase(x);
        }
        else {
            cin >> x;
            map<string, int>::iterator itr = m.find(x);
            if (itr != m.end()) cout << m[x] << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}



