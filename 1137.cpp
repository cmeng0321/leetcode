class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else
            if(n==1) return 1;
            else
                if(n==2) return 1;
                else
                {
                    int T = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
                    return T;
                }
    }
};
