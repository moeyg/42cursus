#include "push_swap.h"

void	validate(t_stack *stack, char *str)
{
	char	**split_str;
	int		i;

	i = 0;
	split_str = ft_split(str, ' ');
	if (!split_str || !*split_str)
		print_error();
	while (split_str[i])
	{
		if (!check_numeric(split_str[i]) || ft_strlen(split_str[i]) > 12)
			print_error();
		if (ft_atoi(split_str[i]) > MAX || ft_atoi(split_str[i]) < MIN)
			print_error();
		if (!check_duplicate(stack, ft_atoi(split_str[i])))
			print_error();
		push_bottom(stack, initialize_node(stack, ft_atoi(split_str[i])));
		i++;
	}
	free_num(split_str);
}

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_duplicate(t_stack *stack, long long num)
{
	t_stack_node	*cur;

	cur = stack->top->next;
	if (num == 0)
	{
		while (cur->next)
		{
			if (cur->num == 0)
				return (0);
			else
				cur = cur->next;
		}
		return (1);
	}
	cur = stack->top->next;
	while (cur->next)
	{
		if (cur->num == num)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	check_sort(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				rank;
	int				i;

	i = 1;
	cur = stack_a->top->next->next;
	rank = stack_a->top->next->rank;
	while (i < stack_a->count)
	{
		if (rank > cur->rank)
			return (0);
		rank = cur->rank;
		cur = cur->next;
		i++;
	}
	return (1);
}
