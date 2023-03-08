/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/08 21:52:35 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void ) {

	ClapTrap Clap1("Clap1");
	ScavTrap Scav1("Scav1");
	FragTrap Frag1("Frag1");

	std::cout << std::endl;

	Clap1.setAttackDamage(5);
	Clap1.attack("Scav1");
	Scav1.takeDamage(Clap1.getAttackDamage());

	std::cout << std::endl;

	Frag1.beRepaired(100);
	Frag1.attack("Scav1");
	Scav1.takeDamage(Frag1.getAttackDamage());
	Frag1.highFivesGuys();

	std::cout << std::endl;

	Scav1.attack("Clap1");
	Clap1.takeDamage(Scav1.getAttackDamage());

	std::cout << std::endl;

	Clap1.setAttackDamage(100);
	Clap1.attack("Scav1");

	std::cout << std::endl;

	Scav1.guardGate();
	Scav1.guardGate();

	std::cout << std::endl;

	return 0;
}
