#include <iostream>


#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define PI 3.14159

#define DEBUG

int main() {
    int x = 5, y = 10;

    std::cout << "The maximum of " << x << " and " << y << " is " << MAX(x, y) << std::endl;

    std::cout << "The value of PI is " << PI << std::endl;

  
#ifdef DEBUG
    std::cout << "Debugging is enabled." << std::endl;
#endif

    return 0;
}
