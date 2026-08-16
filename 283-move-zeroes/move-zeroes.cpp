#include <vector>
#include <algorithm> // For std::swap

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0; // Keeps track of where the next non-zero should go
        
        for (int read = 0; read < nums.size(); read++) {
            // If we find a non-zero element, swap it to the 'write' position
            if (nums[read] != 0) {
                swap(nums[write], nums[read]);
                write++; // Move the write pointer forward
            }
        }
    }
};