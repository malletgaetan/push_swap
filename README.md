# push_swap
sort stack using limited instructions

## Algorithm

quicksort inspired algorithm:

considering stack a is stack that contains all numbers by default, and stack b is empty.

- push all numbers from stack a to b that are less than median
- call quicksort on stack a again if len of quicksort a is more than 3
- find instructions for sorting a and b, merge those instructions together and execute on stacks
- call quicksort on stack b if stack a is bigger than 3
