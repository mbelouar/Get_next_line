/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:22:08 by mbelouar          #+#    #+#             */
/*   Updated: 2022/11/13 17:25:30 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *stock_arr)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stock_arr = ft_strjoin(stock_arr, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stock_arr);
}

char	*ft_fill_line(char *stock_arr, char *snew, int i)
{
	while (stock_arr[i])
	{
		if (stock_arr[i] != '\n')
		{
			snew[i] = stock_arr[i];
			i++;
		}
		if (stock_arr[i] == '\n')
		{
			snew[i] = '\n';
			snew[i + 1] = '\0';
			break ;
		}
		else
			snew[i] = '\0';
	}
	return (snew);
}

char	*ft_get_line(char *stock_arr)
{
	char	*snew;
	char	*str_after_fill;
	int		i;

	i = 0;
	if (!stock_arr[0])
		return (NULL);
	while (stock_arr[i] && stock_arr[i] != '\n')
		i++;
	snew = malloc(sizeof(char) * (i + 2));
	if (!snew)
		return (NULL);
	i = 0;
	str_after_fill = ft_fill_line(stock_arr, snew, i);
	return (str_after_fill);
}

char	*stock_rest(char *stock_arr)
{
	char	*new_str;
	char	*str_after_fill;
	int		i;

	i = 0;
	if (!stock_arr[i])
	{
		free(stock_arr);
		return (NULL);
	}
	while (stock_arr[i] && stock_arr[i] != '\n')
		i++;
	new_str = ft_calloc(sizeof(char), (ft_strlen(stock_arr) - i + 1));
	if (!new_str)
		return (NULL);
	if (i == ft_strlen(stock_arr))
	{
		if (new_str)
			free(new_str);
		free(stock_arr);
		return (NULL);
	}
	str_after_fill = ft_fill_rest(stock_arr, new_str, i);
	free(stock_arr);
	return (str_after_fill);
}

char	*get_next_line(int fd)
{
	static char	*stock_arr[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock_arr[fd] = ft_read(fd, stock_arr[fd]);
	if (!stock_arr[fd])
		return (NULL);
	line = ft_get_line(stock_arr[fd]);
	stock_arr[fd] = stock_rest(stock_arr[fd]);
	return (line);
}
