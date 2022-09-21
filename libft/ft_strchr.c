/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:49:59 by amantara          #+#    #+#             */
/*   Updated: 2022/02/04 16:12:23 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  
	The C library function char *strchr(const char *str, int c) 
	searches for the first occurrence of the character c (an unsigned char) 
	in the string pointed to by the argument str.
*/
char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	ch;

	ch = (unsigned char) c;
	str = (char *)s;
	while (*str != ch)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
