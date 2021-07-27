#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	number;
	int	index;
	int	value;
	int	markup;
}				t_stack;

t_stack		*arr_to_stack(char **naxnakan, t_stack *a, int len);
char		**argv_parser(char **naxnakan, char **massiv, int elements);
void		no_duplicates(t_stack *a, int len);
t_stack		*parser(int argc, char **argv);

int			naxnakan_count(char **naxnakan);
void		error(char *message);
int			elem_count(char *argv);
void		print_stack(t_stack *stack, int size);
t_stack		*create_stack(t_stack *stack, int i);
int			stack_size(t_stack *stack);
int			is_sorted (t_stack *stack);

void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		push(t_stack *from, t_stack *to, int size);

t_stack		*sa(t_stack *a);
t_stack		*ra(t_stack *a);

t_stack		*ft_index(t_stack *stack);
int			get_min(t_stack *stack);
t_stack		*markup(t_stack *stack);
int 		get_markup_length(t_stack *stack, int i);
int			get_max_markup(t_stack *stack);
t_stack		*set_markup(t_stack *stack, int head, int max);

int			is_false_inside(t_stack *stack);
int			fromAtoB(t_stack *a, t_stack *b, int size);
int			sa_needed(t_stack *stack, int size);

#endif