/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:06:15 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 11:48:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX) / size)
		return (NULL);
	array = malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, nmemb * size);
	return (array);
}

/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(sizeof(nmemb * size));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
*/
