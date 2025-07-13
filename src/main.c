/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:38:30 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/12 17:17:03 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lib.h"

int	main(int ac, char **av)
{
	struct s_stack	*stack_a;
	// struct s_stack	*stack_b;
	int i;
	
	if (ac < 2)
		return (-1);
	stack_a = create_stack(ac, av);
	i = 0;
	while (i < ac - 1)
	{
		ft_printf("%d\n", stack_a[i]);
		i++;
	}
	
	free(stack_a);
}
