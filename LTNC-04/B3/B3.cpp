#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {
    int start = 0;
    int end = s.length() - 1;
    int index = -1;

    while (start < end) {
        if (s[start] != s[end]) {
            // Check palindrome if del the character at 'start'
            if (s[start + 1] == s[end] && (start + 2 >= end - 1 || s[start + 2] == s[end - 1])) {
                index = start;
                break;
            }
            // Check palindrome if del the character at 'end'
            if (s[start] == s[end - 1] && (start + 1 >= end - 2 || s[start + 1] == s[end - 2])) {
                index = end;
                break;
            }
        }
        start++;
        end--;
    }

    return index;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
