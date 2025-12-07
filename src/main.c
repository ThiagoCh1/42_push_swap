/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:09:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/12/07 16:56:20 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_ctx *ctx)
{
	stack_free(&ctx->a);
	stack_free(&ctx->b);
}

int	init_and_fill(t_ctx *ctx, char *joined)
{
	if (fill_stack(ctx, joined) == -1)
		return (-1);
	if (has_duplicates(&ctx->a))
	{
		free_all(ctx);
		return (-1);
	}
	return (0);
}

void	run_sort(t_ctx *ctx)
{
	int	*keep;

	index_stack(&ctx->a);
	keep = build_lis_keep(&ctx->a);
	if (!keep)
		return ;
	push_non_lis(ctx, keep);
	free(keep);
	insert_all_from_b(ctx);
	print_ops(ctx);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	char	*joined;

	if (argc < 2)
		return (0);
	joined = join_args(argc, argv);
	if (!joined)
		return (ft_putendl_fd("Error", 2), 1);
	if (init_and_fill(&ctx, joined) == -1)
		return (free(joined), ft_putendl_fd("Error", 2), 1);
	free(joined);
	if (is_sorted(&ctx.a))
		return (free_all(&ctx), 0);
	if (ctx.a.size <= 5)
	{
		sort_upto_five(&ctx);
		print_ops(&ctx);
	}
	else
		run_sort(&ctx);
	free_all(&ctx);
	return (0);
}
