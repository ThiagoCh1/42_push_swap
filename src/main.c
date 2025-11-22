/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:09:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/22 20:16:13 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_ctx *ctx, char *s)
{
	char	**num_arr;
	int		i;
	int		value;

	i = 0;
	num_arr = ft_split(s, ' ');
	while (num_arr[i])
		i++;
	stack_init(&ctx->a, i);
	stack_init(&ctx->b, i);
	ctx->op_len = 0;
	i = 0;
	while (num_arr[i])
	{
		value = ft_atoi(num_arr[i]);
		push_back(&ctx->a, value);
		i++;
	}
	i = 0;
	while (num_arr[i])
	{
		free(num_arr[i]);
		i++;
	}
	free(num_arr);
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
