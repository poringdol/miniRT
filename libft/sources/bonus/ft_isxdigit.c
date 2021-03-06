/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 12:39:53 by pdemocri          #+#    #+#             */
/*   Updated: 2020/04/25 12:40:17 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isxdigit(int ch)
{
	if ((ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f') ||\
		(ch >= '0' && ch <= '9'))
		return (ch);
	return (0);
}
