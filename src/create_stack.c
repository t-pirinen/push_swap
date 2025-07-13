/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:57:26 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/12 17:18:05 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../lib.h"

struct s_stack	*create_stack(int ac, char **av)
{
	struct s_stack	*new_stack;
	int	i;
	
	new_stack->top = 0;
	new_stack->integer_array = malloc((ac - 1) * sizeof(int));
	i = 0;
	while (i < ac - 1)
	{
		new_stack->integer_array[i] = ft_atoi(av[i + 1]);
		i++;
	}
	// (void)av;
	return(new_stack);
}