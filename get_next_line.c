/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:07:33 by mbelouar          #+#    #+#             */
/*   Updated: 2022/11/01 23:51:13 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(int fd, char *stock_arr)
{
    char    *buffer;
    int     bytes_read;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        stock_arr = ft_strjoin(stock_arr, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (stock_arr);
}

char	*ft_get_line(char	*stock_arr)
{
	char	*snew;
	int		i;

	i = 0;
	while (stock_arr[i] && stock_arr[i] != '\n')
		i++;
	snew = malloc(sizeof(char) * (i + 2));
	if (!snew)
		return (NULL);
	i = 0;
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
			break;
		}
	}
	return (snew);
}

char	*stock_rest(char *stock_arr)
{
    char    *new_str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stock_arr[i] && stock_arr[i] != '\n')
		i++;
    new_str = malloc(sizeof(char) * (ft_strlen(stock_arr) - i + 1));
    if (!new_str)
        return (NULL);
    i++;
	while (stock_arr[i])
	{
		new_str[j] = stock_arr[i];
		j++;
		i++;
	}
    new_str[j] = 0;
    free(stock_arr);
	return (new_str);
}

char    *get_next_line(int fd)
{
    static char    *stock_arr;
    char    *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    stock_arr = ft_read(fd, stock_arr);
    if(!stock_arr)
        return NULL;
    line = ft_get_line(stock_arr);
    stock_arr = stock_rest(stock_arr);
    return (line);
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *r;
    
    r = get_next_line(fd);
    printf("Line 1 : %s", r);
    r = get_next_line(fd);
    printf("Line 2 : %s", r);
    r = get_next_line(fd);
    printf("Line 3 : %s", r);
}