class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r=matrix.size();
        int c=matrix[0].size();

        int count=0;
        int total=r*c;

        // index initialisation
        int sc=0;
        int sr=0;
        int er=r-1;
        int ec=c-1;

        while(count<total){
            // print starting row
            for(int i=sc;count<total&&i<=ec;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;

             // print ending column
            for(int i=sr;count<total&&i<=er;i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
             // print ending row
            for(int i=ec;count<total&&i>=sc;i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
             // print starting column
            for(int i=er;count<total&&i>=sr;i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;
    }
};