/* Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself. */

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i] - '0';

            if (j >= 0)
                sum += b[j] - '0';

            result += (sum % 2) + '0';
            carry = sum / 2;

            i--;
            j--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

/* Add Binary — Approach
The approach is to add the two binary strings manually, digit by digit, starting from the right, just like normal addition.
We start at the last digit of both strings because addition is performed from right to left.
For example:
1010
1011
-----
10101
We keep three things:
i = current position in a
j = current position in b
carry = the value carried from the previous addition
For each position, we add:
The current digit from a, if one exists.
The current digit from b, if one exists.
The current carry.
For example, if we have:
1 + 1 + carry 1 = 3
Since this is binary, a sum of 3 means we put 1 into the current position and carry 1 to the next position.
We can get the binary digit using:
sum % 2
And we can get the carry using:
sum / 2
For example:
sum = 0 → digit 0, carry 0
sum = 1 → digit 1, carry 0
sum = 2 → digit 0, carry 1
sum = 3 → digit 1, carry 1
We continue moving i and j to the left until both strings have been completely processed and there is no carry left.
Because we process the numbers from right to left, the result is built backwards. We therefore reverse the result at the end.
The important idea is that we do NOT convert the entire binary strings into integers. The strings can contain up to 10,000 digits, which is far too large for an int or long long. Instead, we perform binary addition one digit at a time, just like doing addition on paper.
Time: O(n), because we process each digit once, where n is the length of the longer string.
Space: O(n), because we store the resulting binary string. */
