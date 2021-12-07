#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*valid_num;

	valid_num = malloc(sizeof(t_stacks));
	if (!check_valid_arg(argc, argv, valid_num))  
		return (0);
	return (0);	
}