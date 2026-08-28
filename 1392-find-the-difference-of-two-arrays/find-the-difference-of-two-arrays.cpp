#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Store unique elements of both vectors into hash sets
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        
        std::vector<int> ans1, ans2;
        
        // Find elements in set1 that do not exist in set2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                ans1.push_back(num);
            }
        }
        
        // Find elements in set2 that do not exist in set1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                ans2.push_back(num);
            }
        }
        
        return {ans1, ans2};
    }
};