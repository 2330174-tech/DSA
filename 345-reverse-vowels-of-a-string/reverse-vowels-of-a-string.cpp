#include <string>
#include <algorithm> // For std::swap

using namespace std;

class Solution {
public:
    // Helper function to easily check for vowels (both cases)
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer until it hits a vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            
            // Move right pointer until it hits a vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            
            // Swap the vowels and move pointers inward
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};