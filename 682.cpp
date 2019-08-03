class Solution {
public:
    int calPoints(vector<string>& ops) {
        int m=0;
        stack<int> point;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="+") 
            {
                int s1=point.top();
                point.pop();
                int s2=point.top();
                point.push(s1);
                point.push(s1+s2);
            }
            
            else if(ops[i]=="D")  point.push(point.top()*2);
                
                else if(ops[i]=="C") point.pop();
                       
                    else 
                        point.push(stoi(ops[i]));
                
        }
        while(!point.empty())
        {
            m+=point.top();
            point.pop();
        }
        return m;
    }
};

