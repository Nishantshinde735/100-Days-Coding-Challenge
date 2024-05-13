#include <iostream>
#include <queue>
#include <string>

using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");

    while (n--) {
        string s1 = q.front();
        q.pop();
        cout << s1 << endl;

        string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}

int main() {
    int n = 10; 
    generateBinary(n);
    return 0;
}
