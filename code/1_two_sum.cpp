class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            um[nums[i]]=i;
        }
        unordered_map<int, int>::iterator it;
        for(int i=0;i<nums.size();++i){
            it=um.find(target-nums[i]);
            if(it!=um.end()&&(it->second!=i)){
                res.push_back(i);
                res.push_back(it->second);
                return res;
            }
                
        }
    }
};