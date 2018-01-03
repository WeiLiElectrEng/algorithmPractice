class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0, hi=nums.size();
        int mid=0;
        mid=(lo+hi)/2;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(nums[mid]<target) lo=mid+1;
            else hi=mid;
            
        }
        return hi;
    }
};
