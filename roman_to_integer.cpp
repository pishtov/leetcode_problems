/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999]. */

class Solution {
public:
    int romanToInt(string s) {
        // Helper func: convert one Roman char to its number
        auto value = [](char c) {
            if (c == 'I') return 1;
            if (c == 'V') return 5;
            if (c == 'X') return 10;
            if (c == 'L') return 50;
            if (c == 'C') return 100;
            if (c == 'D') return 500;
            return 1000; // M (if it's not the above, it must me M)
        };
        
        // This will store the final number
        int result = 0;
        
        // Go through every char in the string
        for (int i = 0; i < s.size(); i++) {
            // Get value of current Roman char
            int current = value(s[i]);

            // If current value is smaller than the next one, subtract it. (Ex. IV means -1 + 5)
            if (i + 1 < s.size() && current < value(s[i + 1])) {
                result -= current;
            } else {
                // Otherwise add it
                result += current;
            }
        }
        // Return final int value
        return result;
    }
};

/* Roman to Integer — Approach
The approach is to go through the Roman numeral from left to right and add the value of each symbol.
The only special case is when a smaller value comes before a larger value. In that situation, we subtract the smaller value instead of adding it.
For example:
VI → 5 + 1 = 6
But:
IV → -1 + 5 = 4
So for every character, we look at the character immediately after it.
If the current value is smaller than the next value, we subtract the current value.
Otherwise, we add it.
For example, with:
MCMXCIV
We process it like this:
M → 1000, add it
C before M → 100 is smaller than 1000, so subtract it
M → 1000, add it
X before C → subtract 10
C → add 100
I before V → subtract 1
V → add 5
So we get:
1000 - 100 + 1000 - 10 + 100 - 1 + 5 = 1994
The important idea is that we don't need to specifically check for IV, IX, XL, XC, CD, or CM. Instead, we use one general rule:
If the current number is smaller than the next number → subtract it.
Otherwise → add it.
The value function is simply used to convert each Roman symbol into its numerical value.
Time: O(n), because we go through the string once.
Space: O(1), because we only use a few variables and don't create anything based on the size of the input. */
