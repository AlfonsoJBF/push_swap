/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:36:12 by albustos          #+#    #+#             */
/*   Updated: 2026/06/26 14:13:34 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (d < s)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
