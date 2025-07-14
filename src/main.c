/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:38:30 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/14 18:45:04 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	check_arg_validity(int ac, char **av);

int	main(int ac, char **av)
{
	struct s_stacks	*stacks;
	const int		len = ac - 1;
	
	check_arg_validity(ac, av);
	
	stacks = malloc(sizeof *stacks);
	


}

static void	check_arg_validity(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		free_and_exit_with_message(NULL, "");
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			free_and_exit_with_message(NULL, "Error\n");
		while (av[i][j] != '\0')
		{
			if ((!(ft_isdigit(av[i][j])) && (av[i][j] != ' ')
			&& (av[i][j] != '-' && av[i][j] != '+' && av[i][j] != ' '))
			|| (av[i][j] == '-' && av[i][j + 1] == '\0')
			|| (av[i][j] == '+' && av[i][j + 1] == '\0')
			|| (av[i][j] == '-' && av[i][j + 1] == ' ')
			|| (av[i][j] == '+' && av[i][j + 1] == ' '))
				free_and_exit_with_message(NULL, "Error\n");
			j++;
		}
	}
}

static void	join_args(int ac, char **av, struct s_stacks *stacks)
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
			free_and_exit_with_message(stacks, "Error\n");
		i++;
	}
	stacks->integer_array = result;
}

void	free_and_exit_with_message(struct s_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->stack_a != NULL)
			free(s->stack_a);
		if (s->stack_b != NULL)
			free(s->stack_b);
		if (s->integer_array != NULL)
			free(s->integer_array);
		if (s != NULL)
			free(s);
	}
	exit(1);
}