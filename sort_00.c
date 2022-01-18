/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:06:20 by bbayard           #+#    #+#             */
/*   Updated: 2021/12/16 01:12:58 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stacks *valid_num)
{
	if (valid_num->a[0]->data > valid_num->a[1]->data)
		sa(valid_num);
}

void	sort_three_elem(t_stacks *v_n)
{
	int	max;
	int	i;

	i = 0;
	max = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data > max)
			max = v_n->a[i]->data;
		i++;
	}
	if (v_n->a[0]->data == max)
		ra(v_n);
	if (v_n->a[1]->data == max)
		rra(v_n);
	if (v_n->a[0]->data > v_n->a[1]->data)
		sa(v_n);
}

int	find_max(t_stacks *v_n)
{
	int	i;
	int	max;

	i = 0;
	max = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data > max)
			max = v_n->a[i]->data;
		i++;
	}
	return (max);
}

int	find_min(t_stacks *v_n)
{
	int	i;
	int	min;

	i = 0;
	min = v_n->a[0]->data;
	while (i < v_n->num_of_a)
	{
		if (v_n->a[i]->data < min)
			min = v_n->a[i]->data;
		i++;
	}
	return (min);
}

void	sort_f_elem(t_stacks *valid_num)
{
	int	max;
	int	min;

	max = find_max(valid_num);
	min = find_min(valid_num);
	while (valid_num->num_of_a > 3)
	{
		if (valid_num->a[0]->data == max
			|| valid_num->a[0]->data == min)
			pb(valid_num);
		else
			ra(valid_num);
	}
	sort_three_elem(valid_num);
	pa(valid_num);
	pa(valid_num);
	if (valid_num->a[0]->data == max)
		ra(valid_num);
	else if (valid_num->a[1]->data < valid_num->a[2]->data)
		return ;
	else
	{
		sa(valid_num);
		ra(valid_num);
	}
}
