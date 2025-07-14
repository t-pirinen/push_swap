/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:48:56 by tpirinen          #+#    #+#             */
/*   Updated: 2025/07/14 19:29:31 by tpirinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../libft/libft.h"

struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		a_size;
	int		b_size;
	char	*args;
};






#endif