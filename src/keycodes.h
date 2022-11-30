/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:44:24 by hrothery          #+#    #+#             */
/*   Updated: 2022/09/26 10:50:33 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __linux__

#  define A_KEY 97
#  define D_KEY 100
#  define W_KEY 119
#  define S_KEY 115
#  define EXIT_KEY 65307
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
# endif

# ifdef __APPLE__

#  define A_KEY 0
#  define D_KEY 2
#  define W_KEY 13
#  define S_KEY 1
#  define EXIT_KEY 53
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
# endif

#endif