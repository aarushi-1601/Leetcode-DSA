class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n= matrix.size();
        int m=matrix[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    for(int j=0; j<m;j++){
                        if(matrix[i][j]!=0){
                            matrix[i][j]=-99999;
                        }
                    }
                    for(int i=0;i<n;i++){
                        if(matrix[i][j]!=0){
                            matrix[i][j]=-99999;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-99999){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
        
    