class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum candies
        int maxcandies = -1;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxcandies) {  // Changed to >
                maxcandies = candies[i];
            }
        }
    
        // Create the boolean vector to hold our results
        vector<bool> output;
        
        // Check each kid against the max
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxcandies) {
                output.push_back(true);  // Added the dot operator
            } else {
                output.push_back(false); // Added the dot operator
            }
        }
        
        return output;
    } // Added missing closing brace for the function
};