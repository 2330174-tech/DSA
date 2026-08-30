#include <string>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::string result = "";
        
        for (char c : s) {
            if (c == '*') {
                result.pop_back(); // Remove closest non-star character to the left
            } else {
                result.push_back(c); // Add non-star character
            }
        }
        
        return result;
    }
};