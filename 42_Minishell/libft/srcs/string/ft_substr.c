/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:09:20 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 11:41:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (start > ft_strlen(s) || (start > ft_strlen(s) && len > ft_strlen(s)))
	{
		i = 0;
		new_str = (char *)malloc(sizeof(char));
		ft_strlcpy(new_str, "", 1);
		return (new_str);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && i + start < ft_strlen(s) && s[i] != '\0')
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (s == NULL || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
