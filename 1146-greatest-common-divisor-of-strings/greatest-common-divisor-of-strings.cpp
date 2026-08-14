#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Step 1: Check if they share the same base pattern
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Step 2: Find the GCD of their lengths
        int gcdLength = gcd(str1.length(), str2.length());
        
        // Step 3: Return the prefix of that length
        return str1.substr(0, gcdLength);
    }
};