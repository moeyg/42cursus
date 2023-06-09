#include "checker.h"

void	sa(t_stack *stack)
{
	t_stack_node	*cur;

	if (stack->count < 2)
		return ;
	cur = pop_top(stack);
	cur->next = stack->top->next->next;
	stack->top->next->next->prev = cur;
	cur->prev = stack->top->next;
	stack->top->next->next = cur;
	(stack->count)++;
}

void	sb(t_stack *stack)
{
	t_stack_node	*cur;

	if (stack->count < 2)
		return ;
	cur = pop_top(stack);
	cur->next = stack->top->next->next;
	stack->top->next->next->prev = cur;
	cur->prev = stack->top->next;
	stack->top->next->next = cur;
	(stack->count)++;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cur;

	if (stack_a->count < 2 || stack_a->count < 2)
		return ;
	cur = pop_top(stack_a);
	cur->next = stack_a->top->next->next;
	stack_a->top->next->next->prev = cur;
	cur->prev = stack_a->top->next;
	stack_a->top->next->next = cur;
	cur = pop_top(stack_b);
	cur->next = stack_b->top->next->next;
	stack_b->top->next->next->prev = cur;
	cur->prev = stack_b->top->next;
	stack_b->top->next->next = cur;
	(stack_a->count)++;
	(stack_b->count)++;
}
