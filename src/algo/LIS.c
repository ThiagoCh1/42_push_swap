/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:27:50 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 17:35:35 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lis_fill_keep(int *prev, int *keep, int best, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		keep[i] = 0;
		i++;
	}
	i = best;
	while (i != -1)
	{
		keep[i] = 1;
		i = prev[i];
	}
}

static int	find_best(int *len, int n)
{
	int	best;
	int	i;

	i = 0;
	best = 0;
	while (i < n)
	{
		if (len[best] < len[i])
			best = i;
		i++;
	}
	return (best);
}

static void	lis_lp(t_stack *a, int *len, int *prev)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		len[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (stack_at(a, j) < stack_at(a, i) && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*build_lis_keep(t_stack *a)
{
	int	*len;
	int	*prev;
	int	*keep;
	int	best;

	len = malloc(sizeof(int) * a->size);
	prev = malloc(sizeof(int) * a->size);
	keep = malloc(sizeof(int) * a->size);
	if (!len || !prev || !keep)
	{
		free(len);
		free(prev);
		free(keep);
		return (NULL);
	}
	lis_lp(a, len, prev);
	best = find_best(len, a->size);
	lis_fill_keep(prev, keep, best, a->size);
	free(len);
	free(prev);
	return (keep);
}
