# push_swap

Sorting algorithm project with two stacks and a restricted set of
sorting instructions available of which I'm only using the following:

- pa - take the top element of stack_b and put it on top of stack_a
- pb - take the top element of stack_a and put it on top of stack_b
- ra - rotate up all elements in stack_a, the first element becomes the last
- rra - rotate down all elements in stack_a, the last element becomes the first
- sa - swap the first two elements of stack_a


The goal of push_swap is to sort any valid input list of integer numbers in the
least amount of steps possible.

The program's input is first put in stack_a, beginning at the top with the first
argument.
Example:

./push_swap 1 3 2

becomes a stack_a from top to bottom like this:

1
3
2

To sort it, we could use sa, ra:

1---------3---------1

3---sa->-1---ra->-2

2---------2---------3

In this case, we didn't even need to use stack_b as an intermediate.

If the input is 2 numbers and the list is not sorted, logically we only
need to do sa once.
For 3 input numbers we can look at the 5 (6 minus the one that's already
sorted) possible ways they can be arranged and act on each case specifically.

For 4 and 5 input numbers we can do pb once or twice respectively, sort the 3
numbers left on stack_a like we did before and then search for the spot to pa
the number(s) from stack_b into stack_a. Lastly, rotate the lowest number to
the top.

From 6 numbers on I'm using radix sort.
In the beginning I handle my input in a way that assigns every number its
corresponding ordered index from all input numbers, starting at 0.
For example the input:

33 -5 12 0

becomes:

3 0 2 1

This is done to reduce the bit size of the numbers as much as possible.
Afterwards, the program can go through stack_a once for every bit, 
starting at the rightmost one. If it's a 0, use pb. Otherwise, use ra.
Once all numbers with the bit it's looking at set to 0 are in stack_b,
use pa to push them all back to the top of stack_a.
This is repeated for every bit up to and including the leftmost bit that's
used by the input numbers.
At the end of this procedure, the list is sorted.

This way, the amount of steps needed for a specific amount of inputs
is always the same.

I can recommend taking a look at [visual representations](https://www.youtube.com/watch?v=nu4gDuFabIM) of radix sort to make things clearer.
In the case of push_swap, we're just using two boxes instead of 10.
One for 0 bits and one for 1 bits - instead of one for every base-10 digit.
The linked lists stack_a and stack_b function as the boxes.
