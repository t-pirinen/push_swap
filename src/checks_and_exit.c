/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:41:53 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/16 22:36:49 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	free_and_exit_with_msg(struct s_stacks *stacks, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stacks != NULL)
	{
		if (stacks->stack_a != NULL)
			free(stacks->stack_a);
		if (stacks->stack_b != NULL)
			free(stacks->stack_b);
		if (stacks->args != NULL)
			free(stacks->args);
		if (stacks != NULL)
			free(stacks);
	}
	exit(1);
}

void	check_arg_validity(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		free_and_exit_with_msg(NULL, "");
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0])
			free_and_exit_with_msg(NULL, "Error\n");
		while (av[i][j] != '\0')
		{
			if ((!(ft_isdigit(av[i][j])) && av[i][j] != '-')
			|| (av[i][j] == '-' && av[i][j + 1] == '\0')
			|| (av[i][j] == '-' && av[i][j + 1] == ' '))
				free_and_exit_with_msg(NULL, "Error\n");
			j++;
		}
	}
}

void	check_for_duplicates_and_order(struct s_stacks *stacks)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (i == 0)
	{
		while (i < stacks->a_size)
		{
			j = i + 1;
			while (j < stacks->a_size)
			{
				if (stacks->stack_a[i] == stacks->stack_a[j])
					free_and_exit_with_msg(stacks, "Error\n");
				j++;
			}
			i++;
		}
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
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}