/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:41:53 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/19 20:29:46 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	free_and_exit_with_msg(struct s_stacks *stacks, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stacks != NULL)
	{
		if (stacks->a != NULL)
			free(stacks->a);
		if (stacks->b != NULL)
			free(stacks->b);
		if (stacks != NULL)
			free(stacks);
	}
	exit(1);
}

void	check_for_duplicates_and_order(struct s_stacks *stacks)
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
	if (is_array_in_order(stacks))
		free_and_exit_with_msg(stacks, NULL);
}

int	is_array_in_order(struct s_stacks *stacks)
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
