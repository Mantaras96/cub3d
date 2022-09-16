/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:32:02 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/01 20:51:08 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i] != 0)
	{
		s3[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		s3[j++] = s2[i];
		i++;
	}
	s3[j] = 0;
	return (s3);
}
