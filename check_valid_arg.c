/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:48:30 by bbayard           #+#    #+#             */
/*   Updated: 2021/12/15 23:37:18 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cleaning_b(t_stacks *valid_num, int i)
{
	int	c;

	c = 0;
	while (i > c)
	{
		free(valid_num->b[c]);
		c++;
	}
	free(valid_num->b);
	return (cleaning(valid_num, i));
}

int	cleaning(t_stacks *valid_num, int i)
{
	while (--i >= 0)
		free(valid_num->a[i]);
	free(valid_num->a);
	free(valid_num);
	return (0);
}

int	create_stack_b(t_stacks *valid_num, int length)
{
	int	i;

	i = 0;
	valid_num->b = malloc(sizeof(char **) * length + 1);
	if (!valid_num->b)
	{
		free(valid_num);
		return (0);
	}
	while (length > i)
	{
		valid_num->b[i] = malloc(sizeof(t_stack));
		if (!valid_num->b[i])
		{
			cleaning_b(valid_num, length);
			return (0);
		}
		valid_num->b[i]->sort_numb = 0;
		i++;
	}
	return (1);
}

int	stack_record_num(char **str, t_stacks *valid_num, int start, int length)
{
	int	i;

	i = 0;
	valid_num->a = malloc(sizeof(char **) * length + 1);
	if (!valid_num->a)
		return (cleaning(valid_num, i));
	while (length - start >= i)
	{
		valid_num->a[i] = malloc(sizeof(t_stack));
		if (!valid_num->a[i])
			return (cleaning(valid_num, i));
		valid_num->a[i]->data = ft_atoi(str[i + start]);
		valid_num->a[i]->sort_numb = 0;
		i++;
	}
	if (!create_stack_b(valid_num, length))
		return (cleaning(valid_num, i));
	return (i);
}

int	check_valid_arg(int argc, char **argv, t_stacks *valid_num)
{	
	char	**str;
	int		step_argc;

	step_argc = 0;
	str = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str)
			return (0);
		if (!ft_strrchr(str, ft_strlen_2(str), 0, step_argc))
			return (0);
		return (stack_record_num(str, valid_num, 0, ft_strlen_2(str)));
	}
	else
	{
		if (!ft_strrchr(argv, --argc, 1, step_argc))
			return (0);
		return (stack_record_num(argv, valid_num, 1, argc));
	}
}
