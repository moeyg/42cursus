#include "push_swap.h"

// rotate
void	rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		rr(stack_a, stack_b);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		rrr(stack_a, stack_b);
		(*a)++;
		(*b)++;
	}
}

void	rotate_a(t_stack *stack_a, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stack_a);
			a--;
		}
		else
		{
			rra(stack_a);
			a++;
		}
	}
}

void	rotate_b(t_stack *stack_b, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stack_b);
			b--;
		}
		else
		{
			rrb(stack_b);
			b++;
		}
	}
}
