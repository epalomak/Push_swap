# Push_swap
Simple sorting algorithm using two stacks and specific predetermined operations,
which are:
- sa    swap the first 2 elements at the top of stack a
- sb    swap the first 2 elements at the top of stack b
- ss    do sa and sb
- pa    take the first element at the top of b and put it at the top of a
- pb    take the first element at the top of a and put it at the top of b
- ra    shift up all elements of stack a by 1
- rb    shift up all elements of stack b by 1
- rr    do ra and rb
- rra   shift down all elements of stack a by 1
- rrb   shift down all elements of stack b by 1
- rrr   do rra and rrb
