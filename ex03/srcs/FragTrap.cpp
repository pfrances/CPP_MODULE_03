/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:37:14 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/10 15:43:29 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

unsigned int FragTrap::DefaultHitPoints_ = 100;
unsigned int FragTrap::DefaultEnergyPoints_ = 100;
unsigned int FragTrap::DefaultAttackDamage_ = 30;

FragTrap::FragTrap( void ) : ClapTrap() {
	this->Name_ = "Unamed";
	this->HitPoints_ = DefaultHitPoints_;
	this->EnergyPoints_ = DefaultEnergyPoints_;
	this->AttackDamage_ = DefaultAttackDamage_;
	std::cout << "[FragTrap] default constructor called. Welcome " << this->Name_ << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->Name_ = name;
	this->HitPoints_ = DefaultHitPoints_;
	this->EnergyPoints_ = DefaultEnergyPoints_;
	this->AttackDamage_ = DefaultAttackDamage_;
	std::cout << "[FragTrap] named constructor called. Welcome " << this->Name_ << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "[FragTrap] copy constructor called. Welcome " << this->Name_ << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "[FragTrap] asignment called. Welcome " << this->Name_ << std::endl;
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "[FragTrap] destructor called. Bye " << this->Name_ << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] Let's do a high Fives !" << std::endl;
}
