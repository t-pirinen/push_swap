/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:15:41 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/23 11:37:22 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	sort_three(struct s_stacks *stacks)
{
	if (stacks->a[2] != 2)
	{
		if (stacks->a[0] == 2)
			rotate(stacks->a, stacks->a_size, "up", "a");
		else
			rotate(stacks->a, stacks->a_size, "down", "a");
	}
	if (stacks->a[0] > stacks->a[1])
		swap("sa", stacks->a, stacks->a_size);
}

void	sort_four_or_five(struct s_stacks *stacks)
{
	while (stacks->b_size <= 1)
	{
		if (stacks->a[0] == 0 || stacks->a[0] == 1)
			push("pb", stacks);
		else
			rotate(stacks->a, stacks->a_size, "up", "a");
	}
	if (stacks->b[0] == 0)
		swap("sb", stacks->b, stacks->b_size);
	if (stacks->a[2] != 4)
	{
		if (stacks->a[0] == 4)
			rotate(stacks->a, stacks->a_size, "up", "a");
		else
			rotate(stacks->a, stacks->a_size, "down", "a");
	}
	if (stacks->a[0] > stacks->a[1])
		swap("sa", stacks->a, stacks->a_size);
	push("pa", stacks);
	push("pa", stacks);
}

void	radix_sort(struct s_stacks *stacks)
{
	int	size;
	int	bit_size;
	int	i;

	size = stacks->a_size - 1;
	bit_size = 0;
	while (size && ++bit_size)
		size >>= 1;
	i = 0;
	while (i < bit_size)
	{
		size = stacks->a_size;
		while (size-- && !check_stack_a_order(stacks))
		{
			if ((stacks->a[0] >> i) & 1)
				rotate(stacks->a, stacks->a_size, "up", "a");
			else
				push("pb", stacks);
		}
		radix_sort_b(stacks, stacks->b_size, bit_size, i);
		i++;
	}
	while (stacks->b_size != 0)
		push("pa", stacks);
}

void	radix_sort_b(struct s_stacks *stacks, int b_size, int bit_size, int i)
{
	i++;
	while (b_size-- && i < bit_size && !check_stack_a_order(stacks))
	{
		if (((stacks->b[0] >> i) & 1) == 0)
			rotate(stacks->b, stacks->b_size, "up", "b");
		else
			push("pa", stacks);
	}
	if (check_stack_a_order(stacks))
		while (stacks->b_size != 0)
			push("pa", stacks);
}
