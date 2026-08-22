#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        
        // 1. Calculate the sum of the very first window of size k
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        double max_sum = current_sum;
        
        // 2. Slide the window across the rest of the array
        for (int i = k; i < nums.size(); i++) {
            // Add the new element on the right, remove the old element on the left
            current_sum = current_sum + nums[i] - nums[i - k];
            
            // Update max_sum if we found a larger sum
            max_sum = max(max_sum, current_sum);
        }
        
        // 3. The maximum average is simply the maximum sum divided by k
        return max_sum / k;
    }
};