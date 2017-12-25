#include <iostream>

State::State(const char* totle, int hitPoints, int damage){
	this->title = title;
	this->hitPoints = hitPoints;
	this->getHitPointsLimit = hitPoints;
	this->damage = damage;
}

State::~State();

void ensureIsAlive(){
	if( this->hitPoints == 0 ){
		throw OutOfHitPointsException();
	}
}

const char* getTitle() const {
	return this->title;
}

int getHitPoints() const {
	return this->hitPoints;
}

int getHitPointsLimit() const {
	return this->getHitPointsLimit;
}

int getDamage() const{
	return this->damage;
}

void addhitPoints(int hp){
	this->ensureIsAlive();

	int total = this->getHitPoints + hp;
	if (total > this->getHitPointsLimit){
		this->getHitPoints = this->getHitPointsLimit;
		return;
	}
}
void takeDamage(int dmg){
	
}
void takeMagicDamage(int dmg);
}
