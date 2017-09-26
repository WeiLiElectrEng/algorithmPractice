class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp_1d(3,0);
        sort(nums.begin(),nums.end());
        
        int len=nums.size();
        int target=0,l=0,r=len-1;
        int sum=0;
        for(int i=0;i<len; ++i){
            target=-nums[i];
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
                l=i+1;
                r=len-1;
                while(l<r){
                    sum=nums[l]+nums[r];
                    if(sum<target){
                        l++;
                    }else if(sum>target){ 
                        r--;
                    }else{
                        tmp_1d[0]=nums[i];
                        tmp_1d[1]=nums[l];
                        tmp_1d[2]=nums[r];
                        res.push_back(tmp_1d);
                        
                        while(l<r&&(nums[l]==tmp_1d[1])) l++;
                        while(l<r&&(nums[r]==tmp_1d[2])) r--;
                    }
                }
            }
        }
        
        return res;
    }
};
