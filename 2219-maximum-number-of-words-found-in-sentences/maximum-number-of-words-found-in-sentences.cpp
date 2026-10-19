class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for (int i = 0; i < sentences.size(); i++) {
            int count = 0;

            for (int j = 0; j < sentences[i].length(); j++) {
                if (sentences[i][j] == ' ') {
                    count++;
                }
            }

            count = count + 1;

            maxWords = max(maxWords, count);
        }

        return maxWords;
    }
};