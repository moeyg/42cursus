#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		rank;

	if (argc == 1)
		return (0);
	initialize_stack(&stack_a);
	if (!argv[1][0])
		print_error();
	rank = build_stack(&stack_a, argv);
	if (check_sort(&stack_a))
		free_stack(&stack_a);
	else if (stack_a.count <= 3)
	{
		ascending_sort(&stack_a);
		free_stack(&stack_a);
	}
	else
	{
		initialize_stack(&stack_b);
		greedy(&stack_a, &stack_b, rank);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}

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
