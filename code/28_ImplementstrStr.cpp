class Solution {
public:
        void premap(int *next, int N, string &needle)
        {
                int i=0,j=-1;

                next[0]=-1;
                while(i<N)
                {
                    while(j>-1&&needle[i]!=needle[j])
                    {
                        j=next[j];
                        //printf("%d\n ",j);
                    }
                    i++;
                    j++;
                    next[i]=j;
                }

        }
        int strStr(string haystack, string needle)
        {
                int i=0,j=0;
                int M=haystack.size(),N=needle.size();
                if(M==0&&N==0)
                    return 0;
                else if(M==0&&N!=0)
                    return -1;
                else if(M!=0&&N==0)
                    return 0;
                
                int next[N]={0};
                premap(next, N, needle);
                while(i < M)
                {
                    while(j>-1&&haystack[i]!=needle[j])
                    {
                        j=next[j];
                    }
                    i++;
                    j++;
                    if(j>=N)
                    {
                        return i-j;
                    }
                }
                return -1;

        }

};


