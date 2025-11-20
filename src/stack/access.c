/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:36:40 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/20 18:17:23 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	stack_at(const t_stack *s, int i)
{
	int	num;
	int actual;
	
	actual = (s->head + i) % s->cap;
	num = s->data[actual];
	return (num);
}

void stack_set(t_stack *s, int i, int value)
{
	int actual;
	
	actual = (s->head + i) % s->cap;
	s->data[actual] = value;
}