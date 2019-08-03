class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> word;
        if(words.empty()) return words;
        string s1= "qwertyuiop";
        string s2= "asdfghjkl";
        string s3= "zxcvbnm";

        multiset<char> m1,m2,m3;
        for(int i=0;i<10;i++) m1.insert(s1[i]);
        for(int i=0;i<9;i++) m2.insert(s2[i]);
        for(int i=0;i<7;i++) m3.insert(s3[i]);
            
        for(int i=0;i<words.size();i++)
        { 
            char w;
            if (words[i][0] >='A'&&words[i][0]<='Z') w=words[i][0] +' ';
            else w=words[i][0];
            if(m1.count(w) != 0)
            {
                int flag=1;
                for(int j=1;j<words[i].length();j++)
                {
                    if (words[i][j] >='A'&&words[i][j]<='Z') w=words[i][j] + ' ';
                    else w=words[i][j];
                    if(m1.count(w) == 0) flag=0;
                    if(flag==0) break;
                }
                if(flag==1) word.push_back(words[i]);
            }
            else
                if(m2.count(w) != 0)
                {
                    int flag=1;
                    for(int j=1;j<words[i].length();j++)
                    {
                        if (words[i][j] >='A'&&words[i][j]<='Z') w=words[i][j] + ' ';
                        else w=words[i][j];
                        if(m2.count(w) == 0) flag=0;
                        if(flag==0) break;
                    }
                    if(flag==1) word.push_back(words[i]);
                }
                else
                    if(m3.count(w) != 0)
                    {
                        int flag=1;
                        for(int j=1;j<words[i].length();j++)
                        {
                            if (words[i][j] >='A' && words[i][j]<='Z') w=words[i][j] +' ';
                            else w=words[i][j];
                            if(m3.count(w) == 0) flag=0;
                            if(flag==0) break;
                        }
                        if(flag==1) word.push_back(words[i]);
                    }
                    
        }
        /*
        string s1= "qwertyuiopQWERTYUIOP";
        string s2= "asdfghjklASDFGHJKL";
        string s3= "zxcvbnmZXCVBNM";

        multiset<char> m1,m2,m3;
        for(int i=0;i<20;i++) m1.insert(s1[i]);
        for(int i=0;i<18;i++) m2.insert(s2[i]);
        for(int i=0;i<14;i++) m3.insert(s3[i]);
            
        for(int i=0;i<words.size();i++)
        { 
            multiset<char> m;
            if(m1.count(words[i][0]) != 0) m=m1;
            else
                if(m2.count(words[i][0]) != 0) m=m2;
                else
                    if(m3.count(words[i][0]) != 0) m=m3;
            
            int flag=1;
            for(int j=1;j<words[i].length();j++)
            {
                if(m.count(words[i][j]) == 0) flag=0;
                if(flag==0) break;
            }
                
            if(flag==1) word.push_back(words[i]);      
        }
		*/ 
        return word;
    }
};
