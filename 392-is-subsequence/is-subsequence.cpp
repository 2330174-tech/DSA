#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t
        
        // Traverse while both pointers are within bounds
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // Found a match, move the 's' pointer to the next target letter
            }
            j++; // Always move the 't' pointer forward to keep scanning
        }
        
        // If i reached the length of s, we found all characters in order
        return i == s.length();
    }
};