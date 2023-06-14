/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjegoulh <xjegoulh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:02:45 by xjegoulh          #+#    #+#             */
/*   Updated: 2023/01/16 13:13:37 by xjegoulh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr2(int nb, char *t, int nbdigits, int isneg);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(char *t, int nbdigits, int isneg)
{
	if (isneg)
		write(1, "-", 1);
	while (nbdigits >= 0)
	{
		ft_putchar('0' + t[nbdigits--]);
	}
}

void	ft_putnbr(int nb)
{
	int		nbdigits;
	int		isneg;
	char	tab[20];

	nbdigits = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		isneg = 1;
		nb = -nb;
	}
	else
		isneg = 0;
	ft_putnbr2(nb, tab, nbdigits, isneg);
}

void	ft_putnbr2(int nb, char *t, int nbdigits, int isneg)
{
	while (nb != 0)
	{
		t[nbdigits++] = nb % 10;
		nb /= 10;
	}
	display(t, nbdigits - 1, isneg);
}
