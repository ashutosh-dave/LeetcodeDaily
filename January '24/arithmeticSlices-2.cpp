using ll = long;
const uint max_n = 1000;
uint dp[max_n][max_n];

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        uint n = a.size();
        uint res = 0;
        unordered_map<int, vector<uint>> ai = {};
        for (uint i = 0; i < n; i++) ai[a[i]].push_back(i);
        for (uint i = 1; i < n; i++) {
            for (uint j = 0; j < i; j++) {
                dp[i][j] = 0;
                auto p = 2l * a[j] - a[i];
                if (p < INT_MIN || p > INT_MAX)
                    continue;
                auto ii = ai.find(p);
                if (ii != ai.end()) {
                    for (auto k : ai[p]) {
                        if (k >= j)
                            break;
                        dp[i][j] += dp[j][k] + 1;
                    }
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};
