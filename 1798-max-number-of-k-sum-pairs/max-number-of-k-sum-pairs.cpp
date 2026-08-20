#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        int operations = 0;
        
        // Step 2: Use two pointers to find valid pairs
        while (left < right) {
            int current_sum = nums[left] + nums[right];
            
            if (current_sum == k) {
                // Found a pair! Count it and move both pointers inward
                operations++;
                left++;
                right--;
            } else if (current_sum < k) {
                // Sum is too small, need a larger number
                left++;
            } else {
                // Sum is too large, need a smaller number
                right--;
            }
        }
        
        return operations;
    }
};