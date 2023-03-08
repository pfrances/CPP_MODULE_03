/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/07 19:17:38 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
	
	ClapTrap Clap1("Clap1");
	ClapTrap Clap2("Clap2");
	ClapTrap Clap3("Clap3");

	std::cout << std::endl;

	Clap1.attack("Clap2");
	Clap2.takeDamage(Clap1.getAttackDamage());

	std::cout << std::endl;

	Clap1.setAttackDamage(5);
	Clap1.attack("Clap3");
	Clap3.takeDamage(Clap1.getAttackDamage());

	std::cout << std::endl;

	Clap1.setAttackDamage(10);
	Clap1.attack("Clap2");
	Clap2.takeDamage(Clap1.getAttackDamage());

	std::cout << std::endl;

	Clap2.setAttackDamage(10);
	Clap2.attack("Clap2");

	std::cout << std::endl;

	return 0;
}
