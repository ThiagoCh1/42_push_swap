/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:13:34 by thribeir          #+#    #+#             */
/*   Updated: 2025/12/07 16:57:19 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s, int size)
{
	s->cap = size;
	s->size = 0;
	s->head = 0;
	s->data = malloc(sizeof(int) * size);
}

void	stack_free(t_stack *s)
{
	s->cap = 0;
	s->size = 0;
	s->head = 0;
	free(s->data);
	s->data = NULL;
}

int	stack_empty(t_stack *s)
{
	if (s->size == 0)
		return (1);
	return (0);
}

void	print_stack(t_stack *s)
{
	int	i;

	i = 0;
	ft_printf("Logical index: \n");
	while (i < s->size)
	{
		ft_printf("Logical index %d: %d\n", i, stack_at(s, i));
		i++;
	}
}

void	just_debug(t_stack *s)
{
	ft_printf("cap = %d \n size = %d \n head = %d \n",
		s->cap, s->size, s->head);
	print_stack(s);
}
