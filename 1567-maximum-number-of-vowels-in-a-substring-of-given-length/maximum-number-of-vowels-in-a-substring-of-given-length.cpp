#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Our trusty helper function from earlier!
    // We only need lowercase letters based on the problem constraints.
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int current_vowels = 0;
        int max_vowels = 0;

        // 1. Process the very first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
        }
        
        max_vowels = current_vowels;

        // 2. Slide the window across the rest of the string
        for (int i = k; i < s.length(); i++) {
            // Add the new character entering the window on the right
            if (isVowel(s[i])) {
                current_vowels++;
            }
            
            // Remove the old character leaving the window on the left
            if (isVowel(s[i - k])) {
                current_vowels--;
            }

            // Update our maximum count
            max_vowels = max(max_vowels, current_vowels);
            
            // Minor Optimization: If we found a window entirely full of vowels, 
            // we can't do any better than 'k'. Return instantly!
            if (max_vowels == k) {
                return k;
            }
        }

        return max_vowels;
    }
};