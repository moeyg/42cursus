#include "push_swap.h"

void	ascending_sort(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				arr[3];
	int				i;

	i = 0;
	cur = stack_a->top->next;
	while (cur->next)
	{
		arr[i] = cur->num;
		i++;
		cur = cur->next;
	}
	if (i == 1)
		return ;
	else if (i == 2)
		sort_two(stack_a, arr);
	else
		sort_three(stack_a, arr);
}

void	sort_two(t_stack *stack_a, int *arr)
{
	if (abs(arr[1]) < abs(arr[2]))
		sa(stack_a);
	else if (abs(arr[2]) > abs(arr[1]))
		return ;
}

void	sort_three(t_stack *stack_a, int *arr)
{
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return ;
	else if (arr[1] < arr[0] && arr[0] < arr[2])
		sa(stack_a);
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		rra(stack_a);
	else if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (arr[1] < arr[2] && arr[2] < arr[0])
	{
		ra(stack_a);
	}
}

void	sort_last_location(t_stack *stack_a)
{
	t_stack_node	*cur;
	int				count;

	count = 0;
	cur = stack_a->top->next;
	while (cur->next)
	{
		if (count != 0 && cur->rank == 1)
			break ;
		count++;
		cur = cur->next;
	}
	if (count > (stack_a->count) / 2)
		count = count - stack_a->count;
	rotate_a(stack_a, count);
}
