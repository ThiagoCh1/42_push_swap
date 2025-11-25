/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:29:41 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/25 19:51:41 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_index(t_stack *a, int x)
{
	int i;
	int best_i;
	int value;
	int best_value = INT_MAX;

	i = 0;
	best_i = -1;
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
}