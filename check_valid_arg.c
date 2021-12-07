#include "push_swap.h"

void	cleaning_b(t_stacks *valid_num, int i)
{
	while (i >= 0)
		free(valid_num->b[i--]);
	free(valid_num);
}

int	create_stack_b(t_stacks *valid_num, int length)
{
	int	i;
	i = 0;
	valid_num->b = malloc(sizeof(char **) * length);
	if (!valid_num)
	{
		free(valid_num);
		return (0);
	}
	while (length > i)
	{
		valid_num->b[i] = malloc(sizeof(t_stack));
		if (!valid_num->b[i])
		{
			cleaning_b(valid_num, i);
			return (0);
		}
		i++;
	}	
	return (1);
}

void	cleaning(t_stacks *valid_num, int i)
{
	while (i >= 0)
		free(valid_num->a[i--]);
	free(valid_num);
}

void	stack_record_num(char **str, t_stacks *valid_num, int start, int length)
{
	int i;
	i = 0;
	valid_num->a = malloc(sizeof(char **) * length);	
	if (!valid_num)
	{
		free(valid_num);
		return ;
	}
	valid_num->num_space = length - start;	
write(1, "==Pizde==\n", 10);	
	while (length-- > start)
	{
write(1, "Pizde\n", 6);		
		valid_num->a[i] = malloc(sizeof(t_stack));
		if(!valid_num->a[i])
		{
			cleaning(valid_num, i);
			return ;
		}
write(1, "Pizde\n", 6);				
		valid_num->a[i]->data = ft_atoi(str[length]);	
		if (!valid_num->a[i]->data)
			cleaning(valid_num, i);
		i++;
	}
write(1, "12Pizde12\n", 10);	
	if (!create_stack_b(valid_num, length))
		cleaning(valid_num, start);
write(1, "==Pizde==\n", 10);
}

int	check_valid_arg(int argc, char **argv, t_stacks *valid_num)
{
	int		i;
	char	**str;

	str = NULL;
	i = 0;
	if (argc < 2)
		return (ft_error());
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str)
			return (0);
		stack_record_num(str, valid_num, 0, ft_strlen(*str));
	}
	else 
	{			
		while (++i < argc)
		{
			if (ft_strrchr(*argv, *argv[i], i))
				return (ft_error());
		}
write(1, "1_Pizde\n", 8);
		stack_record_num(str, valid_num, 1, argc - 1);
	}	
	return (1);
}