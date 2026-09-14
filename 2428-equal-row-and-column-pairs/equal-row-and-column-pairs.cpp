class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        map<vector<int>, int> mp;

        // Store all rows
        for (int i = 0; i < n; i++) {
            mp[grid[i]]++;
        }

        int ans = 0;

        // Check all columns
        for (int j = 0; j < n; j++) {
            
            vector<int> col;

            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            // If column matches a row
            if (mp.find(col) != mp.end()) {
                ans += mp[col];
            }
        }

        return ans;
    }
};