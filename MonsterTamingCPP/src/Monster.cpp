#include "Monster.h"
#include <iostream>
#include <string>

Monster::Monster(const std::string& name, int health, int attackPower, ElementType element)
	: m_name(name), m_health(health), m_attack(attackPower), m_element(element) {}

Monster::~Monster() {}


void Monster::TakeDamage(int damage) {
	m_health -= damage;
	if (m_health < 0) {
		m_health = 0;
	}
}

void Monster::Attack(Monster& defender, const Move& move) {
	std::cout << m_name << " attacks " << defender.GetName() << " with " << move.GetName() << " for " << (move.GetPower() + m_attack) << " damage!" << std::endl;
	defender.TakeDamage(move.GetPower() + m_attack);
}

void Monster::AddMove(const Move& move) {
	m_moves.emplace_back(move);
}

void Monster::PrintStats() const {
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Health: " << m_health << std::endl;
	std::cout << "Attack Power: " << m_attack << std::endl;
	std::cout << "Element: " << (m_element == ElementType::Fire ? "Fire" : 
		m_element == ElementType::Water ? "Water" : 
		m_element == ElementType::Leaf ? "Leaf" : 
		m_element == ElementType::Earth ? "Earth" : 
		m_element == ElementType::Normal ? "Normal" :
		m_element == ElementType::Air ? "Air" : "None") << std::endl;
	std::cout << "Moves: " << std::endl;
	for (const Move& move : m_moves) {
		move.PrintMove();
	}
}

bool Monster::IsAlive() const {
	return m_health > 0;
}

const std::vector<Move>& Monster::GetMoves() const {
	return m_moves;
}

const std::string& Monster::GetName() const {
	return m_name;
}