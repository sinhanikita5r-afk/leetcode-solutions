class Solution {
public:

    int function(vector<int>& arr, int pages) {
        int stu = 1;
        int pageStudent = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(pageStudent + arr[i] <= pages) {
                pageStudent += arr[i];
            }
            else {
                stu++;
                pageStudent = arr[i];
            }
        }

        return stu;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int NoStu = function(nums, mid);

            if(NoStu > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};