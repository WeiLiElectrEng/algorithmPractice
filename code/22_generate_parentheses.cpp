class Solution {
public:
    vector<string> res;
    // void combine_par(string curr, int left, int right, int n);
    vector<string> generateParenthesis(int n) {

        string curr;
        int left=0,right=0;
        curr="(";
        left=1;
        right=0;
        combine_par(curr, left, right, n );
        return res;
    }

    void combine_par(string curr, int left, int right, int n){
        if((left+right)==2*n){
            res.push_back(curr);
            return ;
        }

        if(left==right){  // The following for loop garuatees left cant be larger than n;
            combine_par(curr+"(", left+1, right,n);
        }else{
            string tmp;
            int i=1;
//            for(int i=1;i<=n-left;++i){
            if(i<=n-left){
                tmp=tmp+"(";
//              cout<<curr<<", "<<left<<", "<<right<<endl;
                combine_par(curr+tmp, left+i, right, n);
            }

            tmp.clear();

//            for(int i=1;i<=left-right;++i){
            if(i<=left-right){
                tmp=tmp+")";
                combine_par(curr+tmp, left,right+i,n);
            }
        }
        return;
    }

};
