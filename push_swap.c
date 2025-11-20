/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:08:59 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/05 17:25:26 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_head(char **not_sorted, int len)
{
	int		i;
	int		j;
	int		count;
	
	i = 0;
	while (not_sorted[i])
	{
		j = 0;
		count = 0;
		while (not_sorted[j])
		{
			if (ft_atoi(not_sorted[i]) > ft_atoi(not_sorted[j]))
				count++;
			j++;
		}
		if (count ==  0)
			return (i);
	}
	return (i);
}