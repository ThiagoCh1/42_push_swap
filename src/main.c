/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:09:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 20:43:33 by thribeir         ###   ########.fr       */
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
	if (ctx.a.size > 1)
		run_sort(&ctx);
	//just_debug(&ctx.a);
	free_all(&ctx);
	return (0);
}


/*int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		*keep;

	keep = NULL;
	if (argc >= 2)
	{
		if (fill_stack(&ctx, argv[1]) == -1 || has_duplicates(&ctx.a))
		{
			ft_printf("%s", ERROR_MSG);
			free_all(&ctx, keep);
			return (-1);
		}
		if (ctx.a.size <= 1)
			return (free_all(&ctx, keep), 0);
		index_stack(&ctx.a);
		keep = build_lis_keep(&ctx.a);
		push_non_lis(&ctx, keep);
		while (ctx.b.size > 0)
		{
    		rotate_a(&ctx);
    		op_pa(&ctx);
		}
		normalize_a(&ctx);
		just_debug(&ctx.a);
		print_ops(&ctx);
	}
}*/
