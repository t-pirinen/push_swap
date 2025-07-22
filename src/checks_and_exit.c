/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:41:53 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/22 20:20:20 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	free_and_exit_with_msg(struct s_stacks *stacks, char *msg)
{
	if (stacks)
	{
		if (stacks->a)
			free(stacks->a);
		if (stacks->b)
			free(stacks->b);
		if (stacks)
			free(stacks);
	}
	if (NULL == msg)
		exit(0);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	exit_if_duplicates_or_in_order(struct s_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks->a_size)
	{
		j = i + 1;
		while (j < stacks->a_size)
		{
			if (stacks->a[i] == stacks->a[j])
				free_and_exit_with_msg(stacks, "Error\n");
			j++;
		}
		i++;
	}
	if (check_stack_a_order(stacks))
		free_and_exit_with_msg(stacks, NULL);
}

int	check_stack_a_order(struct s_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_size - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
