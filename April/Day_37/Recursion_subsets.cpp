#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(const vector<int>& nums, int index, vector<int>& subset) {

    if (index == nums.size()) {

        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
        return;
    }

    generateSubsets(nums, index + 1, subset);

  
    subset.push_back(nums[index]);
    generateSubsets(nums, index + 1, subset);

    subset.pop_back();
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> subset;

    cout << "All subsets of the set {1, 2, 3} are:" << endl;
    generateSubsets(nums, 0, subset);

    return 0;
}
