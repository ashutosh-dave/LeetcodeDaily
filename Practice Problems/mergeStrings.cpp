class Solution {
public:
    // Function to merge two strings alternately
    string mergeAlternately(string word1, string word2) {
        // Initialize pointers for each input string and result string
        int i = 0;
        int j = 0;
        string res="";

        // Merge characters alternately until either of the strings is exhausted
        while(i < word1.size() && j < word2.size()){
            res += word1[i++];
            res += word2[j++];
        }

        // If there are remaining characters in word1, append them to the result
        while(i < word1.size()){
            res += word1[i++];
        }

        // If there are remaining characters in word2, append them to the result
        while(j < word2.size()){
            res += word2[j++];
        }

        // Return the final merged string
        return res;
    }
};
