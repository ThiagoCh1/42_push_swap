/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:30:19 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 21:31:16 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ctx *ctx)
{
	int	n;

	if (ctx->a.size < 2)
		return ;
	n = pop_front(&ctx->a);
	push_back(&ctx->a, n);
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_RA;
}


void	op_rb(t_ctx *ctx)
{
	int	n;

	if (ctx->b.size < 2)
		return ;
	n = pop_front(&ctx->b);
	push_back(&ctx->b, n);
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_RB;
}

void	op_rr(t_ctx *ctx)
{
	int	n;

	if (ctx->a.size > 1)
	{
		n = pop_front(&ctx->a);
		push_back(&ctx->a, n);
	}
	if (ctx->b.size > 1)
	{
		n = pop_front(&ctx->b);
		push_back(&ctx->b, n);
	}
	ctx->ops[ctx->op_len++] = OP_RR;
}
