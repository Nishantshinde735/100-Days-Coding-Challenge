#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
   
    void push(int value) {
        data.push_back(value);
    }

    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        int topElement = data.back();
        data.pop_back();
        return topElement;
    }

    
    int top() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return data.back();
    }

  
    bool isEmpty() const {
        return data.empty();
    }

  
    size_t size() const {
        return data.size();
    }

  
    void printStack() const {
        std::cout << "Stack (top to bottom): ";
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;

   
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    std::cout << "After pushing elements:" << std::endl;
    stack.printStack();


    std::cout << "Popped element: " << stack.pop() << std::endl;
    stack.printStack();

 
    std::cout << "Top element: " << stack.top() << std::endl;


    std::cout << "Stack size: " << stack.size() << std::endl;

  
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
