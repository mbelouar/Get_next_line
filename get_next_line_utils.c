/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:07:51 by mbelouar          #+#    #+#             */
/*   Updated: 2022/11/01 23:40:46 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)

{
	char	*final_str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	i = 0;
	j = 0;
	final_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!final_str)
		return (NULL);
	while (i < len_s1)
		final_str[j++] = s1[i++];
	i = 0;
	while (i < len_s2)
		final_str[j++] = s2[i++];
	final_str[j] = '\0';
    free(s1);
	return (final_str);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (0);
}