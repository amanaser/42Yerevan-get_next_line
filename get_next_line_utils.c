/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:43:45 by amanaser          #+#    #+#             */
/*   Updated: 2021/02/16 17:56:44 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_new_line(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			++i;
		return (i);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len + 1;
	if (!s1 && !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memmove(str, s1, s1_len);
	ft_memmove(str + s1_len, s2, s2_len);
	str[len - 1] = '\0';
	free((char *)s1);
	return (str);
}

void	*ft_memmove(void *dst, const void *src, int len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*new_str(char *str)
{
	char	*result;
	int		i;
	int		j;
	int		res_len;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	res_len = ft_strlen(str) - i;
	if (!(result = (char *)malloc(sizeof(char) * (res_len + 1))))
		return (NULL);
	++i;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}
