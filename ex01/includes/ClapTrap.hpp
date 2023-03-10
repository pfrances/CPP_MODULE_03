/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/10 15:33:46 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap( void );

	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getAttackDamage( void ) const;
	void			setAttackDamage( unsigned int );

protected:
	std::string		Name_;
	unsigned int	HitPoints_;
	unsigned int	EnergyPoints_;
	unsigned int	AttackDamage_;

	static unsigned int DefaultHitPoints_;
	static unsigned int DefaultEnergyPoints_;
	static unsigned int DefaultAttackDamage_;

	static unsigned int HitPointsMax_;
	static unsigned int AttackDamageMax_;

};

#endif
