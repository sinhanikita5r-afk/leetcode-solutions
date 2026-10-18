class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int doubleSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int currentElement = nums[i];

            if (currentElement < 10) {
                singleSum += currentElement;
            }
            else {
                doubleSum += currentElement;
            }
        }

        if (singleSum == doubleSum) {
            return false;
        }
        else {
            return true;
        }
    }
};