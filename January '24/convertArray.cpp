#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to find a matrix from a given vector
    // The matrix is constructed by grouping identical elements together
    // Input: vector of integers (v)
    // Output: 2D vector representing the matrix
    vector<vector<int>> findMatrix(vector<int>& v) {
        // Create an unordered_map to store the frequency of each element in the vector
        unordered_map<int, int> um;

        // Count the frequency of each element in the vector and store it in the unordered_map
        for(auto &i : v){
            um[i]++;
        }

        // Create a 2D vector to store the resulting matrix
        vector<vector<int>> ans;

        // Continue the process until all elements in the unordered_map are processed
        while(!um.empty()){
            // Create a temporary vector to store the elements for the current row of the matrix
            // Create another vector to store the elements that need to be erased from the unordered_map
            vector<int> temp, toErase;

            // Iterate through the unordered_map to form the current row of the matrix
            for(auto &[f, s]: um){
                temp.emplace_back(f);
                s--;

                // If the frequency of the current element becomes 0, mark it for removal
                if(s == 0) toErase.emplace_back(f);
            }

            // Add the current row to the matrix
            ans.emplace_back(temp);

            // Remove elements from the unordered_map whose frequencies have become 0
            for(auto &i : toErase){
                um.erase(i);
            }
        }

        // Return the resulting matrix
        return ans;
    }
};
