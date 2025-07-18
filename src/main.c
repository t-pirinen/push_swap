/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:38:30 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/17 17:15:20 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

int	main(int ac, char **av)
{
	struct s_stacks	*stacks;
	
	check_arg_validity(ac, av);
	stacks = malloc(sizeof *stacks);
	if (NULL == stacks)
		exit(1);
	initialize_stacks(ac, av, stacks);
	make_arg_str(ac, av, stacks);
	populate_stack_a(stacks);
	check_for_duplicates_and_order(stacks);
	create_index(stacks);
	if (stacks->a_size == 2 && stacks->stack_a[0] > stacks->stack_a[1])
		swap("sa", stacks->stack_a, stacks->a_size);
	else if (stacks->a_size == 3)
		sort_three_elements(stacks);
	else if (stacks->a_size >= 4 && stacks->a_size <= 5)
		sort_four_to_five_elements(stacks);
	else
		radix_sort(stacks);
	if (is_array_in_order(stacks))
		free_and_exit_with_msg(stacks, NULL);
	free_and_exit_with_msg(stacks, "Error\n");
	return(0);
}
