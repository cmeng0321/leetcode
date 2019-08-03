class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int n=0;
        while(!A.empty())
        {
            
            string s=A[0];
            A.erase(A.begin());
            multiset<char> s1,s2;
            for(int i=0;i<s.size();i+=2) s1.insert(s[i]);
            for(int k=1;k<s.size();k+=2) s2.insert(s[k]);
            for(int m=0;m<A.size();++m)
            {
                if(s==A[m]) {A.erase(A.begin()+m);--m;}
                else
                {
                multiset<char> s3,s4;
                for(int i=0;i<A[m].size();i+=2) s3.insert(A[m][i]);
                if(s1==s3)
                {
                    for(int j=1;j<A[m].size();j+=2) s4.insert(A[m][j]);
                    if(s2==s4) {A.erase(A.begin()+m);--m;}
                }
                else continue;
                }
            }
            ++n;
            
        }
        return n;
    }
};
