#include <iostream>
#include <vector>
using namespace std;
void generateStrings(vector<char>& characters) {
    for (auto i : characters) {
        for (auto j : characters) {
            for (auto k : characters) {
                cout << i << j << k << endl;
            }
        }
    }
}

int main() {
    vector<char> charSet = { 'a', 'b', 'c', 'd' };

    generateStrings(charSet);

    return 0;
}
