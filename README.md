# Push_Swap

Rules :

There are 2 stacks : a and b.

	a has an arbitrary number of positive/negative integer without duplicates.
	
	b is empty.
	
The goal is to sort in ascending order.

We are able to do those operations on the stacks :

	sa : swap a - Swap the two first element of stack a. Do nothing if there is only one element or none.
	sb : swap b - Swap the two first element of stack b. Do nothing if there is only one element or none.
	ss : sa and sb simultaneously.
	pa : push a - Put the first element of b on top of a. Do nothing if b is empty.
	pb : push b - Put the first element of a on top of b. Do nothing if b is empty.
	ra : rotate a - First element of a becomes last, the second first etc ...
	rb : rotate b - First element of b becomes last, the second first etc ...
	rr : ra and rb simultaneously.
	rra : reverse rotate a - Last element of a becomes first, etc ...
	rrb : reverse rotate b - Last element of b becomes first, etc ...
	rrr : rra and rrb simultaneously.

# Usage

```ARG=`ruby -e "puts ([from]..[to]).to_a.shuffle.join(' ')"`| ./push_swap $ARG | ./checker [-v] $ARG```
