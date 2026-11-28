class Solution {
public:
    bool canBeConstructed = false;

    void dfs(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0 || board[row][col] != word[index]) return;
        if (index == word.size() - 1) {
            canBeConstructed = true;
            return;
        }

        index++;
        board[row][col] = '-'; // mark it as visited

        dfs(board, word, row + 1, col, index);
        dfs(board, word, row - 1, col, index);
        dfs(board, word, row, col + 1, index);
        dfs(board, word, row, col - 1, index);

        board[row][col] = word[index - 1]; // put the letter back
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) dfs(board, word, i, j, 0);
            }
        }

        return canBeConstructed;
    }
};
