#include "checker.h"

void	ra(t_stack *stack)
{
	if (stack->count)
		push_bottom(stack, pop_top(stack));
}

void	rb(t_stack *stack)
{
	if (stack->count)
		push_bottom(stack, pop_top(stack));
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count && stack_b->count)
	{
		push_bottom(stack_a, pop_top(stack_a));
		push_bottom(stack_b, pop_top(stack_b));
	}
}
