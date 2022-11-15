/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:07:51 by mbelouar          #+#    #+#             */
/*   Updated: 2022/11/14 22:52:25 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(elementCount * elementSize);
	if (!str)
		return (0);
	while (i < elementSize * elementCount)
		str[i++] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final_str;
	int		size_total;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size_total = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	final_str = (char *)malloc(sizeof(char) * (size_total + 1));
	if (!final_str)
		return (NULL);
	while (s1[++i])
		final_str[i] = s1[i];
	j = 0;
	while (s2[j])
		final_str[i++] = s2[j++];
	final_str[size_total] = '\0';
	free(s1);
	return (final_str);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (0);
}

char	*ft_fill_rest(char *stock_arr, char *new_str, int i)
{
	int	j;

	j = 0;
	i++;
	while (stock_arr[i])
		new_str[j++] = stock_arr[i++];
	new_str[j] = 0;
	return (new_str);
}
