class Solution {
public:
    bool isMatch(string s, string p) {
        const char* sp=s.c_str();
        const char* pp=p.c_str();
        return checkMatch(sp, pp);        
    }
    
    bool checkMatch(const char* s, const char* p){
        if(*s=='\0'){
            return *p=='\0';
        }
        
        if(*(p+1)!='*'){
            if((*s!='\0'&&*p=='.')||*s==*p)
                return checkMatch(s+1, p+1);
            else
                return false;
        }else{
            while((*s!='\0'&&*p=='.')||*s==*p){
                  if(checkMatch(s,p+2)) 
                    return true;  
                s++;
            }
            return checkMatch(s, p+2);
        }
        
	}
};






#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;
string multiply(string num1, string num2);


bool isMatch_dp(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1 && p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
//                if(i>0)
//                	printf("*dp[%d][%d]=%d,dp[%d][%d]=%d, dp[%d][%d]=%d\n",i,j,int(dp[i][j]),i,j-2,int(dp[i][j-2]),i-1,j,int(dp[i - 1][j]));
//                else
//                    printf("k dp[%d][%d]=%d, dp[%d][%d]=%d \n",i,j,int(dp[i][j]),i,j-2,int(dp[i][j-2]));
            } else {
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
//                printf(".p[%d][%d]=%d\n",i,j,int(dp[i][j]));
            }
//            if(i==2&&j==2)
//            	printf("hello %d\n",int(dp[i][j-2]));
        }
    }
    return dp[m][n];
}



//bool isMatch(string s, string p) {
//	//DP solution: see comment below
//	bool dp[s.size()+1][p.size()+1]={false};
//	memset(&dp[0][0],0,sizeof(bool)*s.size()*p.size());
//
//	if(s.empty()&&p.empty()){
//		return true;
//	}else if(p.empty()){
//		if(s.empty()&&(p.size()==2)&&p[0]=='.'&&p[1]=='*'){
//			return true;
//		}
//		return false;
//	}
//
//	dp[0][0]=true;
//	// Initialise s[i] <->p[1], could be in main loop
//	for(int i=0;i<int(s.size());i++){
//		dp[i+1][1]=(dp[i][0]&&((s[i]==p[0])||(p[0]=='.')))||( false&&(p[0]=='*'));
//	}
//
//	// Initialise dp[0][i] in case when p[1]='*', could be in main loop
//	if(p.size()>=2&&p[1]=='*'){
//		dp[0][2]=true;
//		for(int j=2;j<int(p.size());j++){
//			dp[0][j+1]=dp[0][j-1]&&p[j]=='*';
//		}
//	}
//	for(int i=0;i<int(s.size());i++){
//		for(int j=1;j<int(p.size());j++){
//			dp[i+1][j+1]=(dp[i][j]&&(s[i]==p[j]||p[j]=='.'))
//				    ||(dp[i][j+1]&&(p[j]=='*'&&(s[i]==p[j-1]||p[j-1]=='.'))) /* Cope with consecutive matching of 'x*' or '.*' */
//					||(dp[i+1][j-1]&&p[j]=='*'); 							 /* Cope with start of '*' and end of '*' */
//		}
//	}
//	return  dp[s.size()][p.size()];
//}

bool isMatch(string s, string p){
	/*
	 * So many corner cases:
	 *		1. Empty cases
	 *		2. When to do back tracking
	 */
		if(s.empty()&&p.empty()){
			return true;
		}else if(p.empty()){
			return false;
		}else if(s.empty()){
			if((p.size()>1&&p[1]!='*')||((p.size()==1))){
				return false;
			}
		}

		bool res=false;
		if(p.size()==1){
			if(s[0]==p[0]||p[0]=='.'){
				res=isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1));
			}else{
				return false;
			}
		}else{
			if(p[1]!='*'){
				if(s[0]==p[0]||p[0]=='.'){
					res=isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1));
				}else{
					return false;
				}
			}else{
				int i =0;
				while((i<int(s.size()))&&(p[1]=='*'&&(s[i]==p[0]||p[0]=='.'))){
					res=isMatch(s.substr(i,s.size()-i), p.substr(2, p.size()-2));
					if(res==true){
						return true;
					}
					i++;
				}
				res=isMatch(s.substr(i,s.size()-i),p.substr(2,p.size()-2));

			}
		}

		return res;
}

int main() {

	string s,p;
//	s="abcd";
//	p="d*";

//	s="aaa";
//	p="a*a";

//	s="aa";
//	p="a*a";

//	s="aaaaaaaaaaaaab";
//	p="a*a*a*a*a*a*a*a*a*a*c";

//	s="aaaaaaaaaaaaab";
//	p="a*a*a*a*a*a*a*a*a*a*c";

//	s="";
//	p="c*c*";

//	s="caafd";
//	p="caafd";

//	s="caad";
//	p="ca*d";

//	s="mississippi";
//	p="mis*is*ip*.";


//	s="a";
//	p=".*..a*";

//	s="3";
//	p="3*";


//	s="aa";
//	p="a*";

//	s="sspi";
//	p="s*p*";

//	s="aab";
//	p="c*a*b";

//	s="";
//	p="*";

	s="a";
	p=".*..";

	int res=isMatch_dp(s,p);
	int ress=isMatch(s,p);

	printf("res: %d, %d\n",res,ress);


	return 0;
}



