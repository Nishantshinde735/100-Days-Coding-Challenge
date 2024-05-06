#include <iostream>
#include <queue>

int main() {
   
    std::queue<int> q;


    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);


    std::cout << "Size of queue: " << q.size() << std::endl;

   
    std::cout << "Front element: " << q.front() << std::endl;

   
    std::cout << "Back element: " << q.back() << std::endl;

   
    while (!q.empty()) {
        std::cout << "Removing front element: " << q.front() << std::endl;
        q.pop();  
    }

  
    if (q.empty()) {
        std::cout << "Queue is now empty." << std::endl;
    }

    return 0;
}
