/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:48:13 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 21:43:21 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_best_rr(t_move_cost *best, t_abinfo *ab)
{
	t_move_cost	cand;
	int			cost;

	cand.ra = ab->up_a;
	cand.rra = 0;
	cand.rb = ab->up_b;
	cand.rrb = 0;
	if (ab->up_a > ab->up_b)
		cost = ab->up_a;
	else
		cost = ab->up_b;
	cand.total = cost;
	if (cand.total < best->total)
		*best = cand;
}

static void	update_best_rrr(t_move_cost *best, t_abinfo *ab)
{
	t_move_cost	cand;
	int			cost;

	cand.ra = 0;
	cand.rra = ab->down_a;
	cand.rb = 0;
	cand.rrb = ab->down_b;
	if (ab->down_a > ab->down_b)
		cost = ab->down_a;
	else
		cost = ab->down_b;
	cand.total = cost;
	if (cand.total < best->total)
		*best = cand;
}


static void	update_best_ra_rrb(t_move_cost *best, t_abinfo *ab)
{
	t_move_cost	cand;

	cand.ra = ab->up_a;
	cand.rra = 0;
	cand.rb = 0;
	cand.rrb = ab->down_b;
	cand.total = ab->up_a + ab->down_b;
	if (cand.total < best->total)
		*best = cand;
}

static void	update_best_rra_rb(t_move_cost *best, t_abinfo *ab)
{
	t_move_cost	cand;

	cand.ra = 0;
	cand.rra = ab->down_a;
	cand.rb = ab->up_b;
	cand.rrb = 0;
	cand.total = ab->down_a + ab->up_b;
	if (cand.total < best->total)
		*best = cand;
}

void	compute_best_pattern(t_move_cost *cand, t_abinfo *ab)
{
	t_move_cost	best;

	best.total = INT_MAX;
	update_best_rr(&best, ab);
	update_best_rrr(&best, ab);
	update_best_ra_rrb(&best, ab);
	update_best_rra_rb(&best, ab);
	*cand = best;
}

