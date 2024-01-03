#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Function to calculate the number of beams based on a given bank configuration
    // Input: vector of strings representing the bank
    // Output: total number of beams formed
    int numberOfBeams(vector<string>& bank) {
        // Initialize variables to store the total number of beams (ans) and the previous count of '1's (temp)
        int ans = 0, temp = 0;

        // Iterate through each row in the bank
        for (int i = 0; i < bank.size(); i++) {
            // Count the number of '1's in the current row
            int n = count(bank[i].begin(), bank[i].end(), '1');

            // If there are no '1's in the current row, skip to the next iteration
            if (n == 0) continue;

            // Increment the total number of beams by the product of the previous count and the current count
            ans += temp * n;

            // Update the temporary count to the current count for the next iteration
            temp = n;
        }

        // Return the total number of beams formed
        return ans;
    }
};
