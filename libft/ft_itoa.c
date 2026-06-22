/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:02:38 by albustos          #+#    #+#             */
/*   Updated: 2026/05/26 13:32:34 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int				len;
	unsigned int	number;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len = 1;
		number = -n;
	}
	else
		number = n;
	while (number != 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	nb;
	int		size;

	nb = n;
	size = count_len(n);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	if (nb < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		arr[0] = '0';
	arr[size] = '\0';
	while (nb != 0)
	{
		arr[size - 1] = (nb % 10) + 48;
		size--;
		nb = nb / 10;
	}
	return (arr);
}
