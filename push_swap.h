/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:48:58 by bbayard           #+#    #+#             */
/*   Updated: 2021/12/15 23:53:36 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack{
	int		data;
	int		step_sum;
	int		step_a;
	int		step_b;
	int		opt_way;
	int		sort_numb;
}				t_stack;

typedef struct s_stacks{
	int		num_of_a;
	int		num_of_b;
	int		min;

	t_stack	**a;
	t_stack	**b;
}				t_stacks;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		main(int argc, char **argv);
int		sortet(t_stacks *v_n, int num_of_elem);
int		check_valid_arg(int argc, char **argv, t_stacks *valid_num);
long	ft_atoi(char *str);
long	ft_error(int i);
int		ft_strlen(char *s);
int		ft_strlen_2(char **s);
int		ft_strrchr(char **s, int argc, int start, int step_argc);
int		stack_record_num(char **str, t_stacks *valid_num,
			int start, int length);
void	record_str(char **str, char *argv, int i, int start);
int		num_space(char *s, char c);
char	*make_word(char *str, int first, int last);
char	**ft_split(char *s, char c);
int		cleaning(t_stacks *valid_num, int i);
int		create_stack_b(t_stacks *valid_num, int length);
int		cleaning_b(t_stacks *valid_num, int i);
void	sort_two_elem(t_stacks *valid_num);
void	sort_three_elem(t_stacks *valid_num);
void	sort_f_elem(t_stacks *valid_num);
void	sort_elem(t_stacks *valid_num, int num_of_elem, int i);
void	check_print(char **print_comand, int start);
void	sa(t_stacks *valid_num);
void	sb(t_stacks *valid_num);
void	pa(t_stacks *valid_num);
void	pb(t_stacks *valid_num);
void	ra(t_stacks *valid_num);
void	rb(t_stacks *valid_num);
void	rra(t_stacks *valid_num);
void	rrb(t_stacks *valid_num);
void	rr(t_stacks *valid_num);
void	rrr(t_stacks *valid_num);
void	sortirovka(int *sort_mas, int l, int r);
int		part(int *sort_mas, int l, int r);
void	stack_work(t_stacks *v_n, int i);
void	f_sort(t_stacks *v_n);
int		ev_b_rr(t_stacks *v_n, int s_n);
int		ev_b_rrr(t_stacks *v_n, int s_n);
int		compration(int sum_rr, int sum_rrr, int sum_mix);
void	i_v(t_stack *valid_num, int i, int b, int way);
void	push_to_a(t_stacks *v_n, int i);
void	push_w_1(t_stacks *v_n, int r);
void	push_w_2(t_stacks *v_n, int r);
void	push_w_3(t_stacks *v_n, int r);
void	push_w_4(t_stacks *v_n, int r);
void	push_to_b(t_stacks *v_n, int r);
int		sum_step(int a, int b, int i);
int		find_place_b(t_stacks *v_n, int s_n, int min, int max);
int		free_staks(t_stacks *valid_num);

#endif
