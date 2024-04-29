# Mountain Range Problem

## Problem Description

Given an integer \( n \), representing the number of mountains, the task is to find the number of valid mountain ranges that can be formed with \( n \) mountains. A mountain range is valid if it satisfies the following conditions:

1. Each mountain must be of height 1 or greater.
2. The heights of the mountains must form a mountain range.
3. The mountain range begins with a mountain of height 1 and ends with a mountain of height 1.

## Examples

### Example 1 (n = 0):

Input: \( n = 0 \)

Output: \( 1 \)

Explanation: Since there are no mountains, the only valid mountain range is an empty one.

### Example 2 (n = 1):

Input: \( n = 1 \)

Output: \( 1 \)

Explanation: With only one mountain of height 1, the mountain range is already formed.

### Example 3 (n = 2):

Input: \( n = 2 \)

Output: \( 1 \)

Explanation: The only valid mountain range for 2 mountains is \( [1, 1] \).

### Example 4 (n = 3):

Input: \( n = 3 \)

Output: \( 2 \)

Explanation: Valid mountain ranges are \( [1, 2, 1] \) and \( [1, 1, 1] \).

## Relation to Catalan Numbers and Parenthesis Matching

The Mountain Range Problem is closely related to Catalan numbers and the parenthesis matching problem. The number of valid mountain ranges for \( n \) mountains is equal to the \( n \)th Catalan number.

Catalan numbers represent the number of different ways \( n \) pairs of parentheses can be matched, which is akin to the structure of a valid mountain range. Each opening parenthesis corresponds to the beginning of a mountain, and each closing parenthesis corresponds to the end of a mountain. The number of ways to match these parentheses is the same as the number of valid mountain ranges for \( n \) mountains.

Thus, solving the Mountain Range Problem is essentially equivalent to finding the \( n \)th Catalan number.

## Parenthesis Matching Problem

### Example 1 (n = 0):

Input: \( n = 0 \)

Output: \( 1 \)

Explanation: Since there are no parentheses, the only valid arrangement is an empty one.

### Example 2 (n = 1):

Input: \( n = 1 \)

Output: \( 1 \)

Explanation: With only one pair of parentheses, they are already matched.

### Example 3 (n = 2):

Input: \( n = 2 \)

Output: \( 2 \)

Explanation: Valid arrangements are \( ()() \) and \( (()) \).

### Example 4 (n = 3):

Input: \( n = 3 \)

Output: \( 5 \)

Explanation: Valid arrangements are \( ()()(), (())(), ()(()), (()()), ((())) \).


![Mountain Ranges](https://media.geeksforgeeks.org/wp-content/uploads/Mountain_Ranges-copy.jpg)
