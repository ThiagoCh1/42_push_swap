/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:09:38 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/23 02:13:27 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc == 2)
	{
		fill_stack(&ctx, argv[1]);
		index_stack(&ctx.a);
		just_debug(&ctx.a);
	}
	return (0);
}
