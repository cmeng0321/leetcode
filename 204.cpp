/*
204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
 
Constraints:
0 <= n <= 5 * 106

solve
挨个进入素数判断函数， Time Linit Exceeded
部分进入素数判断函数，可取，时间过长 
或者不调用判断素数的函数，直接写入countPrimes函数中 

使用一个vector,将非素数置为false, 
*/ 

class Solution {
public:
    bool isprime(int m){
        for(int i = 2; i <= sqrt(m); ++i){
            if(m % i == 0) return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        int num = 0;
        int i = 2;
        while(i < n){
            if(i != 2 && i != 3 && i != 5 && i != 7){
                if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0){
                    ++i;
                    continue;
                }
                
                else if(isprime(i)) ++num;
                ++i;
            }
            else if(isprime(i)) ++num;
            ++i;
        }
        return num;
    }
    int countPrimes(int n) {
        int num = 0;
        int i = 2;
        while(i < n){
            int flag = 1;
            for(int j = 2; j <= sqrt(i); ++j){
                if(i % j == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) ++num;
            ++i;
        }
        return num;
    }
	
    int countPrimes(int n) {
        int num = 0;
        vector<bool> prime(n, true);
        
        int i = 2;
        for(int i = 2; i < n; ++i){//num的递加在循环内，到n   ，也可到sqrt(n),去掉循环中的++num，之后在计算从prime[2]开始的true 
            if (!prime[i]) continue;  
            ++num;
            for (int j = 2; i * j < n; ++j) {
                prime[i * j] = false;
            }
        }
        return num;
    }
    int countPrimes(int n) {
        //if(n == 0 || n == 1) return 0;
        int num = 0;
        vector<bool> prime(n, true);
        
        int i = 2;
        for(int i = 2; i < sqrt(n); ++i){
            if (!prime[i]) continue;
            for (int j = 2; i * j < n; ++j) {//剔除所有成倍的元素
                prime[i * j] = false;
            }
        }
        
        for(int i = 2; i < n; ++i){
            if(prime[i]) ++num;
        }
        return num;
    }    
	
	int countPrimes(int n) {
		if(n == 0 || n == 1) return 0;
        int num = 0;
        vector<bool> prime(n, true);

        prime[0] = false, prime[1] = false;


        for (int i = 2; i < sqrt(n); i++)//素数判断范围到开方即可
        {
            if (prime[i])
            {
                for (int j = i; j * i < n; j++)
                {
                    prime[j*i] = false;
                }
            }
        }

        for (int i =0;i<n;i++)
            if(prime[i])
                num++;
        return num;
    }		    
};
