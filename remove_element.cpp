/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:
=============================================================
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
    for (int i = 0; i < actualLength; i++) {
        assert nums[i] == expectedNums[i];
    }
=============================================================

If all assertions pass, then your solution will be accepted.
    
Example 1:
    
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/
    
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;

        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != val) {
                nums[write] = nums[read];
                write++;
            }
        }

        return write;
    }
};

/* Remove Element — Approach
The approach is to go through the array and keep only the elements that are not equal to val.
We use two positions:
read looks through every element in the array.
write keeps track of where the next valid element should be placed.
When read finds an element that is not val, we copy it to the write position and move write forward.
For example:
nums = [3,2,2,3], val = 3
We look at 3 → ignore it.
We look at 2 → keep it at the beginning:
[2,2,2,3]
We look at the next 2 → keep it:
[2,2,2,3]
We look at 3 → ignore it.
At the end, write is 2, meaning the first 2 elements are the ones we want:
[2,2,_,_]
We don't actually need to remove anything from the array or change its size. We simply overwrite the beginning of the array with the elements we want to keep.
The important idea is that read searches through the array, while write builds the new valid part of the array.
The value of write is also the answer because it tells us how many elements were not equal to val.
Time: O(n), because we go through the array once.
Space: O(1), because we modify the original array and don't create another array. */
