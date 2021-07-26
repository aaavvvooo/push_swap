#include "push_swap.h"

t_stack	*arr_to_stack(char **naxnakan, t_stack *a, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		if (!ft_isdigit(naxnakan[i][0]) && naxnakan[i][0] != '-')
			error("How do you think I'll sort not numbers1??\n");
		while (j < ft_strlen(naxnakan[i]))
		{
			if (!ft_isdigit(naxnakan[i][j]))
				error("How do you think I'll sort not numbers2??\n");
			++j;
		}
		a[i].number = ft_atoi(naxnakan[i]);
		a[i].value = 1;
		a[i].index = -1;
		a[i].markup = 0;
		++i;
	}
	return (a);
}

char	**argv_parser(char **naxnakan, char **massiv, int elements)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = -1;
	j = 0;
	while (j < elements)
	{
		len = (int) ft_strlen((char *)massiv[j]);
		naxnakan[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!naxnakan[j])
			return (NULL);
		while (massiv[j][++i])
			naxnakan[j][i] = massiv[j][i];
		naxnakan[j][i] = '\0';
		++j;
		i = -1;
	}
	naxnakan[j] = NULL;
	return (naxnakan);
}

void	no_duplicates(t_stack *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i].number == a[j].number)
				error("Have you read the subject? No rep\
eating numbers allowed!!\n");
			++j;
		}
		++i;
	}
}

static int	length_counter(char **array)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (i < naxnakan_count(array))
	{
		while(j < (int)ft_strlen(array[i]))
		{
			++len;
			++j;
		}
		++i;
	}
	return (len);
}

char *tox_lconum(char *tox, char **argv)
{
	int j = 1;
	int t = 0;

	while(argv[j])
	{
		tox = ft_strjoin(tox, argv[j]);
		tox = ft_strjoin(tox, " ");
		++j;
	}
	return (tox);
}

t_stack *parser(int argc, char **argv)
{
	char	**naxnakan;
	char	*tox;
	int		len_tox;
	int		len_naxnakan;
	t_stack	*a;

	len_tox = length_counter(argv);
	tox = (char *)calloc (sizeof(char), (len_tox));
	if(!tox)
		error("Can't allocate enough memory\n");
	if (argc == 1)
		error("Where are your arguments?\n");
	else
	{
		tox = tox_lconum(tox, argv);
		printf("%s\n",tox);
		naxnakan = ft_split(tox, ' ');
		len_naxnakan = naxnakan_count(naxnakan);
		a = (t_stack *)malloc(sizeof(t_stack ) * len_naxnakan);
		if (!a)
		 	return (NULL);
		a = arr_to_stack(naxnakan, a, len_naxnakan);
		no_duplicates(a, len_naxnakan);
		free (naxnakan);
	}
	return (a);
}

int is_sorted (t_stack *stack)
{
	int i;

	i = 0;
	while (stack[++i].value == 1)
		if (stack[i].number <= stack[i - 1].number)
			return (0);
	return (1);
}