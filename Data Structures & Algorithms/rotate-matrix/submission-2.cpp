// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         size_t n = matrix.size(), l = 0, r = n - 1;

//         while (l < r) {
//             for (size_t i = 0; i < r - 1; i++) {
//                 size_t bottom = r, top = l;
//                 // save the top left
//                 int top_left = matrix[top][l + i];

//                 // move the bottom left into the top left
//                 matrix[top][l + i] = matrix[bottom - i][l];
                
//                 // move the bottom right into bottom left
//                 matrix[bottom - i][l] = matrix[bottom][r - i];

//                 // move the top right into the bottom right
//                 matrix[bottom][r - i] = matrix[top + i][r];

//                 // move the top left to the top right
//                 matrix[top + i][r] = top_left;
//             }
//             l++;
//             r--;
//         }
//     }
// };
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;

        while ( l < r ) {
            for(int i = 0; i < r - l; i++) {
                int top = l;
                int bottom = r;

                //save the topleft
                int topLeft = matrix[top][l + i];

                //move bottom left into top left
                matrix[top][l + i] = matrix[bottom - i][l];

                // move bottom right into bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // move top right into bottom right
                matrix[bottom][r - i] = matrix[top + i][r];

                // move top left into top right
                matrix[top + i][r] = topLeft;

            }
            r--;
            l++;
        }
    }
};
