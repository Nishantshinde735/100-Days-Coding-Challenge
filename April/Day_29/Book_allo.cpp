#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& books, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < books.size(); i++) {
        if (books[i] > curr_min)
            return false;

        if (curr_sum + books[i] > curr_min) {
            studentsRequired++;
            curr_sum = books[i];

            if (studentsRequired > m)
                return false;
        } else {
            curr_sum += books[i];
        }
    }
    return true;
}

int findPages(vector<int>& books, int m) {
    long long sum = 0;

    if (books.size() < m)
        return -1;

    for (int i = 0; i < books.size(); i++)
        sum += books[i];

    int start = 0, end = sum;
    int result = INT_MAX;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(books, m, mid)) {
            result = min(result, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int m = 2; 

    cout << "Minimum number of pages = " << findPages(books, m) << endl;

    return 0;
}
