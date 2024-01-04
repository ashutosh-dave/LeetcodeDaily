#include <vector>
#include <unordered_map>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        // Map to store the count of each unique element in the array
        std::unordered_map<int, int> counts;

        // Variable to store the count of occurrences for each element
        int second;

        // Variable to store the result (minimum operations needed)
        int result = 0;

        // Count occurrences of each number in the array
        for(auto num : nums) {
            counts[num]++;
        }

        // Iterate over the counts of unique elements
        for(auto i : counts) {
            second = i.second;

            // If there is a unique element, return -1 (no solution)
            if(second == 1) {
                return -1;
            }

            // If the count modulo 3 is 1, perform specific operations
            if(second % 3 == 1) {
                // Add operations for forming triplets (groups of three)
                result += (second / 3) - 1;
                // Add operations for the remaining two elements in the triplet
                result += 2;
            } else {
                // If count modulo 3 is not 1, perform regular operations for triplets
                result += (second / 3);
                // Add operations for the remaining elements (if any)
                result += ((second % 3) / 2);
            }
        }

        // Return the minimum operations needed
        return result;
    }
};
