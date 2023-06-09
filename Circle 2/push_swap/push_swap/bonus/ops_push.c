#include "checker.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->count)
		push_top(stack_a, pop_top(stack_b));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count)
		push_top(stack_b, pop_top(stack_a));
}
