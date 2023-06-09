#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include "Libft/includes/libft.h"

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_stack_node
{
	int					num;
	int					rank;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				count;
}	t_stack;

/* build_stack.c */
int				build_stack(t_stack *stack, char **argv);
int				find_rank(t_stack *stack, t_stack_node *new);

/* check_operation.c */
void			check_operation(t_stack *stack_a, t_stack *stack_b);
void			operation(char	*op, t_stack *stack_a, t_stack *stack_b);

/* deque.c */
void			push_top(t_stack *stack, t_stack_node *new_node);
void			push_bottom(t_stack *stack, t_stack_node *new_node);
t_stack_node	*pop_top(t_stack *stack);
t_stack_node	*pop_bottom(t_stack *stack);

/* free_operations.c */
void			free_stack(t_stack *stack);
void			free_num(char **str);
void			print_error(void);

/* initialization_stack.c */
void			initialize_stack(t_stack *stack);
t_stack_node	*initialize_node(t_stack *stack, int num);

/* ops_push.c */
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);

/* ops_swap.c */
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack_a, t_stack *stack_b);

/* ops_rotate.c */
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack_a, t_stack *stack_b);

/* ops_reverse_rotate.c */
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack_a, t_stack *stack_b);

/* validate_stack.c */
void			validate(t_stack *stack, char *str);
int				check_numeric(char *str);
int				check_duplicate(t_stack *stack, long long num);
int				check_sort(t_stack *stack_a);

#endif
