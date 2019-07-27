#include <iostream>
#include <vector>
std::vector<int> distributeCandies(int candies, int num_people) {
        
    std::vector<int> people(num_people,0);
    int i=1,j=0;
    for(int i=1,j=0;candies>0;i++,j++)
    {
        people[j%num_people]+=(i<candies?i:candies);
        candies-=i;
    }
        
    return people;
}
int main()
{
	int i,j;
	std::cin >> i >> j;
	std::vector<int> s=distributeCandies(i,j);
	for(int n=0;n<s.size();n++)
	{
		std::cout << s[n]<<" " ;
	}
}

