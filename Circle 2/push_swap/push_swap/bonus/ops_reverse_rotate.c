#include "checker.h"

void	rra(t_stack *stack)
{
	if (stack->count)
		push_top(stack, pop_bottom(stack));
}

void	rrb(t_stack *stack)
{
	if (stack->count)
		push_top(stack, pop_bottom(stack));
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count && stack_b->count)
	{
		push_top(stack_a, pop_bottom(stack_a));
		push_top(stack_b, pop_bottom(stack_b));
	}
}
