/* Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:
 
Constraints:

0 <= num <= 106 */

class Solution {
public:
    int numberOfSteps(int num) {
    int steps = 0;
while (num != 0){
    if (num % 2 == 0) {
        num = num / 2;
    } else {
        num = num -1;
    }
    steps = steps + 1;
}
return steps;
    }
};

/* Number of Steps to Reduce a Number to Zero — Approach
The approach is to simply follow the rules given by the problem until the number becomes 0.
We keep the current number in num and count how many operations we perform.
For every step, we check whether the number is even or odd.
If it is even, we divide it by 2.
If it is odd, we subtract 1.
After performing the operation, we increase steps by 1.
We repeat this until num becomes 0.
For example, with 14:
14 → 7 → 6 → 3 → 2 → 1 → 0
Each arrow represents one step, so the answer is 6.
The important part is that we don't need to calculate anything in advance. We just simulate exactly what the problem tells us to do.
The while (num != 0) loop makes sure we keep going until we reach 0.
Time: O(log n), because dividing an even number by 2 quickly makes the number smaller. The odd numbers only require a subtraction before the next division.
Space: O(1), because we only use the num and steps variables. */
