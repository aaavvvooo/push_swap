#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int		size;

	a = parser(argc, argv);
	size = stack_size(a);
	b = create_stack(b, size);
	printf("A\n");
	print_stack (a, size);
	a = ft_index(a);
	a = markup(a);
	printf("A\n");
	print_stack (a, size);
	fromAtoB(&a, &b, size);
	//printf("A\n");
	//print_stack (a, size);
	//printf("B\n");
	//print_stack (b, size);


	//b = create_stack(b, size);
	//printf("B\n");
	//push (a, b, size);
	//push(a, b, size);
	//printf("A\n");
	//print_stack (a, size);
	//printf("B\n");
	//print_stack (b, size);
		


	return (0);
}
