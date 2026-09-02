/* Integer to Roman
Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 
Constraints:

1 <= num <= 3999
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string result;

        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

/*
Integer to Roman — Approach

The main idea is to always take the largest Roman numeral value that can fit into the current number.

We keep the Roman values in descending order, including the special cases:

1000 → M
900 → CM
500 → D
400 → CD
100 → C
90 → XC
50 → L
40 → XL
10 → X
9 → IX
5 → V
4 → IV
1 → I

Then we go through these values from largest to smallest.

If the current number is large enough to contain a value, we add its Roman symbol to the result and subtract that value from the number.

For example, with 3749:

3749 is at least 1000 → add M, leaving 2749

2749 is at least 1000 → add M, leaving 1749

1749 is at least 1000 → add M, leaving 749

749 is at least 500 → add D, leaving 249

249 is at least 100 → add C, leaving 149

149 is at least 100 → add C, leaving 49

49 is at least 40 → add XL, leaving 9

9 is at least 9 → add IX, leaving 0

Result:

MMMDCCXLIX

The important part is including the special values like 900, 400, 90, 40, 9, and 4.

Without them, the algorithm might try to write 900 as DCCCC, which isn't the correct Roman numeral. By putting 900 → CM in the list, the algorithm automatically chooses the correct form.

The while loop is used because some symbols can be used multiple times.

For example, with 3000:

1000 fits → add M
1000 fits → add M
1000 fits → add M

Giving:

MMM

So the overall approach is:

Start with the largest possible Roman value → add its symbol while it fits → subtract it from the number → move down through the values.

Because the values are already ordered from largest to smallest, this naturally produces the correct Roman numeral.

Time: O(1), because there are always only 13 Roman values to check, and the input is limited to 3999.

Space: O(1) extra space, ignoring the output string.
*/
