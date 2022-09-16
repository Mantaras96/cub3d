/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:28:19 by tmerida-          #+#    #+#             */
/*   Updated: 2022/01/27 20:54:09 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s1;
	size_t	cs;

	cs = count * size;
	s1 = malloc (cs);
	if (s1 == 0)
		return (s1);
	ft_bzero (s1, cs);
	return (s1);
}
