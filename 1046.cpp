#include <iostream>
#include <vector>
#include <set>

using std::vector;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int lastStoneWeight(vector<int>& stones) {
   int m1,m2;
    std::multiset<int> stone(stones.begin(),stones.end());
    while(stone.size()>1)
    {
        m1=*(--stone.end());
        stone.erase(stone.find(m1));
        m2=*stone.rbegin();
        stone.erase(stone.find(m2));
        if(m1!=m2) stone.insert(m1-m2);
    }
    return stone.empty() ? 0 : *stone.begin();
}
int main(int argc, char** argv) {
	int i;
	vector<int> a;
	while(std::cin >> i) {a.push_back(i);}
	i=lastStoneWeight(a);
	std::cout << i << std::endl;
	return 0;
}

