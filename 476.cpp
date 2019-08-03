class Solution {
public:
    int findComplement(int num) {
        int i;
        int m=0,n=1;
        while(num)
        {
            i=num%2;
            m+=((i+1)%2)*n;
            n<<=1;
            num>>=1;
        }
        
        return m;    
     
    }
};
