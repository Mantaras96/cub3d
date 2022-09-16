/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:02:23 by tmerida-          #+#    #+#             */
/*   Updated: 2022/01/22 18:54:21 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	if (c == '\v' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\t' || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	long long int	num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str++ - '0');
		if (num < INT_MIN && sign == -1)
			return (0);
		if (num > INT_MAX && sign == 1)
			return (-1);
	}
	return (sign * num);
}
