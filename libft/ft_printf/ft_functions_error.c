/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:54:52 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/06 15:26:59 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_base_err(int nbr, char *base)
{
	long	l;
	int		count;

	l = nbr;
	count = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (l < 0)
	{
		ft_putchar_fd('-', 2);
		l = -l;
		count ++;
	}
	if (l >= (long)ft_strlen(base))
		count = count + ft_putnbr_base_err(l / ft_strlen(base), base);
	ft_putchar_fd(base[(l % ft_strlen(base))], 2);
	count++;
	return (count);
}

int	ft_putnbr_base_un_err(unsigned int nbr, char *base)
{
	int		count;

	count = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (nbr >= (unsigned int)ft_strlen(base))
		count = count + ft_putnbr_base_un_err(nbr / ft_strlen(base), base);
	ft_putchar_fd(base[(nbr % ft_strlen(base))], 2);
	count++;
	return (count);
}

int	ft_putpointer_err(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
		return (ft_putstring_err("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count = count + ft_putstring_err("0x");
	count = count + ft_putnbr_base_ptr_err(address, "0123456789abcdef");
	return (count);
}

int	ft_putnbr_base_ptr_err(unsigned long nbr, char *base)
{
	int		count;

	count = 0;
	if (ft_strlen(base) < 2)
		return (0);
	if (nbr >= (unsigned long)ft_strlen(base))
		count = count + ft_putnbr_base_ptr_err(nbr / ft_strlen(base), base);
	ft_putchar_fd(base[(nbr % ft_strlen(base))], 2);
	count++;
	return (count);
}

int	ft_putstring_err(char *string)
{
	int	i;

	if (string == NULL)
		string = "(null)";
	i = 0;
	while (string[i] != '\0')
	{
		ft_putchar_fd(string[i], 2);
		i++;
	}
	return (i);
}
