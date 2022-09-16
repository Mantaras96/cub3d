/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:53:38 by tmerida-          #+#    #+#             */
/*   Updated: 2022/01/31 18:45:54 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	l;
	unsigned int	j;
	unsigned int	r1;
	unsigned int	r2;

	l = ft_strlen(dest);
	j = 0;
	r1 = ft_strlen(dest);
	r2 = ft_strlen(src);
	if (size < 1)
		return (r2 + size);
	while (src[j] && l < size - 1)
	{
		dest[l] = src[j];
		l++;
		j++;
	}
	dest[l] = '\0';
	if (size < r1)
		return (r2 + size);
	else
		return (r1 + r2);
}
