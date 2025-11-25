/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:24:29 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/25 13:49:09 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *s, int value)
{
	if (s->size == s->cap)
		return ;
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = value;
	s->size++;
}

void	push_back(t_stack *s, int value)
{
	if (s->size == s->cap)
		return ;
	stack_set(s, s->size, value);
	s->size++;
}

int	pop_front(t_stack *s)
{
	int	first;

	first = stack_at(s, 0);
	s->head = (s->head + 1) % s->cap;
	s->size--;
	return (first);
}

int	pop_back(t_stack *s)
{
	int	back;

	back = stack_at(s, s->size - 1);
	s->size--;
	return (back);
}
