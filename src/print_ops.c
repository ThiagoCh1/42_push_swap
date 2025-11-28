/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:10:00 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/27 22:18:18 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

const char	*op_to_str(int op)
{
	if (op == OP_PA)
		return ("pa\n");
	if (op == OP_PB)
		return ("pb\n");
	if (op == OP_SA)
		return ("sa\n");
	if (op == OP_SB)
		return ("sb\n");
	if (op == OP_SS)
		return ("ss\n");
	if (op == OP_RA)
		return ("ra\n");
	if (op == OP_RB)
		return ("rb\n");
	if (op == OP_RR)
		return ("rr\n");
	if (op == OP_RRA)
		return ("rra\n");
	if (op == OP_RRB)
		return ("rrb\n");
	if (op == OP_RRR)
		return ("rrr\n");
	return ("");
}

void	print_ops(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->op_len)
	{
		ft_printf("%s", op_to_str(ctx->ops[i]));
		i++;
	}
}
