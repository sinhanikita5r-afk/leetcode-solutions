class Solution {
public:
int function(vector<int>& arr, int pages){
    int stu=1;
    int NoPages=0;
    for(int i=0; i<arr.size();i++){
        if(NoPages+arr[i]<=pages){
            NoPages+=arr[i];
        }
        else{
            stu++;
            NoPages=arr[i];
        }
    }
    return stu;

}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
           int Nostu=function(nums,mid);
            if(Nostu>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};