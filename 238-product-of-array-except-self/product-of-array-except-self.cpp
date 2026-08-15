#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the answer array with 1s. 
        // This does not count against our O(1) space complexity constraint.
        vector<int> answer(n, 1);
        
        // Step 1: Calculate all left (prefix) products
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = left_product;    // Store the product of everything to the left
            left_product *= nums[i];     // Update the running left product
        }
        
        // Step 2: Calculate all right (suffix) products on the fly
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= right_product;  // Multiply the left product by the right product
            right_product *= nums[i];    // Update the running right product
        }
        
        return answer;
    }
};