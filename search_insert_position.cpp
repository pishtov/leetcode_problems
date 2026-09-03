/*-Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
-You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

/* Search Insert Position — Approach
The approach is to use binary search because the array is already sorted.
We keep track of the part of the array we are currently searching using two variables:
left starts at the beginning of the array, and right starts at the end.
Then, we check the middle element of the current search area.
If the middle element is smaller than the target, we know that everything before it is also smaller than the target because the array is sorted. So we can ignore that entire left side and move left to the element after the middle.
If the middle element is greater than or equal to the target, we know that everything after it is also greater than the target. So we can ignore that right side and move right to the element before the middle.
We keep repeating this until there are no elements left to search.
At that point, left represents the position where the target should be inserted. This also works when the target already exists in the array, because left will end up at its index.
So the overall approach is simply:
Start with the entire array → check the middle → ignore the half that cannot contain the answer → repeat → return left as the insertion position.
Time: O(log n), because we remove roughly half of the remaining search area after each comparison.
Space: O(1) extra space, because we only use a few variables and do not create another array. */
