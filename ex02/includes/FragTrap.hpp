/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:35:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/08 23:12:30 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {

public:
	FragTrap( void );
	FragTrap( std::string name );
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	virtual ~FragTrap( void );

	void highFivesGuys(void);

};

#endif
