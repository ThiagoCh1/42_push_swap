/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:00:48 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/21 23:11:31 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_ctx *ctx)
{
	if (ctx->a.size < 2)
		return ;
	ctx->a.head = (ctx->a.head + ctx->a.cap - 1) % ctx->a.cap;
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_RRA;
}

void	op_rrb(t_ctx *ctx)
{
	if (ctx->b.size < 2)
		return ;
	ctx->b.head = (ctx->b.head + ctx->b.cap - 1) % ctx->b.cap;
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_RRB;
}
