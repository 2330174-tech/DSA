#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Initialize both to the maximum possible integer value
        int first_min = INT_MAX;
        int second_min = INT_MAX;
        
        for (int num : nums) {
            if (num <= first_min) {
                // We found a new smallest number
                first_min = num;
            } else if (num <= second_min) {
                // We found a number larger than first_min, but smaller than our current second_min
                second_min = num;
            } else {
                // The number is strictly greater than both first_min and second_min
                return true; 
            }
        }
        
        // If we finish the loop without hitting the else block, no triplet exists
        return false;
    }
};