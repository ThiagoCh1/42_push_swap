/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thribeir <thribeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:56:39 by thribeir          #+#    #+#             */
/*   Updated: 2025/11/30 17:06:44 by thribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_len(int argc, char **argv)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		len += j + 1;
		i++;
	}
	return (len);
}

static void	copy_arg(char *dst, char *src, int *k)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[*k] = src[i];
		(*k)++;
		i++;
	}
	dst[(*k)++] = ' ';
}

char	*join_args(int argc, char **argv)
{
	char	*res;
	int		len;
	int		i;
	int		k;

	len = total_len(argc, argv);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		copy_arg(res, argv[i], &k);
		i++;
	}
	if (k > 0 && res[k - 1] == ' ')
		res[k - 1] = '\0';
	else
		res[k] = '\0';
	return (res);
}
