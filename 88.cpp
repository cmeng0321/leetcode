/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]

solve
由于nums1中后面为0，从后向前面倒着比较，哪个大就将其放到后面应该放的位置 
当最后nums2未比较完，需放进。 
*/ 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mn = m+n-1;
        m--;
        n--;
        while(m>=0 && n>=0){
            if(nums1[m] <= nums2[n]){
                nums1[mn] = nums2[n];
                n--;
            }
            else{
                nums1[mn] = nums1[m];
                m--;
            }
            mn--;
        }
        if(n>=0){
            while(n>=0){
                nums1[mn] = nums2[n];
                n--;
                mn--;
            }
        }
        
    }
};
