#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_altitude = 0;
        int max_altitude = 0; // We start at 0, so the max is at least 0
        
        for (int i = 0; i < gain.size(); i++) {
            // Update our current height
            current_altitude += gain[i];
            
            // Record it if it's the highest point we've reached
            max_altitude = max(max_altitude, current_altitude);
        }
        
        return max_altitude;
    }
};