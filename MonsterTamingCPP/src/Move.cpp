#include "Monster.h"
#include <iostream>

Move::Move(const std::string& name, int power, ElementType element)
	: m_name(name), m_power(power), m_element(element) {}

Move::~Move() {}

const int Move::GetPower() const {
	return m_power;
}

const std::string& Move::GetName() const {
	return m_name;
}

void Move::PrintMove() const {
	std::cout << "Move Name: " << m_name << std::endl;
	std::cout << "Power: " << m_power << std::endl;
	std::cout << "Element: " << (m_element == ElementType::Fire ? "Fire" :
		m_element == ElementType::Water ? "Water" :
		m_element == ElementType::Leaf ? "Leaf" :
		m_element == ElementType::Earth ? "Earth" :
		m_element == ElementType::Normal ? "Normal" :
		m_element == ElementType::Air ? "Air" : "None") << std::endl;
}