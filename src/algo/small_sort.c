/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:21:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/12/07 16:27:52 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_to_top(t_ctx *ctx, int idx)
{
	int	n;
	int	steps;

	n = ctx->a.size;
	if (idx <= n / 2)
	{
		steps = idx;
		while (steps-- > 0)
			op_ra(ctx);
	}
	else
	{
		steps = n - idx;
		while (steps-- > 0)
			op_rra(ctx);
	}
}

static void	push_min_to_b(t_ctx *ctx)
{
	int	idx_min;

	idx_min = get_min_index(&ctx->a);
	rotate_a_to_top(ctx, idx_min);
	op_pb(ctx);
}

static void	sort_two(t_ctx *ctx)
{
	int	a;
	int	b;

	a = stack_at(&ctx->a, 0);
	b = stack_at(&ctx->a, 1);
	if (a > b)
		op_sa(ctx);
}

static void	sort_three(t_ctx *ctx)
{
	int	a;
	int	b;
	int	c;

	a = stack_at(&ctx->a, 0);
	b = stack_at(&ctx->a, 1);
	c = stack_at(&ctx->a, 2);
	if (a > b && a < c)
		op_sa(ctx);
	else if (a > b && b > c)
	{
		op_sa(ctx);
		op_rra(ctx);
	}
	else if (a > c && b < c)
		op_ra(ctx);
	else if (a < b && a > c)
		op_rra(ctx);
	else if (a < c && b > c)
	{
		op_sa(ctx);
		op_ra(ctx);
	}
}

void	sort_upto_five(t_ctx *ctx)
{
	int	x;
	int	target;

	if (ctx->a.size == 2)
		sort_two(ctx);
	else if (ctx->a.size == 3)
		sort_three(ctx);
	else
	{
		while (ctx->a.size > 3)
			push_min_to_b(ctx);
		sort_three(ctx);
		while (ctx->b.size > 0)
		{
			x = stack_at(&ctx->b, 0);
			target = find_target_index(&ctx->a, x);
			rotate_a_to_top(ctx, target);
			op_pa(ctx);
		}
		normalize_a(ctx);
	}
}
