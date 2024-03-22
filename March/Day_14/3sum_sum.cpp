#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    
    // Sort the array
    std::sort(nums.begin(), nums.end());
    
    // Fix the first element and use two pointers to find the other two elements
    for (int i = 0; i < n - 2; ++i) {
        // Avoid duplicates
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = threeSum(nums);

    std::cout << "Triplets with sum 0:" << std::endl;
    for (const auto& triplet : result) {
        std::cout << "[";
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
