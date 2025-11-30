/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:37:59 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 19:47:45 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_non_lis(t_ctx *ctx, int *keep)
{
	int	i;
	int	n;

	i = 0;
	n = ctx->a.size;
	while (i < n)
	{
		if (keep[i] == 1)
			op_ra(ctx);
		else
			op_pb(ctx);
		i++;
	}
}
