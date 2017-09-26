class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return INT_MAX;
        int l,r,diff,mindiff,res;
        mindiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;++i){
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                diff= nums[i]+nums[l]+nums[r] - target;
                if(abs(diff)<abs(mindiff)) mindiff = diff;
                if(diff<0) l++;
                else if(diff>0) r--;
                else break;                 
            }
            
        }
        res = target + mindiff;
        return res;
   
    }
};
