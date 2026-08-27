/* Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any integer x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.

Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 
Constraints:

1 <= n <= 1000 */

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

/* Divisor Game — Approach
The key idea is to notice that the result only depends on whether n is even or odd.
If n is even, Alice can always choose x = 1. This changes the number from even to odd.
Now Bob has an odd number. Every divisor of an odd number is also odd. So no matter which divisor Bob chooses, he subtracts an odd number from an odd number, resulting in an even number.
This means Alice gets an even number again.
Alice can keep using x = 1, turning even numbers into odd numbers and forcing Bob to turn them back into even numbers.
Eventually Bob gets 1. There is no number x where 0 < x < 1, so Bob cannot move and loses.
Therefore, if n is even, Alice wins.
If n is odd, Alice has no way to keep the number odd. Every divisor of an odd number is odd, so whatever Alice chooses, she subtracts an odd number from an odd number and gives Bob an even number.
Since an even number is a winning position, Bob can use the same strategy and eventually make Alice lose.
So the final observation is:
Even n → Alice wins
Odd n → Alice loses
That's why the solution only needs:
return n % 2 == 0;
There is no need to actually play the game or find any divisors. The important part is recognizing the even/odd pattern. */
