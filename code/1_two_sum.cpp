class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//        Solution 1 //////////////////////////////////////	  
//        unordered_map<int,int> um;
//        vector<int> res;
//        for(int i=0;i<nums.size();++i){
//            um[nums[i]]=i;
//        }
//        unordered_map<int, int>::iterator it;
//        for(int i=0;i<nums.size();++i){
//            it=um.find(target-nums[i]);
//            if(it!=um.end()&&(it->second!=i)){
//                res.push_back(i);
//                res.push_back(it->second);
//                return res;
//            }
//                
//        }
//
//       Solution 2 //////////////////////////////////////
        vector<pair<int, int>> vp;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            vp.push_back(make_pair(nums[i],i));
        }
        sort(vp.begin(),vp.end());
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        for(l=0; l<nums.size(); ++l){
            if(l==0||(l>0&&nums[l]!=nums[l-1])){
                while((l<r)&&(nums[l]+nums[r]>target)) r--;
                if(nums[l]+nums[r]==target){
                    res.push_back(vp[l].second);
                    res.push_back(vp[r].second);
                    return res;
                }
            }
        }       
        return res;

    }
};
