/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:

-231 <= x <= 231 - 1

Follow up: Could you solve it without converting the integer to a string?
*/

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }
        
        int original = x;
        long int new_number = 0;

        while (x > 0) {
            int digit = x % 10;
            new_number = new_number * 10 + digit;
            x = x / 10;
        }
        return original == new_number;
    }
};

/* Palindrome Number — Approach
The approach is to reverse the number and then compare it with the original number.
First, we save the original number because we are going to change x while reversing it.
If x is negative, we immediately return false. A negative number cannot be a palindrome because of the - sign.
To reverse the number, we repeatedly take its last digit using % 10.
For example, with 123:
123 → take 3
12 → take 2
1 → take 1
We then build the reversed number:
3 → 32 → 321
Once we have the reversed number, we compare it with the original.
If they are the same, the number reads the same forwards and backwards, so it is a palindrome.
For example:
121 → reversed is 121 → true
123 → reversed is 321 → false
The important idea is that we don't need to convert the number to a string. We can reverse the number mathematically by repeatedly taking its last digit and removing that digit.
Time: O(log n), because we process each digit of the number once.
Space: O(1), because we only use a few variables. */
