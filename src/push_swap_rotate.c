/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:30:52 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/25 16:18:39 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	push(char *str, struct s_stacks *stacks)
{
	int	temp;

	if (ft_strncmp(str, "pa", 3) == 0 && stacks->b_size > 0)
	{
		temp = stacks->b[0];
		ft_memmove(stacks->a + 1, stacks->a, sizeof(int) * stacks->a_size);
		stacks->a[0] = temp;
		stacks->a_size++;
		stacks->b_size--;
		ft_memmove(stacks->b, stacks->b + 1, sizeof(int) * stacks->b_size);
	}
	else if (ft_strncmp(str, "pb", 3) == 0 && stacks->a_size > 0)
	{
		temp = stacks->a[0];
		ft_memmove(stacks->b + 1, stacks->b, sizeof(int) * stacks->b_size);
		stacks->b[0] = temp;
		stacks->b_size++;
		stacks->a_size--;
		ft_memmove(stacks->a, stacks->a + 1, sizeof(int) * stacks->a_size);
	}
	ft_putendl_fd(str, 1);
}

void	swap(char *str, int *array, int size)
{
	int	temp;

	if (size <= 0)
		return ;
	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, enum e_dir direction, char *stack_name)
{
	int	temp;

	if (size < 0)
		return ;
	if (direction == up)
	{
		temp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = temp;
		write(1, "r", 1);
	}
	else if (direction == down)
	{
		temp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = temp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(stack_name, 1);
}
