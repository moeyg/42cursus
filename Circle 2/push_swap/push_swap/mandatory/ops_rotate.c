#include "push_swap.h"

void	ra(t_stack *stack)
{
	push_bottom(stack, pop_top(stack));
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	push_bottom(stack, pop_top(stack));
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	push_bottom(stack_a, pop_top(stack_a));
	push_bottom(stack_b, pop_top(stack_b));
	write(1, "rr\n", 3);
}
