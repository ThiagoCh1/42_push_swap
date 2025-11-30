/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:34:12 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 20:34:31 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pattern_up_up(t_move_cost *c, t_abinfo *ab)
{
	c->ra = ab->up_a;
	c->rra = 0;
	c->rb = ab->up_b;
	c->rrb = 0;
	c->total = c->ra + c->rb;
}

void	pattern_down_down(t_move_cost *c, t_abinfo *ab)
{
	c->ra = 0;
	c->rra = ab->down_a;
	c->rb = 0;
	c->rrb = ab->down_b;
	c->total = c->rra + c->rrb;
}

void	pattern_up_down(t_move_cost *c, t_abinfo *ab)
{
	c->ra = ab->up_a;
	c->rra = 0;
	c->rb = 0;
	c->rrb = ab->down_b;
	c->total = c->ra + c->rrb;
}

void	pattern_down_up(t_move_cost *c, t_abinfo *ab)
{
	c->ra = 0;
	c->rra = ab->down_a;
	c->rb = ab->up_b;
	c->rrb = 0;
	c->total = c->rra + c->rb;
}
