#include <iostream>
#include <vector>
#include <cassert>

class NStacks {
private:
    std::vector<int> array;  
    std::vector<int> tops;   
    std::vector<int> next;   
    int n, capacity, freeTop; 

public:
    NStacks(int numStacks, int totalSize) : n(numStacks), capacity(totalSize), freeTop(0) {
        array.resize(totalSize);
        tops.resize(numStacks, -1);
        next.resize(totalSize);

    
        for (int i = 0; i < totalSize - 1; i++) {
            next[i] = i + 1;
        }
        next[totalSize - 1] = -1; 
    }

    void push(int stack, int value) {
        assert(stack < n && stack >= 0);
        if (freeTop == -1) {
            std::cout << "Stack Overflow\n";
            return;
        }

        int index = freeTop;          
        freeTop = next[index];        
        array[index] = value;          
        next[index] = tops[stack];      
        tops[stack] = index;          
    }

    int pop(int stack) {
        assert(stack < n && stack >= 0);
        if (tops[stack] == -1) {
            std::cout << "Stack Underflow\n";
            return INT_MIN;
        }

        int index = tops[stack];      
        tops[stack] = next[index];   
        next[index] = freeTop;        
        freeTop = index;               

        return array[index];        
    }

    bool isEmpty(int stack) {
        return tops[stack] == -1;
    }

    bool isFull() {
        return freeTop == -1;
    }
};

int main() {
    int numStacks = 3, totalSize = 10;
    NStacks stacks(numStacks, totalSize);

   
    stacks.push(0, 11);
    stacks.push(0, 12);
    stacks.push(1, 21);
    stacks.push(2, 31);
    stacks.push(1, 22);

   
    std::cout << "Popped from stack 0: " << stacks.pop(0) << std::endl;
    std::cout << "Popped from stack 1: " << stacks.pop(1) << std::endl;
    std::cout << "Popped from stack 2: " << stacks.pop(2) << std::endl;

    return 0;
}
