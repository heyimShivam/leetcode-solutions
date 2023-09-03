class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        vector<unordered_map<char, int>> check_subbox(9);

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                   mp1[board[i][j]]++;
                   if(mp1[board[i][j]] == 2) return false;
                }

                if(board[j][i] != '.') {
                   mp2[board[j][i]]++;
                   if(mp2[board[j][i]] == 2) return false;
                }

                if(board[i][j] != '.') {
                    check_subbox[((i/3)*3)+(j/3)][board[i][j]]++;
                    if(check_subbox[((i/3)*3)+(j/3)][board[i][j]] == 2) {
                        cout<<board[i][j]<<" "<<i<<" j: "<<j;return false;};
                }
            }

            mp1.clear();
            mp2.clear();
        }

        return true;
    }
};