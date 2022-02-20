/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanaser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:43:57 by amanaser          #+#    #+#             */
/*   Updated: 2021/02/16 17:47:57 by amanaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
int			check_new_line(char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_split(char *str);
int			ft_strlen(const char *s);
char		*new_str(char *str);
void		*ft_memmove(void *dst, const void *src, int len);

#endif
