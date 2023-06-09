#include "push_swap.h"

int	get_count(t_stack *stack_a, int rank, int temp)
{
	t_stack_node	*cur;
	int				count;

	count = 0;
	cur = stack_a->top->next;
	while (cur->next)
	{
		if (temp == cur->rank)
			break ;
		count++;
		cur = cur->next;
	}
	if (temp < rank)
		count++;
	return (count);
}

int	get_max_count(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				rank;
	int				count;

	count = 0;
	cur = stack_a->top->next;
	rank = find_max_rank(stack_a);
	while (cur->next)
	{
		if (rank == cur->rank)
			break ;
		count++;
		cur = cur->next;
	}
	return (count);
}
