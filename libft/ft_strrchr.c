/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:59 by amantara          #+#    #+#             */
/*   Updated: 2022/02/04 16:13:05 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*str_copy;
	int				i;
	unsigned char	ch;

	ch = (unsigned char) c;
	str_copy = (char *)str;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str_copy[i] == ch)
			return (&str_copy[i]);
		i--;
	}
	return (0);
}
