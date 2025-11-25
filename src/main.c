/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:09:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/25 18:12:21 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		*keep;

	if (argc == 2)
	{
		fill_stack(&ctx, argv[1]);
		index_stack(&ctx.a);
		just_debug(&ctx.a);
		keep = build_lis_keep(&ctx.a);
		push_non_lis(&ctx, keep);
		just_debug(&ctx.a);
		just_debug(&ctx.b);
		printf("A.data = %p\n", (void *)ctx.a.data);
		printf("B.data = %p\n", (void *)ctx.b.data);
	}
	return (0);
}
