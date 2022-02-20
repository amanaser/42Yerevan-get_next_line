/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:31:48 by amanaser          #+#    #+#             */
/*   Updated: 2021/02/11 20:31:59 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split(char *str)
{
	int		i;
	char	*result;
	char	*temp;

	temp = 0;
	result = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		++i;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char *str;
	int			b_index;

	b_index = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = malloc((sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (!check_new_line(str) && b_index != 0)
	{
		if ((b_index = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[b_index] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	*line = ft_split(str);
	str = new_str(str);
	if (b_index == 0)
		return (0);
	return (1);
}
