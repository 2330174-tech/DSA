#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // If we don't need to plant any flowers, it's automatically true
        if (n == 0) {
            return true;
        }
        
        for (int i = 0; i < flowerbed.size(); i++) {
            // Only check if the current spot is empty
            if (flowerbed[i] == 0) {
                
                // Check left and right neighbors. 
                // If we are at the edge (i == 0 or i == size - 1), we treat the "out of bounds" neighbor as empty.
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    // Plant a flower here so it counts for future neighbor checks
                    flowerbed[i] = 1;
                    n--;
                    
                    // Early exit: we planted all required flowers
                    if (n == 0) {
                        return true;
                    }
                }
            }
        }
        
        // If we finished the loop and n is still greater than 0, we failed to plant enough
        return n <= 0;
    }
};