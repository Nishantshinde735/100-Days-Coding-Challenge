#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void priorityQueueExample() {
    // Using a lambda to compare elements.
    auto cmp = [](int left, int right) { return left > right; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    // Add some elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    // Display in priority order
    cout << "Priority Queue content:";
    while (!pq.empty()) {
        cout << ' ' << pq.top();
        pq.pop();
    }
    cout << '\n';
}

int main() {
    priorityQueueExample();
    return 0;
}
