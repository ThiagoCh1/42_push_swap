/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:53:05 by thribeir          #+#    #+#             */
/*   Updated: 2025/12/07 16:55:45 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_len(char **arr)
{
	int	len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	init_ctx_stacks(t_ctx *ctx, int len)
{
	stack_init(&ctx->a, len);
	stack_init(&ctx->b, len);
	if (!ctx->a.data || !ctx->b.data)
	{
		stack_free(&ctx->a);
		stack_free(&ctx->b);
		return (0);
	}
	ctx->op_len = 0;
	return (1);
}

void	fill_a(t_stack *a, char **arr)
{
	int	i;
	int	value;

	i = 0;
	while (arr[i])
	{
		value = ft_atoi(arr[i]);
		push_back(a, value);
		i++;
	}
}

int	fill_stack(t_ctx *ctx, char *s)
{
	char	**num_arr;
	int		len;
	int		i;

	i = 0;
	num_arr = ft_split(s, ' ');
	if (!num_arr)
		return (-1);
	len = split_len(num_arr);
	if (!init_ctx_stacks(ctx, len))
		return (free_split(num_arr), -1);
	while (num_arr[i])
	{
		if (!is_valid_int(num_arr[i]))
		{
			free_split(num_arr);
			stack_free(&ctx->a);
			stack_free(&ctx->b);
			return (-1);
		}
		i++;
	}
	fill_a(&ctx->a, num_arr);
	return (free_split(num_arr), 1);
}
