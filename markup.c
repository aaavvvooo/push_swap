#include "push_swap.h"

int     get_max_markup(t_stack *stack)
{
    int i;
    int max;
    int temp;

    i = -1;
    max = 0;
    temp = 0;
    while (stack[++i].value == 1)
    {
        if (stack[i].markup == 1)
            ++temp;
        else
        {
            if(temp > max)
                max = temp;
        }
    }
    if(temp > max)
        max = temp;
    return (max);
}

int  get_markup_length(t_stack *stack, int i)
{
    int j = 0;
    int markup_length = 1;
    while (j < i)
        ++j;
    while (stack[j].value == 1)
    {
        ++j;
        if (stack[j].index > stack[j - 1].index)
            ++markup_length;
        else
            break;
    }
    return (markup_length);
}

t_stack *set_markup(t_stack *stack, int head, int max)
{
    int i = 0;
    int j;
    while (stack[i].index != head)
    {
        stack[i].markup = 0;
        ++i;
    }
    j = i;
    while (j < i + max)
    {
        stack[j].markup = 1;
        ++j;
    }
    while (stack[j].value == 1)
    {
        stack[j].markup = 0;
        ++j;
    }
    return (stack);
}

t_stack *markup(t_stack *stack)
{
    int i = 0;
    int head = stack[i].index;
    int max = 1;
    int t_max;

    while (stack[i].value == 1)
    {
        t_max = get_markup_length(stack, i);
        if (t_max > max)
        {
            max = t_max;
            head = stack[i].index;
        }
        ++i;
    }
    stack = set_markup(stack, head, max);
    return (stack);
}