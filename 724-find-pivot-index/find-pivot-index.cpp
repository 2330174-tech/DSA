#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if left sum equals right sum
            if (left_sum == total_sum - left_sum - nums[i]) {
                return i; // Leftmost pivot index
            }
            left_sum += nums[i];
        }
        
        return -1;
    }
};