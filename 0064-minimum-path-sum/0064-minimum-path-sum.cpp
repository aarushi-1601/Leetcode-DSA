class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> test(n,vector<int>(m,0));
        test[0][0]=grid[0][0];
        for(int i=1;i<m;i++){    
            test[0][i]=test[0][i-1]+grid[0][i];
        }
        for(int i=1;i<n;i++){       
            test[i][0]=test[i-1][0]+grid[i][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int up=test[i-1][j];
                int left=test[i][j-1];
                test[i][j]=min(up+grid[i][j],left+grid[i][j]);
            }
        }
        return test[n-1][m-1];
    }
};