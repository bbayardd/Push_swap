/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:48:51 by bbayard           #+#    #+#             */
/*   Updated: 2021/12/16 01:01:56 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_staks(t_stacks *valid_num)
{
	free(valid_num);
	return (0);
}

int	sortet(t_stacks *v_n, int num_of_elem)
{
	int	i;

	i = 1;
	while (i < num_of_elem)
	{
		if (v_n->a[i - 1]->data < v_n->a[i]->data)
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}

int	sum_step(int a, int b, int i)
{
	if (i == 1)
		a = 0;
	if (a >= b)
		return (a);
	else
		return (b);
}

int	find_place_b(t_stacks *v_n, int s, int m, int x)
{
	int	i;
	int	remeber;
	int	remeber_m;

	i = -1;
	while (++i < v_n->num_of_b)
	{
		if (v_n->b[i]->sort_numb - s == 1)
			return (i);
		else if (v_n->b[i]->sort_numb - s > 0 && v_n->b[i]->sort_numb - s < m)
		{
			remeber = i;
			m = v_n->b[i]->sort_numb - s;
		}
		else if (v_n->b[i]->sort_numb - s == -1)
			return (-i);
		else if (v_n->b[i]->sort_numb - s < 0 && v_n->b[i]->sort_numb - s > x)
		{
			remeber_m = i;
			x = v_n->b[i]->sort_numb - s;
		}
	}
	if (m > x * (-1))
		remeber = remeber_m * (-1);
	return (remeber);
}

int	main(int argc, char **argv)
{
	t_stacks	*valid_num;
	int			num_of_element;

	valid_num = malloc(sizeof(t_stacks));
	if (!valid_num)
		return (0);
	valid_num->num_of_b = 0;
	num_of_element = check_valid_arg(argc, argv, valid_num);
	if (!num_of_element)
		return (0);
	valid_num->num_of_a = num_of_element;
	if (sortet(valid_num, num_of_element) || (num_of_element == 1))
		return (cleaning_b(valid_num, num_of_element));
	else if (num_of_element == 2)
		sort_two_elem(valid_num);
	else if (num_of_element == 3)
		sort_three_elem(valid_num);
	else if (num_of_element == 4 || num_of_element == 5)
		sort_f_elem(valid_num);
	else
		sort_elem(valid_num, num_of_element, -1);
	return (cleaning_b(valid_num, num_of_element));
}
