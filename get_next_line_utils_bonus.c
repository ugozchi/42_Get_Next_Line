/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:06:54 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/30 00:12:11 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*return the length*/
size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

/*ft_strjoin allocates and returns a new string, which is the result of the
  concatenation of s1 and s2*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	char	*output_ptr;

	output = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output_ptr = output;
	while (*s1)
		*output_ptr++ = *s1++;
	while (*s2)
		*output_ptr++ = *s2++;
	*output_ptr = '\0';
	return (output);
}

/*ft_strchr locates the character c in str and returns its position*/
char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	if (!str || !*str)
		return (NULL);
	ptr = (char *)str;
	while (*ptr && (unsigned char)*ptr != (unsigned char)c)
		ptr++;
	if ((unsigned char)*ptr == (unsigned char)c)
		return (ptr);
	else
		return (NULL);
}

/*ft_strlcpy copies up to size - 1 characters from the NUL-terminated string
src to dst, NUL-terminating the result.*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	while (src[length])
		length++;
	if (size == 0)
		return (length);
	while (--size && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (length);
}
