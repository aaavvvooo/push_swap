#include "push_swap.h"

static t_stack  *massivi_lconum(t_stack *stack, t_stack *massiv, int size)
{
    int j;
    
    j = -1;
    while(stack[++j].value == 1)
    {
        massiv[j].number =  stack[j].number;
        massiv[j].value = 1;
    }
    massiv[j].value = 0;
    return (massiv);
}

void    swap(t_stack *stack)
{
    t_stack temp;
    temp.number = stack[0].number;
    stack[0].number = stack[1].number;
    stack[1].number = temp.number;
    temp.index = stack[0].index;
    stack[0].index = stack[1].index;
    stack[1].index = temp.index;


}

void rotate(t_stack *stack)
{
    t_stack temp;
    int i;

    i = 0;
    temp.number = stack[0].number;
    while(stack[++i].value == 1)
        stack[i - 1].number = stack[i].number;
    stack[i - 1].number = temp.number;
}

void reverse_rotate(t_stack *stack)
{
    t_stack temp;
    int     i;

    i = stack_size(stack) - 1;
    temp.number = stack[i].number;
    while(i > 0)
    {
        stack[i].number = stack[i - 1].number;
        --i;
    }
    stack[i].number = temp.number;
}

void    push(t_stack *from, t_stack *to, int size)
{
    int     i;
    int     temp;
    t_stack *massiv;

    massiv = (t_stack *)malloc (sizeof(t_stack) * size);
    temp = from[0].number;
    i = 0;
    while(from[++i].value == 1)
        from[i - 1].number = from[i].number;
    from[i - 1].value = 0;
    i = -1;
    massiv = massivi_lconum(to, massiv, size);  
    to[0].number = temp;
    while(to[++i].value == 1)
        to[i + 1].number = massiv[i].number;
    to[i].value = 1;
    free(massiv);
}

t_stack *sa(t_stack *a)
{
    swap(a);
    printf("sa\n");
    return (a);
}

