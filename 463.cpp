class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int x=0,y=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    x++;
                    if(j<grid[0].size()-1 && grid[i][j+1]) y++;
                    
                    if(i<grid.size()-1 && grid[i+1][j]) y++;
                }
            }
        }
        return 4*x-2*y;
    }
};
