class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
            int n = s.length();
        int dp[n + 1];  // dp[i] represents the minimum number of extra characters up to index i

        unordered_set<string> dict;
        for (auto word : dictionary) {
            dict.insert(word);
        }

        // Initialize dp array
        dp[0] = 0;

        // Iterate over each index of the string
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;  // Assume the current character is extra

            // Check if any substring ending at the current index is present in the dictionary
            for (int j = i - 1; j >= 0; j--) {
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};
