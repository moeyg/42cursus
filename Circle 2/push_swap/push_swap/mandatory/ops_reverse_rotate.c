#include "push_swap.h"

void	rra(t_stack *stack)
{
	push_top(stack, pop_bottom(stack));
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	push_top(stack, pop_bottom(stack));
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	push_top(stack_a, pop_bottom(stack_a));
	push_top(stack_b, pop_bottom(stack_b));
	write(1, "rrr\n", 4);
}
