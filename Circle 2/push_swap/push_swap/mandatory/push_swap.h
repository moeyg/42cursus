#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

/* compare_rotation.c */
int				compare_rotations(int a, int b, int a_loc, int b_loc);
int				absolute_value(int num);

/* deque.c */
void			push_top(t_stack *stack, t_stack_node *new_node);
void			push_bottom(t_stack *stack, t_stack_node *new_node);
t_stack_node	*pop_top(t_stack *stack);
t_stack_node	*pop_bottom(t_stack *stack);

/* find_operations.c */
int				find_rank(t_stack *stack, t_stack_node *new);
int				find_max_rank(t_stack *stack_a);
int				find_min_count(t_stack *stack_a, int rank);

/* free_operations.c */
void			free_stack(t_stack *stack);
void			free_num(char **str);
void			print_error(void);

/* get_operations.c */
int				get_count(t_stack *stack_a, int rank, int temp);
int				get_max_count(t_stack *stack_a);

/* greedy.c */
void			greedy(t_stack *stack_a, t_stack *stack_b, int rank);
void			partition_stack(t_stack *stack_a, t_stack *stack_b, int rank);
void			calc_min(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
int				set_location(t_stack *stack_a, int rank);

/* initialization_operations */
void			initialize_stack(t_stack *stack);
t_stack_node	*initialize_node(t_stack *stack, int num);

/* main.c */
int				build_stack(t_stack *stack, char **argv);

/* op_push.c */
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);

/* op_swap.c */
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack_a, t_stack *stack_b);

/* op_rotate.c */
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack_a, t_stack *stack_b);

/* op_reverse_rotate.c */
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack_a, t_stack *stack_b);

/* rotate.c */
void			rotate(t_stack *stack_a, t_stack *stack_b, int *a, int *b);
void			rotate_a(t_stack *stack_a, int a);
void			rotate_b(t_stack *stack_b, int b);

/* sort_operations.c */
void			ascending_sort(t_stack *stack_a);
void			sort_two(t_stack *stack_a, int *arr);
void			sort_three(t_stack *stack_a, int *arr);
void			sort_last_location(t_stack *stack_a);

/* validate_stack.c */
void			validate(t_stack *stack, char *str);
int				check_numeric(char *str);
int				check_duplicate(t_stack *stack, long long num);
int				check_sort(t_stack *stack_a);

#endif
