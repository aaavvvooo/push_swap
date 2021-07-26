#include "push_swap.h"

void	error(char *message)
{
	printf("%s\n", message);
	exit(0);
}

int	naxnakan_count(char **naxnakan)
{
	int	i;

	i = 0;
	while (naxnakan[i])
		++i;
	return (i);
}

void	print_stack(t_stack *stack, int size)
{
	int	i;

	i = -1;
	while(++i < size)
		printf("to[%d].number is -> %d, value is -> %d, index is -> %d, markup is -> %d\n", 
				i, stack[i].number, stack[i].value, stack[i].index, stack[i].markup);
	printf("\n");
}

t_stack	*create_stack(t_stack *stack, int i)
{
	stack = (t_stack *)malloc (sizeof(t_stack ) * (i + 1));
	if (!stack)
		return (NULL);
	return (stack); 
}

int	stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while(stack[i].value == 1)
 		++i;
	return (i);
}
