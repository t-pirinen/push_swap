/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:26 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/19 21:18:31 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	init_stacks_and_populate_a(int ac, char **av, struct s_stacks *stacks)
{
	int		i;
	int		j;

	stacks->a_size = ac - 1;
	stacks->b_size = 0;
	stacks->a = malloc(stacks->a_size * sizeof * stacks->a);
	if (stacks->a == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	stacks->b = malloc(stacks->a_size * sizeof * stacks->b);
	if (stacks->b == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	i = 1;
	j = 0;
	while (av[i] != NULL && av[i][0] != '\0')
		stacks->a[j++] = convert_arg_to_int(av[i++], stacks);
}

int	convert_arg_to_int(const char *n, struct s_stacks *stacks)
{
	int			i;
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	i = 0;
	if (n[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_with_msg(stacks, "Error\n");
		result = result * 10 + (n[i] - '0');
		if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
			free_and_exit_with_msg(stacks, "Error\n");
		i++;
	}
	return ((int)(sign * result));
}

void	create_index(struct s_stacks *stacks)
{
	int		i;
	int		j;
	int		idx_nbr;
	int		*new_a;

	new_a = malloc(stacks->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	i = 0;
	while (i < stacks->a_size)
	{
		idx_nbr = 0;
		j = 0;
		while (j < stacks->a_size)
		{
			if (stacks->a[i] > stacks->a[j])
				idx_nbr++;
			j++;
		}
		new_a[i] = idx_nbr;
		i++;
	}
	ft_int_arr_copy(stacks->a, new_a, stacks->a_size);
	free(new_a);
}
