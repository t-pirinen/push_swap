/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:26 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/16 22:26:43 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	initialize_stacks(int ac, char **av, struct s_stacks *stacks)
{
	int	word_count;
	int	i;
	
	i = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	while (--ac)
	{
		word_count = ft_count_words(av[i + 1], ' ');
		if (word_count)
			stacks->a_size += word_count;
		else
			stacks->a_size++;
		i++;
	}
	stacks->stack_a = malloc(stacks->a_size * sizeof *stacks->stack_a);
	if (stacks->stack_a == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
	stacks->stack_b = malloc(stacks->a_size * sizeof *stacks->stack_b);
	if (stacks->stack_b == NULL)
		free_and_exit_with_msg(stacks, "Error\n");
}

void	make_arg_str(int ac, char **av, struct s_stacks *stacks)
{
	char	*result;
	char	*tmp;
	int		i;

	result = NULL;
	i = 1;
	while (i < ac)
	{
		if (result == NULL)
			result = ft_strdup(av[i]);
		else
		{
			tmp = ft_strjoin(result, " ");
			free(result);
			result = ft_strjoin(tmp, av[i]);
			free(tmp);
		}
		if (!result)
			free_and_exit_with_msg(stacks, "Error\n");
		i++;
	}
	stacks->args = result;
}

void	populate_stack_a(struct s_stacks *stacks)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	temp = ft_split(stacks->args, ' ');
	i = 0;
	while (temp[i] != NULL && temp[i][0] != '\0')
	{
		stacks->stack_a[j++] = convert_arg_to_int(temp[i++], stacks);
		free(temp[i - 1]);
	}
	free(temp);
}

int	convert_arg_to_int(const char *n, struct s_stacks *stacks)
{
	int			i;
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	i = 0;
	if (n[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (n[i])
	{
		if (result > 2147483647 || (sign * result) < -2147483648)
			free_and_exit_with_msg(stacks, "Error\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			free_and_exit_with_msg(stacks, "Error\n");
		result = result * 10 + (n[i++] - '0');
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
	i = -1;
	while (++i < stacks->a_size)
	{
		idx_nbr = 0;
		j = -1;
		while (++j < stacks->a_size)
			if (stacks->stack_a[i] > stacks->stack_a[j])
				idx_nbr++;
		new_a[i] = idx_nbr;
	}
	i = stacks->a_size;
	while (i--)
		stacks->stack_a[i] = new_a[i];
	free(new_a);
}
