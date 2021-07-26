#include "push_swap.h"

int get_min(t_stack *stack)
{
    int i;
    int min;

    i = 0;
    while (stack[i].index != -1)
        ++i;
    min = i;
    ++i;
    while (stack[i].value == 1)
    {
        if (stack[i].number < stack[min].number && stack[i].index == -1)
            min = i;
        ++i;
    }
    return (min);
}

t_stack     *ft_index(t_stack *stack)
{
    int index;
    int i;

    i = 0;
    while (i < stack_size(stack))
    {
        index = get_min(stack);
        stack[index].index = i;
        ++i;
    }
    return (stack); 
}