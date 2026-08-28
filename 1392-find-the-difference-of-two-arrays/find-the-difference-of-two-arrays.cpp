#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Build hash sets to remove duplicates and enable O(1) lookups
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        
        std::vector<int> diff1, diff2;
        
        // Find elements in set1 that are not in set2
        for (int num : set1) {
            if (!set2.count(num)) {
                diff1.push_back(num);
            }
        }
        
        // Find elements in set2 that are not in set1
        for (int num : set2) {
            if (!set1.count(num)) {
                diff2.push_back(num);
            }
        }
        
        return {diff1, diff2};
    }
};