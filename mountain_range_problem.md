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


[!for n =4](data:image/png;base64,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)