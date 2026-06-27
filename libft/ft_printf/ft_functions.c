/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:54:52 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/25 13:21:17 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_base(int nbr, char *base)
{
	long	l;
	int		count;

	l = nbr;
	count = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (l < 0)
	{
		ft_putchar_fd('-', 1);
		l = -l;
		count ++;
	}
	if (l >= (long)ft_strlen(base))
		count = count + ft_putnbr_base(l / ft_strlen(base), base);
	ft_putchar_fd(base[(l % ft_strlen(base))], 1);
	count++;
	return (count);
}

int	ft_putnbr_base_un(unsigned int nbr, char *base)
{
	int		count;

	count = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (nbr >= (unsigned int)ft_strlen(base))
		count = count + ft_putnbr_base_un(nbr / ft_strlen(base), base);
	ft_putchar_fd(base[(nbr % ft_strlen(base))], 1);
	count++;
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
		return (ft_putstring("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count = count + ft_putstring("0x");
	count = count + ft_putnbr_base_ptr(address, "0123456789abcdef");
	return (count);
}

int	ft_putnbr_base_ptr(unsigned long nbr, char *base)
{
	int		count;

	count = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (nbr >= (unsigned long)ft_strlen(base))
		count = count + ft_putnbr_base_ptr(nbr / ft_strlen(base), base);
	ft_putchar_fd(base[(nbr % ft_strlen(base))], 1);
	count++;
	return (count);
}

int	ft_putstring(char *string)
{
	int	i;

	if (string == NULL)
		string = "(null)";
	i = 0;
	while (string[i] != '\0')
	{
		ft_putchar_fd(string[i], 1);
		i++;
	}
	return (i);
}
