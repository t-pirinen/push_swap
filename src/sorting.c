/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:15:41 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/20 18:22:24 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	radix_sort(struct s_stacks *stacks)
{
	int	size_idx;
	int	bit_size;
	int	i;

	size_idx = stacks->a_size - 1;
	bit_size = 0;
	i = 0;
	while (size_idx && ++bit_size)
		size_idx >>= 1;
	while (i < bit_size)
	{
		size_idx = stacks->a_size;
		while (size_idx-- && !is_array_in_order(stacks))
		{
			if ((stacks->a[0] >> i) & 1)
				rotate(stacks->a, stacks->a_size, "up", "a");
			else
				push("pb", stacks);
		}
		radix_sort_b(stacks, stacks->b_size, bit_size, i + 1);
		i++;
	}
	while (stacks->b_size)
		push("pa", stacks);
}

void	radix_sort_b(struct s_stacks *stacks, int b_size, int bit_size, int i)
{
	while (b_size-- && i < bit_size && !is_array_in_order(stacks))
	{
		if (((stacks->b[0] >> i) & 1) == 0)
			rotate(stacks->b, stacks->b_size, "up", "b");
		else
			push("pa", stacks);
	}
	if (is_array_in_order(stacks))
		while (stacks->b_size != 0)
			push("pa", stacks);
}

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
