#include "push_swap.h"

int	ft_atoi(char *str)
{
	int		sign;
	int		num;
	int		i;


	sign = 1;
	num = 0;
	i = 0;
write(1, "atoii\n", 6);
	if (!str[i])
		return (0);
write(1, "atoii\n", 6);
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		return (ft_error());
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i++] - '0') * sign;
		if ((sign > 0 && num < 0) || (sign < 0 && num > 0))
			return (ft_error());
	}
	if (str[i])
		return (ft_error());
	return (num);
} 

int ft_error()
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strrchr(char *s, char c, int start)
{
	int	i;

	i = ft_strlen((char *) s) + 1;
	while (i--)
	{
		if ((s[i] == c) && (i != start))
			return (1);
	}
	return (0);
}
