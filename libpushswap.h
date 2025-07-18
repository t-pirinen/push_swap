/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:48:56 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/16 22:00:53 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../libft/libft.h"

struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		a_size;
	int		b_size;
	char	*args;
};

void	free_and_exit_with_msg(struct s_stacks *s, char *msg);
void	check_arg_validity(int ac, char **av);
void	initialize_stacks(int ac, char **av, struct s_stacks *stacks);
void	make_arg_str(int ac, char **av, struct s_stacks *stacks);
void	populate_stack_a(struct s_stacks *stacks);
int		convert_arg_to_int(const char *n, struct s_stacks *stacks);
void	check_for_duplicates_and_order(struct s_stacks *stacks);
int		is_array_in_order(struct s_stacks *stacks);
void	create_index(struct s_stacks *stacks);

void	radix_sort(struct s_stacks *stacks);
void	radix_sort_stack_b(struct s_stacks *stacks, int b_size, int bit_size, int j);
void	sort_three_elements(struct s_stacks *stacks);
void	sort_four_to_five_elements(struct s_stacks *stacks);
void	push(char *str, struct s_stacks *stacks);
void	swap(char *str, int *array, int size);
void	rotate(int *array, int size, char *direction, char *list);


#endif