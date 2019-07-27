#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
                        point.push(atoi(c_str(ops[i])));
                
        }
        while(!point.empty())
        {
            m+=point.top();
            point.pop();
        }
        return m;
    }
int main() {
	int i;
	vector<int> a;
	while(std::cin >> i) {a.push_back(i);}
	i=lastStoneWeight(a);
	std::cout << i;
}

