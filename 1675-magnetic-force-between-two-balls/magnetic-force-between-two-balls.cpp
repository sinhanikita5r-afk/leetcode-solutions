class Solution {
public:

    bool canWePlace(vector<int>& arr, int distance, int m) {
        int countM = 1;
        int lastM = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastM >= distance) {
                countM++;
                lastM = arr[i];
            }

            if (countM >= m)
                return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canWePlace(position, mid, m)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};