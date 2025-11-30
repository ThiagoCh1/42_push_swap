/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:29:41 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 21:13:24 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_move_cost(t_move_cost *m)
{
	m->ra = 0;
	m->rra = 0;
	m->rb = 0;
	m->rrb = 0;
	m->total = INT_MAX;
	m->index_b = 0;
}

static void	fill_abinfo(t_ctx *ctx, int index_b, t_abinfo *ab)
{
	int	x;
	int	t;

	x = stack_at(&ctx->b, index_b);
	t = find_target_index(&ctx->a, x);
	ab->up_a = t;
	ab->down_a = ctx->a.size - t;
	ab->up_b = index_b;
	ab->down_b = ctx->b.size - index_b;
}

static void	find_best_move(t_ctx *ctx, t_move_cost *best)
{
	int			i;
	t_abinfo	ab;
	t_move_cost	cand;

	init_move_cost(best);
	i = 0;
	while (i < ctx->b.size)
	{
		fill_abinfo(ctx, i, &ab);
		compute_best_pattern(&cand, &ab);
		if (cand.total < best->total)
			*best = cand;
		i++;
	}
}

void	insert_all_from_b(t_ctx *ctx)
{
	t_move_cost	m;

	while (ctx->b.size > 0)
	{
		find_best_move(ctx, &m);
		apply_move(ctx, &m);
	}
	normalize_a(ctx);
}

