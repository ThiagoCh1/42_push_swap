/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:29:41 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/25 23:41:18 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *a)
{
	int	i;
	int	v;
	int	min_i;
	int min_v;

	i = 1;
	min_i = 0;
	min_v = stack_at(a, 0);
	while (i < a->size)
	{
		v = stack_at(a, i);
		if (v < min_v)
		{
			min_v = v;
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

int	find_target_index(t_stack *a, int x)
{
	int i;
	int best_i;
	int value;
	int best_value;

	i = 0;
	best_i = -1;
	best_value = INT_MAX;
	while (i < a->size)
	{
		value = stack_at(a, i);
		if (value > x && value < best_value)
		{
			best_value = value;
			best_i = i;
		}
		i++;
	}
	if (best_i != -1)
		return (best_i);
	return (get_min_index(a));
}

void	rotate_a(t_ctx *ctx)
{
	int	t;
	int	n;

	n = ctx->a.size;
	t = find_target_index(&ctx->a, stack_at(&ctx->b, 0));
	if (t <= n / 2)
	{
		while (t > 0)
		{
			op_ra(ctx);
			t--;
		}
	}
	else
	{
		t = n - t;
		while (t > 0)
		{
			op_rra(ctx);
			t--;
		}
	}
}

void	normalize_a(t_ctx *ctx)
{
	int	t;
	int	n;

	n = ctx->a.size;
	t = get_min_index(&ctx->a);
	if (t <= n / 2)
	{
		while (t > 0)
		{
			op_ra(ctx);
			t--;
		}
	}
	else
	{
		t = n - t;
		while (t > 0)
		{
			op_rra(ctx);
			t--;
		}
	}
}