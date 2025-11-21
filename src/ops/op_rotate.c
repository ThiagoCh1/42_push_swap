/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:30:19 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/21 23:05:37 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_ctx *ctx)
{
	if (ctx->a.size < 2)
		return ;
	ctx->a.head = (ctx->a.head + 1) % ctx->a.cap;
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_RA;
}

void	op_rb(t_ctx *ctx)
{
	if (ctx->b.size < 2)
		return ;
	ctx->b.head = (ctx->b.head + 1) % ctx->b.cap;
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_RB;
}
