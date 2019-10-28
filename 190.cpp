/*Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

Example 1:
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
so return 964176192 which its binary representation is 00111001011110000010100101000000.*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i;
        int m;
        uint32_t N = 0;
        
        for(i = 0; i < 32; i++)
        {
            m = n % 2;
            n = n / 2;
            N = N * 2;
            N = N + m;
        }
        
        return N;
    }
};
