#include "catch.hpp"
#include "../state/State.h"

TEST_CASE("Test state class"){
	State* state = new State("State", 200, 50);

	REQUIRE(state->getTitile() == "State");
	REQUIRE(state->getHitPoints() == 200);
	REQUIRE(state->getHitPointsLimit() == 200);
	REQUIRE(state->getDamage() == 50);

	SECTION("State::takeDamage tests"){
		int damage = 10;
		int iteration = state->getHitPoints() / damage;

		for( int i = 1 ; i <= iteration; i++ ){
			state->takeDamage(damage);
			int expectedHP = state->getHitPointsLimit() - damage * i;
			REQUIRE(state->getHitPoints() == expectedHP);	
		}
		
	}

}