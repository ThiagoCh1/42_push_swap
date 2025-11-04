/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:19:37 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/04 18:59:13 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*sorted_arr(char **not_sorted, int len)
{
	int		i;
	int		j;
	int		*sorted;
	int		count;
	
	sorted = malloc(len * sizeof(int));
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
		sorted[count] = ft_atoi(not_sorted[i]);
		i++;
	}
	sorted[i] = '\0';
	return (sorted);
}

int main(int argc, char **argv)
{
	char	**num_arr;
	//t_list	*a;
	int		i;
	int		*sorted;

	i = 0;
	if (argc == 2)
	{
		num_arr = ft_split(argv[1], ' ');
		while (num_arr[i])
			i++;
		//a = ft_calloc(i, sizeof(t_list));
		sorted = sorted_arr(num_arr, i + 1);
		printf("%d, %d, %d", sorted[0], sorted[1], sorted[2]);
	}
}