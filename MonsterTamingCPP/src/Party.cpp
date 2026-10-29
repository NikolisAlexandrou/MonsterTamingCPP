#include <MonsterParty.h>
#include <iostream>

/// <summary>
/// Add a monster to the monster party if it is not already full and point it to
/// active monster slot if the party was empty
/// </summary>
/// <param name="monster"></param>
void Party::AddMonster(Monster monster) {
	// Check if the party is not already full
	if (m_monsters.size() > 5)
		return;

    m_monsters.push_back(std::move(monster));
}

/// <summary>
/// Print all the party members and the active monster
/// </summary>
void Party::PrintParty() const {
    for (std::size_t i = 0; i < m_monsters.size(); ++i)
    {
        const Monster& monster = m_monsters[i];

        std::cout << i + 1 << ". ";

        monster.PrintStats();

        if (i == m_activeIndex)
            std::cout << "   [ACTIVE]\n";
    }
}

/// <summary>
/// Switch current active monster to the monster at index given
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
bool Party::SwitchTo(std::size_t index) {
    // Check if there is an actual valid monster in that index
    if (index > m_monsters.size())
        return false;

    // Check if the monster is alive
    if (!m_monsters[index].IsAlive())
        return false;

    // change the active monster to monster at index
    m_activeIndex = index;

    return true;
}

/// <summary>
/// Get the active monster of the party
/// </summary>
/// <returns></returns>
Monster& Party::GetActiveMonster() {
    return m_monsters.at(m_activeIndex);
}

/// <summary>
/// Get the active monster of the party
/// </summary>
/// <returns></returns>
const Monster& Party::GetActiveMonster() const {
    return m_monsters.at(m_activeIndex);
}

/// <summary>
/// Get the total count of the monsters are in the party
/// </summary>
/// <returns></returns>
size_t Party::GetSize() const {
    return m_monsters.size();
}

