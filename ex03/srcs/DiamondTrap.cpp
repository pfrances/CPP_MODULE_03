/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:11:11 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/08 22:55:37 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap(), Name_("Unamed") {
	this->HitPoints_ = FragTrap::HitPoints_;
	this->EnergyPoints_ = ScavTrap::EnergyPoints_;
	this->AttackDamage_ = FragTrap::AttackDamage_;
	std::cout << "[DiamondTrap] default constructor called. Welcome " << this->Name_ << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), Name_(name) {
	this->ClapTrap::HitPoints_ = FragTrap::HitPoints_;
	this->ClapTrap::EnergyPoints_ = ScavTrap::EnergyPoints_;
	this->ClapTrap::AttackDamage_ = FragTrap::AttackDamage_;
	std::cout << "[DiamondTrap] named constructor called. Welcome " << this->Name_ << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), Name_(other.Name_) {
	std::cout << "[DiamondTrap] copy constructor called. Welcome " << this->Name_ << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		this->Name_ = other.Name_;
		this->HitPoints_ = other.HitPoints_;
		this->EnergyPoints_ = other.EnergyPoints_;
		this->AttackDamage_ = other.AttackDamage_;
		std::cout << "[DiamondTrap] asignment called. Welcome " << this->Name_ << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "[DiamondTrap] destructor called. Bye " << this->Name_ << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "[DiamondTrap] My name is " << this->Name_ << " and my ClapTrap name is " << this->ClapTrap::Name_ << std::endl;
}
