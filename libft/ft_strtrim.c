/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:33:33 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/04 21:33:43 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_principio(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (!(ft_strchr(set, s1[i])))
			return (i);
		i++;
	}
	return (i);
}

int	ft_final(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (!(ft_strchr(set, s1[len - 1 - i])))
			return (len - i);
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		principio;
	int		final;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	principio = ft_principio(s1, set);
	final = ft_final(s1, set);
	if (principio > final)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (final - principio + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + principio, final - principio + 1);
	return (str);
}
