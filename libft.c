/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:47:48 by bbayard           #+#    #+#             */
/*   Updated: 2021/12/15 20:55:46 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		sign;
	int		num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	if (!str[i])
		return (2147483648);
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		return (ft_error(1));
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0') * sign;
		if ((sign > 0 && num < 0) || (sign < 0 && num > 0))
			return (ft_error(1));
	}
	if (str[i])
		return (ft_error(1));
	return (num);
}

long	ft_error(int i)
{
	if (i == 1)
	{
		write (i, "Error\n", 6);
		return (2147483648);
	}
	else
	{
		write (1, "Error\n", 6);
		return (0);
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_2(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (--i);
}

int	ft_strrchr(char **s, int argc, int start, int step_argc)
{
	long	c1;
	long	c2;

	if (argc <= 0)
	{
		if (ft_atoi(s[argc]) == 2147483648)
			return (0);
		return (1);
	}
	while (0 < argc)
	{	
		c2 = ft_atoi(s[argc]);
		if (c2 == 2147483648)
			return (0);
		step_argc = argc--;
		while (--step_argc >= start)
		{
			c1 = ft_atoi(s[step_argc]);
			if (c1 == 2147483648)
				return (0);
			if (c1 - c2 == 0)
				return (ft_error(0));
		}
	}
	return (1);
}
