#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int largestRectangleArea(const vector<int>& heights) {

    stack<int> s;
    
    
    vector<int> extendedHeights = heights;
    extendedHeights.push_back(0);
    
    int maxArea = 0;
    int i = 0;
    
   
    while (i < extendedHeights.size()) {
        
        if (s.empty() || extendedHeights[i] >= extendedHeights[s.top()]) {
            s.push(i);
            i++;
        } else {
           
            int height = extendedHeights[s.top()];
            s.pop();
            
            
            int width = s.empty() ? i : i - s.top() - 1;
            
           
            maxArea = max(maxArea, height * width);
        }
    }
    
    return maxArea;
}

int main() {
    
    vector<int> heights = {2, 1, 5, 6, 2, 3};

  
    cout << "Histogram: ";
    for (int height : heights) {
        cout << height << " ";
    }
    cout << endl;

   
    int maxArea = largestRectangleArea(heights);

   
    cout << "Largest Rectangular Area: " << maxArea << endl;

    return 0;
}
