#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; // Pointer to overwrite the array in-place
        int read = 0;  // Pointer to scan the array
        int n = chars.size();
        
        while (read < n) {
            char currentChar = chars[read];
            int count = 0;
            
            // Count the occurrences of the current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }
            
            // Write the character
            chars[write++] = currentChar;
            
            // If the character appeared more than once, write the count
            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[write++] = digit;
                }
            }
        }
        
        // The write pointer now represents the length of the new compressed array
        return write; 
    }
};