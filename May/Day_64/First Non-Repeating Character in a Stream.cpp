#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void findFirstNonRepeating() {
    queue<char> q;
    unordered_map<char, int> count;
    char stream[] = "geeksforgeeksandgeeksquizfor"; 
  
    for (int i = 0; stream[i]; i++) {
        char ch = stream[i];

     
        count[ch]++;

        q.push(ch);

       
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
}

int main() {
    findFirstNonRepeating();
    return 0;
}
