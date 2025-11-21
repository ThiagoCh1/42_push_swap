/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:29:29 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/21 22:15:48 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_ctx *ctx)
{
	int	n;

	if (stack_empty(&ctx->a))
		return ;
	n = pop_front(&ctx->a);
	push_front(&ctx->b, n);
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_PB;
}

void	op_pa(t_ctx *ctx)
{
	int	n;

	if (stack_empty(&ctx->b))
		return ;
	n = pop_front(&ctx->b);
	push_front(&ctx->a, n);
	if (ctx->op_len < MAX_OPS)
		ctx->ops[ctx->op_len++] = OP_PA;
}
