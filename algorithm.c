#include "push_swap.h"

int		is_false_inside(t_stack *stack)
{
	int i;

	i = 0;
	while (stack[i].value == 1)
	{
		if (stack[i].markup == 0)
			return (1);
		++i;
	}
	return (0);
}

int		sa_needed(t_stack *stack, int size)
{
	t_stack *temp;
	int 	i;

	i = -1;
	temp = create_stack(stack, size);
	while (stack[++i].value == 1)
	{
		temp[i].number = stack[i].number;
		temp[i].value = stack[i].value;
		temp[i].markup = stack[i].markup;
		temp[i].index = stack[i].index;
	}
	swap(temp);
	printf("swapped temp\n");
	printf("this is my temp1\n");
	print_stack(temp, size);
	temp = markup(temp);
	printf("temp2\n");
	print_stack(temp, size);
	if(get_max_markup(temp) > get_max_markup(stack))
	{
		free(temp);
		return (1);
	}
	free(temp);	
	return (0);
}

int false_head(t_stack *stack)
{
	if(stack[0].markup == 0)
		return (1);
	return (0);
}

int	fromAtoB(t_stack *a, t_stack *b, int size)
{
	while (is_false_inside(a))
	{
		if(sa_needed(a, size))
		{
			a = sa(a);
			a = markup(a);
		}
		else if(false_head(a))
		{
			push(a, b, size);
			printf("pb\n");
		}
		else
		{
			printf("A1\n");
			print_stack(a, size);
			ra(a);
			a = ft_index(a);

			printf("A2\n");
			print_stack(a, size);

		}
	}
	return(1);
}