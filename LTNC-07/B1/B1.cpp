#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch(vector<int>& arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) return mid;

        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1) {
        cout << "Element " << x << " is present at index " << result << "." << endl;
    }
    else {
        cout << "Element " << x << " is not present in the vector." << endl;
    }

    return 0;
}