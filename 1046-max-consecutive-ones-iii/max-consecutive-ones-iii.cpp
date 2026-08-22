#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zero_count = 0;
        int max_len = 0;
        
        // The right pointer expands the window
        for (int right = 0; right < nums.size(); right++) {
            // If we see a 0, we use one of our flips
            if (nums[right] == 0) {
                zero_count++;
            }
            
            // If we used more flips than allowed, the window is invalid.
            // We must shrink it from the left until we drop a 0.
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--; // We recovered a flip!
                }
                left++; // Shrink the window
            }
            
            // The window is valid again, so check if it's the longest one we've seen
            // Length of a window is right - left + 1
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};