/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:48:56 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/22 20:20:20 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include "../libft/libft.h"

struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
};

void	init_stacks_and_populate_a(int ac, char **av, struct s_stacks *stacks);
void	create_index(struct s_stacks *stacks);

void	free_and_exit_with_msg(struct s_stacks *s, char *msg);
void	exit_if_duplicates_or_in_order(struct s_stacks *stacks);
int		check_stack_a_order(struct s_stacks *stacks);

void	radix_sort(struct s_stacks *stacks);
void	sort_three(struct s_stacks *stacks);
void	sort_four_or_five(struct s_stacks *stacks);

void	push(char *str, struct s_stacks *stacks);
void	swap(char *str, int *array, int size);
void	rotate(int *array, int size, char *direction, char *list);

#endif