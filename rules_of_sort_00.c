/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_of_sort_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:17:49 by bbayard           #+#    #+#             */
/*   Updated: 2021/12/16 01:11:29 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *valid_num)
{
	t_stack	*t;

	t = valid_num->a[0];
	valid_num->a[0] = valid_num->a[1];
	valid_num->a[1] = t;
	write (1, "sa\n", 3);
}

void	sb(t_stacks *valid_num)
{
	t_stack	*t;

	t = valid_num->b[0];
	valid_num->b[0] = valid_num->b[1];
	valid_num->b[1] = t;
	write (1, "sb\n", 3);
}

void	pa(t_stacks *valid_num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (!valid_num->b[0])
		return ;
	i = valid_num->num_of_a;
	tmp = valid_num->a[i];
	while (i > 0)
	{
		valid_num->a[i] = valid_num->a[i - 1];
		i--;
	}	
	valid_num->a[0] = valid_num->b[0];
	i = 0;
	if (valid_num->num_of_b == 1)
		valid_num->b[i] = 0;
	while (valid_num->num_of_b > ++i)
			valid_num->b[i - 1] = valid_num->b[i];
	valid_num->b[i] = tmp;
	valid_num->num_of_b--;
	valid_num->num_of_a++;
	write (1, "pa\n", 3);
}

void	pb(t_stacks *valid_num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (!valid_num->a[0])
		return ;
	i = valid_num->num_of_b;
	tmp = valid_num->b[i];
	while (i > 0)
	{
		valid_num->b[i] = valid_num->b[i - 1];
		i--;
	}	
	valid_num->b[0] = valid_num->a[0];
	i = 0;
	if (valid_num->num_of_a == 1)
		valid_num->a[i] = 0;
	while (valid_num->num_of_a > ++i)
			valid_num->a[i - 1] = valid_num->a[i];
	valid_num->a[i] = tmp;
	valid_num->num_of_a--;
	valid_num->num_of_b++;
	write (1, "pb\n", 3);
}

void	ra(t_stacks *valid_num)
{
	int		i;
	t_stack	*t;

	i = 0;
	t = valid_num->a[i];
	while (valid_num->num_of_a - 1 > i)
	{
		valid_num->a[i] = valid_num->a[i + 1];
		i++;
	}
	valid_num->a[i] = t;
	write (1, "ra\n", 3);
}
