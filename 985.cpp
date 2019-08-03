class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> B;
        int m=0;
        for(int a : A)
        {
            if(a%2==0) m+=a;
        }
        for(auto q : queries)
        {
            
            if(A[q[1]]%2==0) m-=A[q[1]];
            int m1;
            if((m1=A[q[1]]+q[0])%2==0) m+=m1;
            A[q[1]]=m1;
            B.push_back(m);

        }
        return B;
    }
};
