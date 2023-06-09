#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack_node	*cur;

	while (stack->count)
	{
		cur = pop_bottom(stack);
		free(cur);
	}
	free(stack->top);
	free(stack->bottom);
}

void	free_num(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
