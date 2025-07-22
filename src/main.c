/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:38:30 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/22 20:22:08 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

int	main(int ac, char **av)
{
	struct s_stacks	*stacks;

	stacks = malloc(sizeof * stacks);
	if (NULL == stacks)
		exit(1);
	init_stacks_and_populate_a(ac, av, stacks);
	create_index(stacks);
	exit_if_duplicates_or_in_order(stacks);
	if (stacks->a_size == 2)
		swap("sa", stacks->a, stacks->a_size);
	else if (stacks->a_size == 3)
		sort_three(stacks);
	else if (stacks->a_size == 4 || stacks->a_size == 5)
		sort_four_or_five(stacks);
	else
		radix_sort(stacks);
	free_and_exit_with_msg(stacks, NULL);
}
