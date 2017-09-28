class Solution {
public:
    vector<string>res;
    vector<string> keys;
    std::map<string, int> km;
    void combine(vector<string> &res, string curr);
    vector<string> letterCombinations(string digits) {

        keys.push_back("");
        keys.push_back("");
        keys.push_back("abc");
        keys.push_back("def");
        keys.push_back("ghi");
        keys.push_back("jkl");
        keys.push_back("mno");
        keys.push_back("pqrs");
        keys.push_back("tuv");
        keys.push_back("wxyz");
        
        string key_val="0123456789";
        
        for(int i=0;i<key_val.size();++i){
            km.insert(pair<string, int>(key_val.substr(i,1), i)); 
        }
        string path_record;
        if(digits.empty()) return res;
        
        
        cout<<keys[km.find(digits.substr(0,1))->second].size()<<endl;
        combine(digits, path_record);
        
        return res;
    }
    
    void combine(string curr, string path_record){
        int curr_key_size=keys[km.find(curr.substr(0,1))->second].size();
        for(int i=0;i<curr_key_size;++i){
            if(curr.size()>1)
                combine(curr.substr(1),path_record+keys[km.find(curr.substr(0,1))->second].substr(i,1));
            else{
                res.push_back(path_record+keys[km.find(curr.substr(0,1))->second].substr(i,1));
                if(i==curr_key_size-1){
                    return;
                }
            }
                
        }
    }
    
};
