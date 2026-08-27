/* Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 

Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

Constraints:

n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1. */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for (int i = 0; i < image.size(); i++) {

            // Flip row i
            for (int j = 0; j < image[i].size() / 2; j++) {
                swap(image[i][j], image[i][image[i].size() - 1 - j]
                );
            }

            // Invert row i
            for (int j = 0; j < image[i].size(); j++) {
                if (image[i][j] == 0) {
                    image[i][j] = 1;
                } else {
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
};

/* Flip and Invert Image — Approach
The approach is to process the image one row at a time.
For each row, we need to do two things:
First, reverse the row. For example:
[1, 1, 0] → [0, 1, 1]
We do this by swapping the first element with the last element, the second with the second-to-last, and so on. We only need to go through half of the row because every swap handles two elements.
After reversing the row, we invert it. This means changing every 0 into a 1 and every 1 into a 0.
For example:
[0, 1, 1] → [1, 0, 0]
The code repeats these two steps for every row and modifies the original image directly.
So the overall approach is simply:
Go through each row → reverse it → invert every value → move to the next row.
There is no complicated algorithm needed because the problem directly tells us the two operations we need to perform.
Time: O(n²), because we potentially look at every element in the matrix.
Space: O(1) extra space, because we modify the existing image instead of creating another matrix. */
