#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_top(stack_a, pop_top(stack_b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_top(stack_b, pop_top(stack_a));
	write(1, "pb\n", 3);
}
