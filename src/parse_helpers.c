/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:04:15 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/28 02:51:43 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_digit_string(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (is_sign(s[i]))
		i++;
	if (!ft_isdigit((unsigned char)s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_in_int_range(const char *s)
{
	long long	nb;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	if (is_sign(s[i]))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	nb = 0;
	while (ft_isdigit((unsigned char)s[i]))
	{
		nb = nb * 10 + (s[i] - '0');
		if (sign == 1 && nb > INT_MAX)
			return (0);
		if ((sign == -1) && ((-nb) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_int(const char *s)
{
	if (!is_digit_string(s))
		return (0);
	if (!is_in_int_range(s))
		return (0);
	return (1);
}

int	has_duplicates(t_stack *s)
{
	int	i;
	int	j;
	int	v;

	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		v = stack_at(s, i);
		while (j < s->size)
		{
			if (v == stack_at(s, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
