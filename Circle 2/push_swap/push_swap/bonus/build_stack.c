#include "checker.h"

int	build_stack(t_stack *stack, char **argv)
{
	t_stack_node	*cur;
	int				i;
	int				rank;

	i = 1;
	rank = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			print_error();
		else
			validate(stack, argv[i]);
		i++;
	}
	cur = stack->top->next;
	while (cur->next)
	{
		if (rank <= cur->rank)
			rank = cur->rank;
		cur = cur->next;
	}
	return (rank);
}

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
