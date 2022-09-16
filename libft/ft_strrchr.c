/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:11:32 by tmerida-          #+#    #+#             */
/*   Updated: 2022/01/31 18:54:54 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	c1;
	size_t	len;

	s1 = (char *)s;
	len = ft_strlen(s1);
	c1 = (char)c;
	while (len > 0)
	{
		if (s1[len] == c1)
			return (&s1[len]);
		len--;
	}
	if (s1[len] == c1)
		return (&s1[len]);
	return (NULL);
}
