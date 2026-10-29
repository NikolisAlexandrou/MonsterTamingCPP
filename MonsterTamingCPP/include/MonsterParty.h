#pragma once

#include "Monster.h"
#include <cstddef>
#include <vector>

class Party {
public:
	void AddMonster(Monster monster);

	void PrintParty() const;

	bool SwitchTo(std::size_t index);

	Monster& GetActiveMonster();

	const Monster& GetActiveMonster() const;

	std::size_t GetSize() const;

private:
	std::vector<Monster> m_monsters;

	std::size_t m_activeIndex = 0;
};

