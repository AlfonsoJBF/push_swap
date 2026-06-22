/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:16:08 by albustos          #+#    #+#             */
/*   Updated: 2026/05/20 18:32:26 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	s = (unsigned char *)dest;
	while (i < n)
	{
		s[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
