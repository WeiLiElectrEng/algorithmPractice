class Solution {
public:
    int divide(int dividend, int divisor) {
        // 1. Be care the order of -,+ and >>, << operation, normally -,+ have higher priority
        // 2. Be care the int/long shift operation: 1<<nbits -> this is int operation, (long) 1<<nbits -> this is long operation!
        // deal with sign
        int flag=0;
        long dividend0=dividend, divisor0=divisor;
        if((dividend0>0&&divisor0<0)||
          (dividend0<0&&divisor0>0)){
            flag=1;
            if(dividend0<0)
                dividend0=0-dividend0;
            else
                divisor0=0-divisor0;
        }else if(dividend0<0&&divisor0<0){
            flag=2;
            dividend0=0-dividend0;
            divisor0=0-divisor0;
        }

        long rem=dividend0, div=divisor0, pow2=-1;
        long res=0;

        while(rem>0){           
            while(rem>=div){
                div=div<<1;
                pow2++;
            }
            if(pow2!=-1){
                res=res+((long)1<<pow2);
                rem=rem-(div>>1);
                // cout<<rem<<endl;
            }else{
                break;
            }

            div=divisor0;
            pow2=-1;
        }
        if(res>((long)INT_MAX+1))
            return INT_MAX;
        else if(flag!=1&&res==(long)((long)INT_MAX+1))
            return INT_MAX;

        if(flag==1)
            res=0-res;

        return (int)res;
    }
};
