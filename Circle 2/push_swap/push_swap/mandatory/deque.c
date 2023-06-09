#include "push_swap.h"

void	push_top(t_stack *stack, t_stack_node *new_node)
{
	new_node->next = stack->top->next;
	stack->top->next->prev = new_node;
	new_node->prev = stack->top;
	stack->top->next = new_node;
	(stack->count)++;
}

void	push_bottom(t_stack *stack, t_stack_node *new_node)
{
	new_node->prev = stack->bottom->prev;
	stack->bottom->prev->next = new_node;
	new_node->next = stack->bottom;
	stack->bottom->prev = new_node;
	(stack->count)++;
}

t_stack_node	*pop_top(t_stack *stack)
{
	t_stack_node	*cur;

	cur = stack->top->next;
	if (cur)
	{
		stack->top->next = cur->next;
		cur->next->prev = stack->top;
		(stack->count)--;
		return (cur);
	}
	else
		return (NULL);
}

t_stack_node	*pop_bottom(t_stack *stack)
{
	t_stack_node	*cur;

	cur = stack->bottom->prev;
	if (cur)
	{
		stack->bottom->prev = cur->prev;
		cur->prev->next = stack->bottom;
		(stack->count--);
		return (cur);
	}
	else
		return (NULL);
}
