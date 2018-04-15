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
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    /*
     * Note
     * 		1. Size of s could be smaller than size of words
     * 		2. indexer for constraint arrays should contain tail,
     * 		   such as line 43 and line 40
     * 		4. size_t is unsigned, Be carefull when using for in
     * 		   for loop as substraction operation may cause unsigned inifinity value.
    */

    vector<int>res;
    if(s.empty()||words.empty()) return res;
    if(s.size()<words.size()) return res;
    int s_size=s.size();
    int word_len=words[0].size();
    int words_size=words.size();
    map<string,int> wmap, smap;
    for(int i=0;i<words_size;i++){
        if(words[i].size()!=word_len) return res;
        wmap[words[i]]++;

    }

        int j=0;
        int cnt=0;
        smap.clear();
        string cur_str;
    // cout<<"here"<<words_size<<endl;
    for(int i=0;i<=s_size-word_len*words_size;i++){
        j=i;
        smap.clear();
        for(cnt=0;cnt<words_size,j<=s.size()-word_len;cnt++){
            cur_str=s.substr(j,word_len);
            if(wmap.find(cur_str)==wmap.end()) break;
            smap[cur_str]++;
            if(smap[cur_str]>wmap[cur_str]) break;
            j=j+word_len;

            if(cnt==words_size-1) res.push_back(i);
        }
    }

    return res;


}
int main() {
	string s="aaa";
	vector<string> words={"aa","aa"};
	vector<int> res;
	res=findSubstring(s, words);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}

