class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int n=1;
        int m=0;
        vector<int> v;
        
        for(auto s : S)
        {
            
            m+=widths[s-'a'];
            if(m>100) 
            {
                ++n;
                m=widths[s-'a'];
            }
        }
        
        v.push_back(n);
        v.push_back(m);
        return v;
    }
};
