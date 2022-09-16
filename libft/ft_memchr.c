/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:01:37 by tmerida-          #+#    #+#             */
/*   Updated: 2022/01/28 20:55:50 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*s2 == (unsigned char) c)
			return (s2);
		s2++;
	}
	return (NULL);
}
