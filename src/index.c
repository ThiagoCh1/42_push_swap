/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 01:22:23 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/23 02:08:07 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ranking(t_stack *a)
{
	int	i;
	int	j;
	int	count;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * a->size);
	if (!temp)
		return (NULL);
	while (i < a->size)
	{
		j = 0;
		count = 0;
		while (j < a->size)
		{
			if (stack_at(a, i) > stack_at(a, j))
				count++;
			j++;
		}
		temp[i] = count;
		i++;
	}
	return (temp);
}

void	index_stack(t_stack *a)
{
	int		*temp;
	int		i;

	i = 0;
	temp = ranking(a);
	if (!temp)
		return ;
	while (i < a->size)
	{
		stack_set(a, i, temp[i]);
		i++;
	}
	free(temp);
}
