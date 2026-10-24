#pragma once
#include <string>
#include "ElementType.h"


class Move {
public:
	Move(const std::string& name, int power, ElementType element);
	~Move();

	const int GetPower() const;

	void PrintMove() const;

	const std::string& GetName() const;

private:
	std::string m_name;
	int m_power;
	ElementType m_element;
};