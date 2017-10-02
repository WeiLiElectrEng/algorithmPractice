class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int resd0,resd1,sum,l,r;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int>tmp(4,INT_MAX);
        
        for(int i=0;i<nums.size();++i){
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
                resd0=target-nums[i];
                for(int j=i+1;j<nums.size();++j){
                    if(j==i+1||(j>i+1&&nums[j]!=nums[j-1])){
                        resd1=resd0-nums[j];
                        l=j+1;
                        r=nums.size()-1;
                        while(l<r){
                            sum=nums[l]+nums[r];
                            if(sum<resd1) {
                                l++;
                            }else if(sum>resd1){ 
                                r--;
                            }else if(sum==resd1){
                                tmp[0]=nums[i];
                                tmp[1]=nums[j];
                                tmp[2]=nums[l];
                                tmp[3]=nums[r];
                                res.push_back(tmp);
                                while(l<r&&nums[l]==tmp[2]) l++;
                                while(l<r&&nums[r]==tmp[3]) r--;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
