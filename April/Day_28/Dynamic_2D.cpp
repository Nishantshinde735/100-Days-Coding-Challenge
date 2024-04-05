#include <iostream>

using namespace std;

int main() {
   
    int rows = 5;
    int cols = 4;

    int** array2D = new int*[rows];

    for(int i = 0; i < rows; ++i) {
        array2D[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            array2D[i][j] = i * cols + j;
        }
    }

    cout << "2D Array Elements:" << endl;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; ++i) {
        delete[] array2D[i]; 
    }
    delete[] array2D; 

    return 0;
}
