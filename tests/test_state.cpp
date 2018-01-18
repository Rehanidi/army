#include "catch.hpp"
#include "../state/State.h"

TEST_CASE("Test state class"){
	State* state = new State("State", 200, 50);

	REQUIRE(state->getTitle() == "State");
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

		try {
			state->takeDamage(damage);
		}	catch (OutOfHitPointsException object){
			REQUIRE(state->getHitPoints() == 0);
		}

		try {
			state->addHitPoints(damage);
		} catch (OutOfHitPointsException object){
			REQUIRE(state->getHitPoints() == 0);
		}		
	}

	SECTION("State::takeMagicDamage tests"){
		int damage = 10;
		int iteration = state->getHitPoints() / damage;

		for( int i = 1 ; i <= iteration; i++ ){
			state->takeMagicDamage(damage);
			int expectedHP = state->getHitPointsLimit() - damage * i;
			REQUIRE(state->getHitPoints() == expectedHP);
		}

		try {
			state->takeMagicDamage(damage);
		}	catch (OutOfHitPointsException object){
			REQUIRE(state->getHitPoints() == 0);
		}

		try {
			state->addHitPoints(damage);
		} catch (OutOfHitPointsException object){
			REQUIRE(state->getHitPoints() == 0);
		}		
	}
	SECTION("State::addHitPoints test") {
		state->takeDamage(50);
		REQUIRE(state->getHitPoints() == 150);

		state->addHitPoints(40);
		REQUIRE(state->getHitPoints() == 190);

		state->addHitPoints(10);
		REQUIRE(state->getHitPoints() == 200);
		
		state->addHitPoints(10);
		REQUIRE(state->getHitPoints() == 200);
	}
}
