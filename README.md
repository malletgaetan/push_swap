# push_swap
sort stack using limited instructions

## Algorithm

quicksort inspired algorithm:

considering stack a is stack that contains all numbers by default, and stack b is empty.

1 - push all numbers from stack a to b that are less than median
2 - call quicksort on stack a again if len of quicksort a is more than 3
3 - found instructions for sorting a and b and merge those instructions
4 - call quicksort on stack b if stack a is bigger than 3
