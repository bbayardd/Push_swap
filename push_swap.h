#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack{

	int		data;
	int		step_sum;
	int		step_a;
	int		step_b;
	// int		c_point_a;
	// int		c_point_b;
	// struct step_scal *left;
	// struct step_scal *rigth;
	
}				t_stack;

typedef struct s_stacks{
	int		num_of_a;
	int		num_of_b;
	int		min;
	int		max;
	int		middle;
	int		num_space;

	t_stack	**a;
	t_stack	**b;
}				t_stacks;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		main(int argc, char **argv);
int		check_valid_arg(int argc, char **argv, t_stacks *valid_num);
int		ft_atoi(char *str);
int 	ft_error();
int		ft_strlen(char *s);
int 	ft_strrchr(char *s, char c, int start);
void	stack_record_num(char **str, t_stacks *valid_num, int start, int length);
void	record_str(char **str, char *argv, int i, int start);
int		num_space(char *s, char c);
char	*make_word(char *str, int first, int last);
char	**ft_split(char *s, char c);
void	cleaning(t_stacks *valid_num, int i);
int		create_stack_b(t_stacks *valid_num, int length);
void	cleaning_b(t_stacks *valid_num, int i);

# endif
