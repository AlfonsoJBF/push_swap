/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:12:12 by mtapiado          #+#    #+#             */
/*   Updated: 2026/07/06 15:25:34 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_putchar_printf_err(char c)
{
	ft_putchar_fd(c, 2);
	return (1);
}

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_printf_err(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstring_err(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base_err(va_arg(args, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base_un_err(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base_un_err(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base_un_err(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putpointer_err(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar_printf_err('%'));
	return (0);
}

int	ft_printf_error(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count = count + ft_format(format[i], args);
		}
		else
			count = count + ft_putchar_printf_err(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
