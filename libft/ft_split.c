/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:21:37 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/04 21:44:43 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contador(char const *s, char c)
{
	int	i;
	int	init;
	int	numword;

	numword = 0;
	i = -1;
	init = -1;
	while (s[++i])
	{
		if (init == -1 && s[i] != c)
			init = 1;
		if (init != -1 && s[i] == c)
		{	
			numword += 1;
			init = -1;
		}
	}
	if (init == 1)
		++numword;
	return (numword);
}

char	*ft_printword(char const *str, int inicio, int fin)
{
	size_t	i;
	char	*palabra;

	i = 0;
	palabra = malloc(sizeof(char ) * (fin - inicio + 1));
	if (!palabra)
		return (NULL);
	while (inicio < fin)
	{
		palabra[i] = str[inicio];
		i++;
		inicio++;
	}
	palabra[i] = '\0';
	return (palabra);
}

void	split_string(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		activado;

	i = 0;
	j = 0;
	activado = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && activado < 0)
		{
			activado = i;
		}
		else if ((s[i] == c || i == ft_strlen(s)) && activado >= 0)
		{
			str[j++] = ft_printword(s, activado, i);
			activado = -1;
		}
		i++;
	}
	str[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		palabr;
	char	**str;

	if (!s)
		return (NULL);
	palabr = contador(s, c);
	str = malloc(sizeof(char *) * (palabr + 1));
	if (!str)
		return (NULL);
	split_string(str, s, c);
	return (str);
}
