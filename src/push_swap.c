/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:19:37 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/03 21:49:41 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**num_arr;
	t_list	*a;
	t_list	*b;
	int		i;

	i = 0;
	if (argc == 2)
	{
		num_arr = ft_split(argv[1], ' ');
		while (num_arr[i])
			i++;
		a = ft_calloc(i, sizeof(t_list));
		printf("%s, %s, %s", num_arr[0], num_arr[1], num_arr[2]);
	}
}