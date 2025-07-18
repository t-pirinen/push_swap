/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:15:41 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/16 22:03:02 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	radix_sort(struct s_stacks *stacks)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stacks->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stacks->a_size;
		while (size-- && !is_array_in_order(stacks))
		{
			if (((stacks->stack_a[0] >> j) & 1) == 0)
				push("pb", stacks);
			else
				rotate(stacks->stack_a, stacks->a_size, "up", "a");
		}
		radix_sort_stack_b(stacks, stacks->b_size, bit_size, j + 1);
	}
	while (stacks->b_size != 0)
		push("pa", stacks);
}

void	radix_sort_stack_b(struct s_stacks *stacks, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_in_order(stacks))
	{
		if (((stacks->stack_b[0] >> j) & 1) == 0)
			rotate(stacks->stack_b, stacks->b_size, "up", "b");
		else
			push("pa", stacks);
	}
	if (is_array_in_order(stacks))
		while (stacks->b_size != 0)
			push("pa", stacks);
}

void	sort_three_elements(struct s_stacks *stacks)
{
	if (stacks->stack_a[2] != 2)
	{
		if (stacks->stack_a[0] == 2)
			rotate(stacks->stack_a, stacks->a_size, "up", "a");
		else
			rotate(stacks->stack_a, stacks->a_size, "down", "a");
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap("sa", stacks->stack_a, stacks->a_size);
}

void	sort_four_to_five_elements(struct s_stacks *stacks)
{
	while (stacks->b_size <= 1)
	{
		if (stacks->stack_a[0] == 0 || stacks->stack_a[0] == 1)
			push("pb", stacks);
		else
			rotate(stacks->stack_a, stacks->a_size, "up", "a");
	}
	if (stacks->stack_b[0] == 0)
		swap("sb", stacks->stack_b, stacks->b_size);
	if (stacks->stack_a[2] != 4)
	{
		if (stacks->stack_a[0] == 4)
			rotate(stacks->stack_a, stacks->a_size, "up", "a");
		else
			rotate(stacks->stack_a, stacks->a_size, "down", "a");
	}
	if (stacks->stack_a[0] > stacks->stack_a[1])
		swap("sa", stacks->stack_a, stacks->a_size);
	push("pa", stacks);
	push("pa", stacks);
}