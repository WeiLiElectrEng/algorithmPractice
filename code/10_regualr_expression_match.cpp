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


