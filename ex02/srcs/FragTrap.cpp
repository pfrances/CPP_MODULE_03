/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:37:14 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/08 21:42:36 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	this->Name_ = "Unamed";
	this->HitPoints_ = 100;
	this->EnergyPoints_ = 100;
	this->AttackDamage_ = 30;
	std::cout << "[FragTrap] default constructor called. Welcome " << this->Name_ << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->Name_ = name;
	this->HitPoints_ = 100;
	this->EnergyPoints_ = 100;
	this->AttackDamage_ = 30;
	std::cout << "[FragTrap] named constructor called. Welcome " << this->Name_ << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	this->Name_ = other.Name_;
	this->HitPoints_ = other.HitPoints_;
	this->EnergyPoints_ = other.EnergyPoints_;
	this->AttackDamage_ = other.AttackDamage_;
	std::cout << "[FragTrap] copy constructor called. Welcome " << this->Name_ << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "[FragTrap] asignment called. Welcome " << this->Name_ << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "[FragTrap] destructor called. Bye " << this->Name_ << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] Let's do a high Fives !" << std::endl;
}
