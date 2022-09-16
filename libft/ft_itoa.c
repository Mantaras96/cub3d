/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:35:01 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/04 18:57:52 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_contador(long int num)
{
	size_t	i;

	i = 0;
	if (num == 0)
	{
		return (1);
	}
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_conversion(long int n, char *s1, long int i)
{
	if (n < 0)
	{
		s1[0] = '-';
		n *= -1;
	}	
	if (n >= 10)
	{
		ft_conversion((n / 10), s1, (i - 1));
	}
	s1[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	i = ft_contador(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
	{
		return (0);
	}
	str[i--] = '\0';
	ft_conversion(n, str, i);
	return (str);
}
