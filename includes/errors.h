/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:13:05 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:17:28 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define INVARGS "Invalid number of arguments\n"
# define INV_SECOND "Invalid second argument\n"
# define INIT_FAIL "Failed mlx connection initialization\n"
# define DOUBLE_R "Invalid .rt file. Double initil of Resolution at string "
# define DOUBLE_A "Invalid .rt file. Double initial of Ambient light at string "
# define INVAL_P "Invalid .rt file. Invalid param at string "
# define INVAL_V "Invalid .rt file. Invalid value at string "
# define NO_CAMERA "Invalid .rt file. Need at least one camera"
# define CREATE_BMP "Failed to write bmp file"
# define WRITE_BMP "Failed to write bmp file"

void	check_input(int argc, char *rt, char *save, int *fd);

#endif
