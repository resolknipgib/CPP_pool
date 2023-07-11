/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:39:08 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/13 12:39:15 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);

		Brain const	&operator=(Brain const &copy);

		std::string const	&getIdea(int const &index) const;
		void				setIdea(std::string const &idea, int const &index);
};
