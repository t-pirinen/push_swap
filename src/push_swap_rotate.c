/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:30:52 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/16 22:41:39 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	push(char *str, struct s_stacks *stacks)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (stacks->b_size <= 0)
			return ;
		tmp = stacks->stack_b[0];
		ft_memmove(stacks->stack_a + 1, stacks->stack_a, sizeof(int) * stacks->a_size);
		stacks->stack_a[0] = tmp;
		stacks->b_size--;
		ft_memmove(stacks->stack_b, stacks->stack_b + 1, sizeof(int) * stacks->b_size);
		stacks->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (stacks->a_size <= 0)
			return ;
		tmp = stacks->stack_a[0];
		ft_memmove(stacks->stack_b + 1, stacks->stack_b, sizeof(int) * stacks->b_size);
		stacks->stack_b[0] = tmp;
		stacks->a_size--;
		ft_memmove(stacks->stack_a, stacks->stack_a + 1, sizeof(int) * stacks->a_size);
		stacks->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}