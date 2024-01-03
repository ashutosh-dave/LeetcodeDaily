class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Get the number of cookies
        int cookiesNums = s.size();
        
        // If there are no cookies, return 0 (no happy children)
        if(cookiesNums == 0)  
            return 0;

        // Sort the arrays of children's greed and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Initialize variables to keep track of the maximum number of satisfied children,
        // and pointers to iterate through the sorted arrays
        int maxNum = 0;
        int cookieIndex = cookiesNums - 1; // Start from the last cookie
        int childIndex = g.size() - 1;      // Start from the last child

        // Iterate through the arrays
        while(cookieIndex >= 0 && childIndex >= 0){
            // If the size of the current cookie is greater than or equal to
            // the greed of the current child, assign the cookie to the child
            if(s[cookieIndex] >= g[childIndex]){
                maxNum++;            // Increment the count of satisfied children
                cookieIndex--;       // Move to the next smaller cookie
                childIndex--;        // Move to the next smaller child's greed
            }
            else{
                childIndex--;        // If the cookie is not big enough, move to the next smaller child
            }
        }

        // Return the maximum number of satisfied children
        return maxNum;
    }
};
