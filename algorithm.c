#include "push_swap.h"

int		is_false_inside(t_stack *stack)
{
	int i;

	i = 0;
	while (stack[i].value == 1)
	{
		if (stack[i].markup == 0)
			return (0);
		++i;
	}
	return (1);
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
	temp = markup(temp);
	printf("temp\n");
	print_stack(temp, size);
	if(get_max_markup(temp) > get_max_markup(stack))
	{
		free(temp);
		return (1);
	}
	free(temp);	
	return (0);
}

int	fromAtoB(t_stack *a, t_stack **b, int size)
{
	//while (is_false_inside(a))
	//{
		if(sa_needed(a, size))
		{
			a = sa(a);
			a = markup(a);
		}
		else if()
	//}
	return(1);
}