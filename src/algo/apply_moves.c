/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:50:46 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 21:11:54 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_double_rot(t_ctx *ctx, t_move_cost *move)
{
	while (move->ra > 0 && move->rb > 0)
	{
		op_rr(ctx);
		move->ra--;
		move->rb--;
	}
	while (move->rra > 0 && move->rrb > 0)
	{
		op_rrr(ctx);
		move->rra--;
		move->rrb--;
	}
}

static void	apply_single_rot_a(t_ctx *ctx, t_move_cost *move)
{
	while (move->ra > 0)
	{
		op_ra(ctx);
		move->ra--;
	}
	while (move->rra > 0)
	{
		op_rra(ctx);
		move->rra--;
	}
}

static void	apply_single_rot_b(t_ctx *ctx, t_move_cost *move)
{
	while (move->rb > 0)
	{
		op_rb(ctx);
		move->rb--;
	}
	while (move->rrb > 0)
	{
		op_rrb(ctx);
		move->rrb--;
	}
}

void	apply_move(t_ctx *ctx, t_move_cost *move)
{
	apply_double_rot(ctx, move);
	apply_single_rot_b(ctx, move);
	apply_single_rot_a(ctx, move);
	op_pa(ctx);
}
