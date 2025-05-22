class Solution {
public:
    void setColumn(vector<vector<int>>& matrix, int col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //matrix[i][0]==0 will denotes the row i will be zeroed
        //matrix[0][i]==0 denotes the column i will be zeroed
        //so first row and first column are representatives basically, the only exceptrion is matrix[0][0]
        //so we need to fill that one first by checking both first row and first column and then setting 
        //thus allowing us to modify 1st column and row
        //Overall and A+ implementation problem
        bool row=false;
        bool col=false;
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                row=true;
            }
        }

        for(int j=0;j<n;j++){
            if(matrix[j][0]==0){
                col=true;
            }
        }

        //setting row representatives
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                }
            }
        }

        //setting column representatives
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[j][i]==0){
                    matrix[0][i]=0;
                }
            }
        }
        //usign the representatives
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }


        for(int i=1;i<m;i++){
            if(matrix[0][i]==0){
                for(int j=0;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }

        //now using the variables to set first row and first column
        if(row){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }

        if(col){
            for(int j=0;j<n;j++){
                matrix[j][0]=0;
            }
        }


        
    }
};