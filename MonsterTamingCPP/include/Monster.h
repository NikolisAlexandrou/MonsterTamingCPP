#pragma once
#include <string>
#include <vector>
#include "Move.h"
#include "ElementType.h"

class Monster {
public:
	Monster(const std::string& name, int health, int attackPower, ElementType element);

	void TakeDamage(int damage);

	void Attack(Monster& defender, const Move& move);

	void AddMove(const Move& move);

	void PrintStats() const;

	bool IsAlive() const;

	const std::vector<Move>& GetMoves() const;

	const std::string& GetName() const;

	~Monster();

private:
	std::string m_name;
	int m_health;
	int m_attack;
	ElementType m_element;
	std::vector<Move> m_moves;
};