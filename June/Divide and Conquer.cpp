#include <iostream>
#include <vector>
#include <string>
using namespace std;

string commonPrefix(const string& left, const string& right) {
    int minLength = min(left.size(), right.size());
    for (int i = 0; i < minLength; ++i) {
        if (left[i] != right[i]) {
            return left.substr(0, i);
        }
    }
    return left.substr(0, minLength);
}

string longestCommonPrefix(vector<string>& strs, int l, int r) {
    if (l == r) {
        return strs[l];
    } else {
        int mid = (l + r) / 2;
        string leftPrefix = longestCommonPrefix(strs, l, mid);
        string rightPrefix = longestCommonPrefix(strs, mid + 1, r);
        return commonPrefix(leftPrefix, rightPrefix);
    }
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    return longestCommonPrefix(strs, 0, strs.size() - 1);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
