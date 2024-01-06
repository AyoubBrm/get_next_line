/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:31:29 by abouram           #+#    #+#             */
/*   Updated: 2022/11/15 00:31:32 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)&s[i]);
}

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	void	*take;

	take = malloc(count * size);
	if (take)
	{
		ft_bzero(take, count * size);
		return (take);
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	char	*temp;

	temp = s1;
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	p = (char *)ft_calloc((ft_strlen(temp) + ft_strlen(s2) + 1), sizeof(char));
	i = 0;
	if (!p)
		return (NULL);
	while (*s1)
	{
		p[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		p[i] = *s2++;
		i++;
	}
	free(temp);
	return (p);
}
