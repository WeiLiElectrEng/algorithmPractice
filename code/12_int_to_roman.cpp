class Solution {
public:
    string intToRoman(int num) {
        // string roma_digi="IVXLCDM";
        string res;
        int cur_digi=0;
        // roma number
        
        // thousand, as below 4000
        cur_digi=num/1000;
        for(int i=0;i<cur_digi;i++){
            res=res+"M";
        }
        num=num-cur_digi*1000;
        
        //hundred
        cur_digi=num/100;
        if(cur_digi==9){
            res=res+"CM";
        }else if(cur_digi>=5&&cur_digi<=8){
            res=res+"D";
             for(int i=5;i<cur_digi;i++){
                 res=res+"C";
             }
        }else if(cur_digi==4){
            res=res+"CD";
        }else if(cur_digi>0&&cur_digi<4){
             for(int i=0;i<cur_digi;i++){
                 res=res+"C";
             }
        }
        num=num-cur_digi*100;
        
        // Ten
        cur_digi=num/10;
        if(cur_digi==9){
            res=res+"XC";
        }else if(cur_digi>=5&&cur_digi<=8){
            res=res+"L";
            for(int i=5;i<cur_digi;i++){
                res=res+"X";
            }
        }else if(cur_digi==4){
            res=res+"XL";
        }else if(cur_digi>0&&cur_digi<4){
            for(int i=0;i<cur_digi;i++){
                res=res+"X";
            }
        }
        num=num-cur_digi*10;
        
        cur_digi=num;
        // ones
        if(cur_digi==9){
            res=res+"IX";
        }else if(cur_digi>=5&&cur_digi<=8){
            res=res+"V";
            for(int i=5;i<cur_digi;i++){
                res=res+"I";
            }
        }else if(cur_digi==4){
            res=res+"IV";
        }else if(cur_digi>0){
            for(int i=0;i<cur_digi;i++){
                res=res+"I";
            }
        }
        
        return res;
    }
};
