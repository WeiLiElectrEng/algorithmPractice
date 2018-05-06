class Solution {
public:
    string countAndSay(int n) {
	/* 1. Covert string element to char
	 * 2. Amend string
	 * 
	 */
        string res="1";
        int ssize=res.size();
        int cnt=1;
        char c;
        stringstream ss;
        while((--n)>0){
            cnt=1;
            c=res[0];
            ssize=res.size();
            ss.str("");
            for(int i=1;i<ssize;i++){
                if(c==res.at(i)){
                    cnt++;
                }else{
                    ss<<cnt<<c;
                    c=res[i];
                    cnt=1;
                }
            }
            ss<<cnt<<c;
            res=ss.str();
        }
        return res;
    }
};
