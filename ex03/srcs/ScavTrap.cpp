/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/10 15:41:14 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

unsigned int ScavTrap::DefaultHitPoints_ = 100;
unsigned int ScavTrap::DefaultEnergyPoints_ = 50;
unsigned int ScavTrap::DefaultAttackDamage_ = 20;

ScavTrap::ScavTrap( void ) : ClapTrap(), gateKeeper_(false) {
	this->Name_ = "Unamed";
	this->HitPoints_ = DefaultHitPoints_;
	this->EnergyPoints_ = DefaultEnergyPoints_;
	this->AttackDamage_ = DefaultAttackDamage_;
	std::cout << "[ScavTrap] default constructor called. Welcome " << this->Name_ << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name), gateKeeper_(false) {
	this->Name_ = name;
	this->HitPoints_ = DefaultHitPoints_;
	this->EnergyPoints_ = DefaultEnergyPoints_;
	this->AttackDamage_ = DefaultAttackDamage_;
	std::cout << "[ScavTrap] named constructor called. Welcome " << this->Name_ << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	this->gateKeeper_ = other.gateKeeper_;
	std::cout << "[ScavTrap] copy constructor called. Welcome " << this->Name_ << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->gateKeeper_ = other.gateKeeper_;
	}
	std::cout << "[ScavTrap] asignment called. Welcome " << this->Name_ << std::endl;
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "[ScavTrap] destructor called. Bye " << this->Name_ << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->EnergyPoints_ > 0 && this->HitPoints_ > 0) {
		std::cout << "[ScavTrap] " << this->Name_ << " attacks " << target << ", causing " << this->AttackDamage_ << " points of damage!" << std::endl;
		this->EnergyPoints_--;
	} else if (this->EnergyPoints_ == 0) {
		std::cout << "[ScavTrap] " << this->Name_ << " has no energy point anymore. He can't attack." << std::endl;
	} else if (this->HitPoints_ == 0) {
		std::cout << "[ScavTrap] " << this->Name_ << " has no hit point anymore. He can't attack." << std::endl;
	}
}

void	ScavTrap::guardGate( void ) {
	if (this->EnergyPoints_ == 0) {
		std::cout << "[ScavTrap] " << this->Name_ << " has no energy point anymore. He can't switch his Gate Keeper." << std::endl;
	} else if (this->HitPoints_ == 0) {
		std::cout << "[ScavTrap] " << this->Name_ << " has no hit point anymore. He can't switch his Gate Keeper." << std::endl;
	}
	else
	{
		if (this->gateKeeper_) {
			std::cout << "[ScavTrap] " << this->Name_ << " is not on Gate Keeper mode anymore." << std::endl;
		} else {
			std::cout << "[ScavTrap] " << this->Name_ <<" is now on Gate Keeper mode." << std::endl;
		}
		this->gateKeeper_ = !this->gateKeeper_;
	}
}
