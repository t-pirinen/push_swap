/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:30:52 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/25 16:34:32 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpushswap.h"

void	push(enum e_push_to instruction, struct s_stacks *stacks)
{
	int	temp;

	if (instruction == pa && stacks->b_size > 0)
	{
		temp = stacks->b[0];
		ft_memmove(stacks->a + 1, stacks->a, sizeof(int) * stacks->a_size);
		stacks->a[0] = temp;
		stacks->a_size++;
		stacks->b_size--;
		ft_memmove(stacks->b, stacks->b + 1, sizeof(int) * stacks->b_size);
		ft_putendl_fd("pa", 1);
	}
	else if (instruction == pb && stacks->a_size > 0)
	{
		temp = stacks->a[0];
		ft_memmove(stacks->b + 1, stacks->b, sizeof(int) * stacks->b_size);
		stacks->b[0] = temp;
		stacks->b_size++;
		stacks->a_size--;
		ft_memmove(stacks->a, stacks->a + 1, sizeof(int) * stacks->a_size);
		ft_putendl_fd("pb", 1);
	}
}

void	swap(char *instruction, int *stack, int size)
{
	int	temp;

	if (size <= 0)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	ft_putendl_fd(instruction, 1);
}

void	rotate(int *stack, int size, enum e_dir direction, char *stack_name)
{
	int	temp;

	if (size < 0)
		return ;
	if (direction == up)
	{
		temp = stack[0];
		ft_memmove(stack, stack + 1, sizeof(int) * (size - 1));
		stack[size - 1] = temp;
		write(1, "r", 1);
	}
	else if (direction == down)
	{
		temp = stack[size - 1];
		ft_memmove(stack + 1, stack, sizeof(int) * (size - 1));
		stack[0] = temp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(stack_name, 1);
}
