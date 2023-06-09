#include "checker.h"

void	check_operation(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		operation(op, stack_a, stack_b);
		free(op);
	}
	if (check_sort(stack_a) && !stack_b->count)
		write(1, "OK\n", 2);
	else if (!check_sort(stack_a) || stack_b->count)
		write(1, "KO\n", 2);
	else
		write(1, "Error\n", 6);
}

void	operation(char	*op, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(op, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(op, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		print_error();
}
