#include <iostream>
#include <vector>
#include <string>

using namespace std;


const vector<string> keypad = {
    "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};
digits[index] - '0'];

void findCombinations(const string &digits, int index, string &current, vector<string> &result) {
    
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

   
    string possibleLetters = keypad[

    
    for (char letter : possibleLetters) {
        current.push_back(letter); 
        findCombinations(digits, index + 1, current, result); 
        current.pop_back(); 
    }
}

vector<string> letterCombinations(const string &digits) {
    vector<string> result;
    if (digits.empty()) return result;
    string current;
    findCombinations(digits, 0, current, result);
    return result;
}

int main() {
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);

    cout << "All combinations for the digits " << digits << ":" << endl;
    for (const string &comb : combinations) {
        cout << comb << endl;
    }

    return 0;
}
