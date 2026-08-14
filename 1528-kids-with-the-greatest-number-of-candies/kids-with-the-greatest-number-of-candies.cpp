#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Step 1: Find the current maximum number of candies
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        vector<bool> result;
        // Pre-allocate memory to avoid reallocations
        result.reserve(candies.size());
        
        // Step 2: Check each kid's potential total against the maximum
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
            
            // Note: This whole if/else block can also be written as a single line:
            // result.push_back(candies[i] + extraCandies >= maxCandies);
        }
        
        return result;
    }
};