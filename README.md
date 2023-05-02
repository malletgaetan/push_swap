# push_swap
sort stack using limited instructions

## Quicksort inspired algorithm

The used algorithm globally works like quicksort, with some tricks to lower the instructions using the `rr`, `rrr` and `ss` instructions.

Here is a simplified version.

### sort_and_merge
More [here](https://github.com/malletgaetan/push_swap/blob/main/srcs/common/sort_and_merge.c)

1. find instructions to sort a
2. find instructions to sort b
3. compress them using `rr`, `rrr` and `ss` instructions

### quicksort stack a
More [here](https://github.com/malletgaetan/push_swap/blob/main/srcs/common/quicksort.c)

1. if len <= 3, then b last part should be less than or equal to 3 in len, so call sort_and_merge function and return
2. push every values less than median to stack b
3. call quicksort stack a
4. call quicksort stack b

### quicksort stack b
More [here](https://github.com/malletgaetan/push_swap/blob/main/srcs/common/quicksort.c)

1. push every values more than median to stack a
2. call quicksort stack a
3. call quicksort stack b
