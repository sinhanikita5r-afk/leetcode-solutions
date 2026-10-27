class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();

        for (int i = 0; i < n; i++) {
            string s = words[i];

            int left = 0;
            int right = s.size() - 1;

            bool isPalindrome = true;

            while (left < right) {
                if (s[left] != s[right]) {
                    isPalindrome = false;
                    break;
                }

                left++;
                right--;
            }

            if (isPalindrome) {
                return s;
            }
        }

        return "";
    }
};