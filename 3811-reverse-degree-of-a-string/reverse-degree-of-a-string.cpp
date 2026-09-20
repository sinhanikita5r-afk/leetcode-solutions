class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // Reverse alphabet value
            int reverseValue = 'z' - ch + 1;

            // Position is i + 1
            ans += reverseValue * (i + 1);
        }

        return ans;
    }
};