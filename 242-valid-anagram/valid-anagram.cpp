class Solution {
public:
    bool isAnagram(string s, string t) {

        map<char, int> mpp;

        for(char ch : s){
            mpp[ch]++;
        }

        for(char ch : t){
            mpp[ch]--;
        }

        for(auto x : mpp){
            if(x.second != 0){
                return false;
            }
        }

        return true;
    }
};