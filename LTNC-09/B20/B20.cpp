#include <iostream>
#include <vector>

using namespace std;

static bool isValid(int number) {
    while (number > 0) {
        int digit = number % 10;
        if (digit != 1 && digit != 3 && digit != 5) {
            return false;
        }
        number /= 10;
    }
    return true;
}

static void generateNumbersWithSum(int targetSum, int currentSum, int currentNumber, vector<int>& result) {
    if (currentSum == targetSum) {
        if (isValid(currentNumber)) {
            result.push_back(currentNumber);
        }
        return;
    }

    for (int digit : {1, 3, 5}) {
        if (currentSum + digit <= targetSum) {
            generateNumbersWithSum(targetSum, currentSum + digit, currentNumber * 10 + digit, result);
        }
    }
}

int main() {
    int targetSum = 6;
    vector<int> result;

    generateNumbersWithSum(targetSum, 0, 0, result);

    for (int number : result) {
        cout << number << endl;
    }

    return 0;
}
