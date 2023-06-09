#include "push_swap.h"

int	find_rank(t_stack *stack, t_stack_node *new)
{
	t_stack_node	*cur;
	int				rank;

	rank = 0;
	cur = stack->top->next;
	while (cur->next)
	{
		if (cur->num > new->num && rank > cur->rank)
			rank = cur->rank;
		else if (cur->num < new->num && rank < cur->rank)
			rank = cur->rank;
		cur = cur->next;
	}
	if (rank == 0)
		rank++;
	cur = stack->top->next;
	while (cur->next)
	{
		if ((cur->rank == rank && cur->num > new->num) || cur->rank > rank)
			(cur->rank)++;
		else if (cur->rank == rank && cur->num < new->num)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

int	find_max_rank(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				rank;

	cur = stack_a->top->next;
	rank = 0;
	while (cur->next)
	{
		if (rank < cur->rank)
			rank = cur->rank;
		cur = cur->next;
	}
	return (rank);
}

int	find_min_count(t_stack *stack_a, int rank)
{
	t_stack_node	*cur;
	int				temp;
	int				diff;
	int				count;

	diff = MAX;
	cur = stack_a->top->next;
	while (cur->next)
	{
		if (diff > abs(cur->rank - rank))
		{
			diff = abs(cur->rank - rank);
			temp = cur->rank;
		}
		cur = cur->next;
	}
	count = get_count(stack_a, rank, temp);
	return (count);
}
