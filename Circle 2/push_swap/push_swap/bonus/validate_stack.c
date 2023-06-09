#include "checker.h"

void	validate(t_stack *stack, char *str)
{
	char	**stack_nums;
	int		i;

	i = 0;
	stack_nums = ft_split(str, ' ');
	if (!stack_nums || !*stack_nums)
		print_error();
	while (stack_nums[i])
	{
		if (!check_numeric(stack_nums[i]) || ft_strlen(stack_nums[i]) > 13)
			print_error();
		if (ft_atoi(stack_nums[i]) > MAX || ft_atoi(stack_nums[i]) < MIN)
			print_error();
		if (!check_duplicate(stack, ft_atoi(stack_nums[i])))
			print_error();
		push_bottom(stack, initialize_node(stack, ft_atoi(stack_nums[i])));
		i++;
	}
	free_num(stack_nums);
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
