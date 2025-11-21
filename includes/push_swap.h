/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:08:56 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/21 00:52:20 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../42_libft/libft.h"
# include <stdio.h>

# define MAX_OPS 200000
# define ERROR_MSG "Error\n"

typedef struct s_stack
{
	int	*data;
	int	cap;
	int	size;
	int	head;
}	t_stack;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_ctx
{
	t_stack		a;
	t_stack		b;
	t_op		ops[MAX_OPS];
	int			op_len;
}	t_ctx;

int		stack_at(const t_stack *s, int i);
void	stack_set(t_stack *s, int i, int value);

#endif
