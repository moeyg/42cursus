#include "checker.h"

void	initialize_stack(t_stack *stack)
{
	stack->top = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!stack->top)
		print_error();
	stack->bottom = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!stack->bottom)
		print_error();
	stack->top->prev = NULL;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->bottom->next = NULL;
	stack->count = 0;
}

t_stack_node	*initialize_node(t_stack *stack, int num)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		print_error();
	new->next = NULL;
	new->prev = NULL;
	new->num = num;
	new->rank = find_rank(stack, new);
	return (new);
}
