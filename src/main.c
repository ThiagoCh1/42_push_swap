/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:09:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/28 00:32:38 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		*keep;

	if (argc >= 2)
	{
		if (fill_stack(&ctx, argv[1]) == -1)
		{
			ft_printf("%s", ERROR_MSG);
			return (-1);
		}
		if (ctx.a.size <= 1)
			return (ft_printf("%s", ERROR_MSG), -1);
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
	return (0);
}
