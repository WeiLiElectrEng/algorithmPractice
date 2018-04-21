//============================================================================
// Name        : est.cpp
// Author      : wli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
		stack<int> st;
		int curr_pos=0;
		int max_len=0;
		st.push(-1);
		for(int i =0;i<(int)s.size();i++){
			if(s.substr(i,1)=="("){
				st.push(i);
			}else{
				if(st.empty()){
					st.push(i);
				}else{
					curr_pos=st.top();
					if(curr_pos!=-1){
						if(s.substr(curr_pos,1)=="("){
							st.pop();
							max_len=max(max_len, (i-st.top()));
						}else{
							st.push(i);
						}
					}else{
						st.push(i);
					}
				}
			}
		}
		return max_len;
}

int main() {
	string in="(())";

	bool aa=(in.compare(0,1,")"));
	printf("%d\n", aa);
	int res;
	res=longestValidParentheses(in);
	printf("results: %d\n", res);

	return 0;
}

