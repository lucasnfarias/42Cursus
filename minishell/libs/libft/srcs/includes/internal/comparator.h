/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:29:52 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/17 20:31:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARATOR_H
# define COMPARATOR_H

/**
 * \brief Compare two elements
 *
 * @param max The first element
 * @param min The second element
 *
 * @return The return can be different for diferents implementations
 */
typedef bool (*	t_comparator)(const void *max, const void *min);

#endif
