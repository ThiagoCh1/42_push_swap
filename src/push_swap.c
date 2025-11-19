/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:19:37 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/19 23:46:16 by thribeir         ###   ########.fr       */
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
		sorted[i] = count;
		i++;
	}
	return (sorted);
}

t_list	*make_list(char *arg)
{
	t_node	*item;
	t_list	*a;
	char	**num_arr;
	int		i;
	int		*sorted;

	i = 0;
	a = NULL;
	num_arr = ft_split(arg, ' ');
	while (num_arr[i])
		i++;
	sorted = sorted_arr(num_arr, i);
	i--;
	while (i >= 0)
	{
		item = malloc(sizeof(t_node));
		item->value = ft_atoi(num_arr[i]);
		item->index = sorted[i];
		ft_lstadd_front(&a, ft_lstnew(item));
		i--;
	}
	free(num_arr);
	free(sorted);
	return a;
}

int main(int argc, char **argv)
{
	t_list	*a;
	//t_list	*b;

	if (argc == 2)
	{
		a = make_list(argv[1]);
		t_list	*tmp;
		t_node	*data;

		tmp = a;
		while (tmp)
		{
			data = (t_node *)tmp->content;
			printf("value: %d | index: %d\n", data->value, data->index);
			tmp = tmp->next;
		}
	}
}
