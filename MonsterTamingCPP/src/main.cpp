// Main.cpp : Defines the entry point for the application.
//
#include <iostream>
#include "Monster.h"
#include <memory>
#include <vector>
#include <ctime>

//using namespace std;
const Move& ChooseMove(Monster& monster, bool isPlayer);

std::vector<Monster> party;

int main()
{
	// add monsters to party
	party.emplace_back("Leafon", 100, 20, ElementType::Leaf);
	party[0].AddMove(Move("Scratch", 10, ElementType::Normal));
	party[0].AddMove(Move("Leaf Blade", 30, ElementType::Leaf));
	party[0].AddMove(Move("Grass Attack", 15, ElementType::Leaf));

	party.emplace_back("Pyrock", 50, 50, ElementType::Earth);
	party[1].AddMove(Move("Earthquake", 40, ElementType::Earth));
	party[1].AddMove(Move("Rock Throw", 20, ElementType::Earth));

	std::cout << "Your party consists of the following monsters:\n" << std::endl;
	int index = 1;
	for (const Monster& monster : party) {
		std::cout << index++ << ". ";
		monster.PrintStats();
	}
	std::cout << "\n" << std::endl;

	auto floxy = std::make_unique<Monster>("Floxy", 80, 25, ElementType::Fire);
	floxy.get()->AddMove(Move("Fire Blast", 35, ElementType::Fire));

	Monster* player = nullptr;
	Monster* enemy = nullptr;

	// Set pointers to attacker and defender
	player = &party[0];
	enemy = floxy.get();

	std::cout << "You are being challenged by a wild " << floxy->GetName() << "!\n" << std::endl;

	// Handle main game loop
	while ((player != nullptr && player->IsAlive()) && (enemy != nullptr && enemy->IsAlive())) {
		// Display stats
		std::cout << "------    Your monster stats:    ------\n" << std::endl;
		player->PrintStats();
		std::cout << "\n" << std::endl;
		std::cout << "------    Enemy monster stats:    ------\n" << std::endl;
		enemy->PrintStats();
		std::cout << "\n" << std::endl;


		// Get player input
		std::string in;
		std::cout << "\nAttack? [yes|no|change]\n" << std::endl;
		std::cin >> in;

		// Validate player input
		while (in != "yes" && in != "no" && in != "change") {
			std::cout << "Invalid input. Please enter 'yes', 'no', or 'change'.\n" << std::endl;
			std::cin >> in;
		}

		// Attack
		if (in == "yes") {
			player->Attack(*enemy, ChooseMove(*player, true));
			std::cout << "Waiting for opponents turn... \n" << std::endl;
		}
		else if (in == "no") {
			std::cout << "Turn skipped, waiting for opponent attack. \n" << std::endl;
		}
		else if (in == "change") {
			std::cout << "Changing monster...\n" << std::endl;
			// Implement monster change logic here
			int choice;

			std::cout << "Choose a monster from your party:\n";
			for (size_t i = 0; i < party.size(); ++i) {
				std::cout << i + 1 << ". " << party[i].GetName() << std::endl;
			}

			std::cin >> choice;

			while (choice < 1 || choice > static_cast<int>(party.size())) {
				std::cout << "Invalid choice. Please select a valid monster.\n" << std::endl;
				std::cin >> choice;
			}

			if (choice >= 1 && choice <= static_cast<int>(party.size())) {
				player = &party[choice - 1];
			}
		}
		if (enemy->IsAlive()) {
			enemy->Attack(*player, ChooseMove(*enemy, false));
		}

		// Check death Conditions
		if (!enemy->IsAlive()) {
			std::cout << "You Won! your opponent's monster is dead!\n" << std::endl;
		}
		else if (!player->IsAlive()) {
			std::cout << "You Lost! your monster is dead!\n" << std::endl;
		}
	}

	return 0;
}


const Move& ChooseMove(Monster& monster, bool isPlayer) {
	// Check if monster is player
	if (isPlayer == true) {
		std::cout << "Choose a move to use:\n";
		for (int i = 0; i < monster.GetMoves().size(); i++) {
			const Move& move = monster.GetMoves()[i];
			std::cout <<  (i + 1) +". " << move.GetName() << " (Power: " << move.GetPower() << ")\n";
		}
		int choice;
		std::cin >> choice;

		while (choice < 1 || choice > static_cast<int>(monster.GetMoves().size())) {
			std::cout << "Invalid choice. Please select a valid move.\n" << std::endl;
			std::cin >> choice;
		}

		return monster.GetMoves()[choice - 1];
	}
	else {
		srand(time(0));
		int randNum = rand() % monster.GetMoves().size();
		return monster.GetMoves()[randNum];
	}
}
