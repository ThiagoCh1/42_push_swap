/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:00:48 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/25 18:44:19 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rra(t_ctx *ctx)
{
    int n;

    if (ctx->a.size < 2)
        return;
    n = pop_back(&ctx->a);
    push_front(&ctx->a, n);
    ctx->ops[ctx->op_len++] = OP_RRA;
}

void op_rrb(t_ctx *ctx)
{
    int n;

    if (ctx->b.size < 2)
        return;
    n = pop_back(&ctx->b);
    push_front(&ctx->b, n);
    ctx->ops[ctx->op_len++] = OP_RRB;
}
