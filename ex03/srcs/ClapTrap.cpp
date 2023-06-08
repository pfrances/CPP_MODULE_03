/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/06/08 21:18:28 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

unsigned int ClapTrap::HitPointsMax_ = 100;
unsigned int ClapTrap::AttackDamageMax_ = 100;

unsigned int ClapTrap::DefaultHitPoints_ = 10;
unsigned int ClapTrap::DefaultEnergyPoints_ = 10;
unsigned int ClapTrap::DefaultAttackDamage_ = 0;

ClapTrap::ClapTrap( void ) : Name_("Unamed"),
							HitPoints_(DefaultHitPoints_),
							EnergyPoints_(DefaultEnergyPoints_),
							AttackDamage_(DefaultAttackDamage_) {
	std::cout << "[ClapTrap] default constructor called. Welcome " << this->Name_ << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : Name_(name),
							HitPoints_(DefaultHitPoints_),
							EnergyPoints_(DefaultEnergyPoints_),
							AttackDamage_(DefaultAttackDamage_) {
	std::cout << "[ClapTrap] named constructor called. Welcome " << this->Name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : Name_(other.Name_),
											HitPoints_(other.HitPoints_),
											EnergyPoints_(other.EnergyPoints_),
											AttackDamage_(other.AttackDamage_) {
	std::cout << "[ClapTrap] copy constructor called. Welcome " << this->Name_ << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->Name_ = other.Name_;
		this->HitPoints_ = other.HitPoints_;
		this->EnergyPoints_ = other.EnergyPoints_;
		this->AttackDamage_ = other.AttackDamage_;
	}
	std::cout << "[ClapTrap] asignment called. Welcome " << this->Name_ << std::endl;
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "[ClapTrap] destructor called. Bye " << this->Name_ << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->EnergyPoints_ > 0 && this->HitPoints_ > 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " attacks " << target << ", causing " << this->AttackDamage_ << " points of damage!" << std::endl;
		this->EnergyPoints_--;
	} else if (this->EnergyPoints_ == 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " has no energy point anymore. He can't attack." << std::endl;
	} else if (this->HitPoints_ == 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " has no hit point anymore. He can't attack." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoints_ == 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " has no hit point anymore. He can't take damage." << std::endl;
	} else if (this->HitPoints_ >= amount) {
		this->HitPoints_ -= amount;
		std::cout << "[ClapTrap] " << this->Name_ << " take " << amount << " damage. He has now " << this->HitPoints_ << " hit points." << std::endl;
	} else {
		std::cout << "[ClapTrap] " << this->Name_ << " take " << this->HitPoints_ << " damage. He died." << std::endl;
		this->HitPoints_ = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (amount > HitPointsMax_) {
		std::cout << "[ClapTrap] That too amount of Hit point. Max 100." << std::endl;
	} else if (this->EnergyPoints_ > 0 && this->HitPoints_ > 0) {
		if (this->HitPoints_ == HitPointsMax_) {
			std::cout << "[ClapTrap] " << this->Name_ << " is already full life." << std::endl;
		} else if (this->HitPoints_ + amount <= HitPointsMax_) {
			this->HitPoints_ += amount;
			std::cout << "[ClapTrap] " << this->Name_ << " repared " << amount << " hit point. He has now : " << this->HitPoints_ << " hit points." << std::endl;
		} else {
			this->HitPoints_ = HitPointsMax_;
			std::cout << "[ClapTrap] " << this->Name_ << " repared " << HitPointsMax_ - amount << " hit point. He has now : " << this->HitPoints_ << " hit points." << std::endl;
		}
		this->EnergyPoints_--;
	} else if (this->EnergyPoints_ == 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " has no energy point anymore. He can't be repaired." << std::endl;
	} else if (this->HitPoints_ == 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " has no hit point anymore. He can't be repaired." << std::endl;
	}
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	return (this->AttackDamage_);
}

void	ClapTrap::setAttackDamage( unsigned int Attack_value) {
	if (Attack_value > AttackDamageMax_) {
		std::cout << "[ClapTrap] That too high attack damage value. Max 100." << std::endl;
	} else if (this->HitPoints_ > 0) {
		this->AttackDamage_ = Attack_value;
		std::cout << "[ClapTrap] " << this->Name_ << "'s attack damage's value is now set to " << this->AttackDamage_ << std::endl;
	} else if (this->HitPoints_ == 0) {
		std::cout << "[ClapTrap] " << this->Name_ << " has no hit point anymore. He can't update his attack damage value." << std::endl;
	}
}
