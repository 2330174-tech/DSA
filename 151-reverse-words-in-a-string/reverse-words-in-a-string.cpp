#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int idx = 0; // The "write" pointer
        
        for (int start = 0; start < n; start++) {
            // If we find a non-space character, we've found the start of a word
            if (s[start] != ' ') {
                
                // If this is not the first word, prepend a single space
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                
                // Keep track of where this specific word begins in our compacted string
                int wordStart = idx;
                
                // Shift the entire word to the left
                while (start < n && s[start] != ' ') {
                    s[idx++] = s[start++];
                }
                
                // Step 2: Reverse the individual word back to normal
                reverse(s.begin() + wordStart, s.begin() + idx);
            }
        }
        
        // Step 3: Remove the leftover garbage characters at the end
        s.erase(s.begin() + idx, s.end());
        
        return s;
    }
};