#include "push_swap.h"

void	greedy(t_stack *stack_a, t_stack *stack_b, int rank)
{
	int				a;
	int				b;

	partition_stack(stack_a, stack_b, rank);
	ascending_sort(stack_a);
	while (stack_b->count)
	{
		a = stack_a->count;
		b = stack_b->count;
		calc_min(stack_a, stack_b, &a, &b);
		rotate(stack_a, stack_b, &a, &b);
		rotate_a(stack_a, a);
		rotate_b(stack_b, b);
		pa(stack_a, stack_b);
	}
	sort_last_location(stack_a);
}

void	partition_stack(t_stack *stack_a, t_stack *stack_b, int rank)
{
	t_stack_node	*cur;
	int				i;
	int				count;
	int				pivot[2];

	pivot[0] = rank / 3;
	pivot[1] = rank / 3 * 2;
	i = 0;
	count = stack_a->count;
	while (i < count)
	{
		cur = stack_a->top->next;
		if (cur->rank > pivot[1])
			ra(stack_a);
		else if (pivot[0] < cur->rank && cur->rank <= pivot[1])
			pb(stack_a, stack_b);
		else if (cur->rank <= pivot[0])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		i++;
	}
	while (stack_a->count > 3)
		pb(stack_a, stack_b);
}

void	calc_min(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	t_stack_node	*cur;
	int				a_loc;
	int				b_loc;
	int				i;
	int				rank;

	i = 0;
	cur = stack_b->top->next;
	while (i < stack_b->count)
	{
		rank = cur->rank;
		a_loc = set_location(stack_a, rank);
		if (i >= (stack_b->count) / 2)
			b_loc = i - stack_b->count;
		else
			b_loc = i;
		if (i == 0 || compare_rotations(*a, *b, a_loc, b_loc))
		{
			*a = a_loc;
			*b = b_loc;
		}
		cur = cur->next;
		i++;
	}
}

int	set_location(t_stack *stack_a, int rank)
{
	int				count;
	int				max;

	count = 0;
	if (stack_a->top->next)
	{
		max = find_max_rank(stack_a);
		if (rank > max)
			count = get_max_count(stack_a) + 1;
		else
			count = find_min_count(stack_a, rank);
	}
	if (count >= (stack_a->count / 2))
		count = count - stack_a->count;
	return (count);
}
