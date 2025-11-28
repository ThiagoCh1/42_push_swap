/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:08:56 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/28 00:27:57 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>

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
void	push_front(t_stack *s, int value);
void	push_back(t_stack *s, int value);
int		pop_front(t_stack *s);
int		pop_back(t_stack *s);
void	stack_init(t_stack *s, int size);
void	stack_free(t_stack *s);
int		stack_empty(t_stack *s);
void	print_stack(t_stack *s);
int		fill_stack(t_ctx *ctx, char *s);
void	just_debug(t_stack *s);
void	index_stack(t_stack *a);
int		is_sorted(t_stack *a);
int		*build_lis_keep(t_stack *a);
void	push_non_lis(t_ctx *ctx, int *keep);
void	rotate_a(t_ctx *ctx);
void	normalize_a(t_ctx *ctx);
void	print_ops(t_ctx *ctx);
int		is_valid_int(const char *s);

// ops_push.c
void	op_pa(t_ctx *ctx);
void	op_pb(t_ctx *ctx);

// ops_swap.c
void	op_sa(t_ctx *ctx);
void	op_sb(t_ctx *ctx);
//void    op_ss(t_ctx *ctx);

// ops_rotate.c
void	op_ra(t_ctx *ctx);
void	op_rb(t_ctx *ctx);
//void    op_rr(t_ctx *ctx);

// ops_reverse.c
void	op_rra(t_ctx *ctx);
void	op_rrb(t_ctx *ctx);
//void	op_rrr(t_ctx *ctx);


#endif
