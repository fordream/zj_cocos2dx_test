//
//  Enemy.cpp
//
//  Created by tonyguan on 13-12-11.
//
//

#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy(EnemyTypes enemyType)
{
	this->enemyType = enemyType;
	this->initialHitPoints = 1;
	this->velocity = Vec2::ZERO;
}

Enemy* Enemy::createWithEnemyTypes(EnemyTypes enemyType)
{
	Enemy *enemy = new Enemy(enemyType);

	const char* enemyFramName = Enemy_Stone;

	switch (enemyType) {
	case EnemyTypeStone:
		enemyFramName = Enemy_Stone;
		enemy->initialHitPoints = 3;
		break;
	case EnemyTypeEnemy1:
		enemyFramName = Enemy_1;
		enemy->initialHitPoints = 5;
		break;
	case EnemyTypeEnemy2:
		enemyFramName = Enemy_2;
		enemy->initialHitPoints = 10;
		break;
	case EnemyTypePlanet:
		enemyFramName = Enemy_Planet;
		enemy->initialHitPoints = 15;
		break;
	}

	if (enemy && enemy->initWithSpriteFrameName(enemyFramName)) {

		enemy->autorelease();

		auto body = PhysicsBody::create();

		if (enemyType == EnemyTypeStone || enemyType == EnemyTypePlanet) {
			body->addShape(PhysicsShapeCircle::create(enemy->getContentSize().width / 2 - 5));
		}  else if  (enemyType == EnemyTypeEnemy1) {
			Vec2 verts[] ={ 
				Vec2(-2.5,-45.75), 
				Vec2(-29.5,-27.25), 
				Vec2(-53, -0.25), 
				Vec2(-34,43.25), 
				Vec2(28, 44.25), 
				Vec2(55,-2.25)};
			body->addShape(PhysicsShapePolygon::create(verts ,6));
		} else if  (enemyType == EnemyTypeEnemy2) {
			Vec2 verts[] ={  
				Vec2(1.25, 32.25), 
				Vec2(36.75, -4.75), 
				Vec2( 2.75, -31.75), 
				Vec2(-35.75,-3.25)};
			body->addShape(PhysicsShapePolygon::create(verts, 4));
		}

		body->setCategoryBitmask(0x01);			//0001
		body->setCollisionBitmask(0x02);		//0010
		body->setContactTestBitmask(0x01);
	
		enemy->setPhysicsBody(body);

		enemy->setVisible(false);
		enemy->spawn();
		enemy->unscheduleUpdate();
		enemy->scheduleUpdate();

		return enemy;
	}

	CC_SAFE_DELETE(enemy);

	return nullptr;
}

void Enemy::update(float dt)
{
	//设置陨石和行星旋转.
	switch (enemyType) {
	case EnemyTypeStone:
		this->setRotation(this->getRotation() - 0.5);
		break;
	case EnemyTypePlanet:
		this->setRotation(this->getRotation() + 1);
		break;
	}

	Vec2 moveLen = velocity * dt;

	this->setPosition(this->getPosition() + moveLen);

	if (this->getPosition().y + this->getContentSize().height /2 < 0) {
		this->spawn();
	}    
}


void Enemy::spawn()
{
	Size screenSize = Director::getInstance()->getVisibleSize();
	float yPos = screenSize.height + this->getContentSize().height /2 ;
	float xPos = CCRANDOM_0_1()*(screenSize.width - this->getContentSize().width) + this->getContentSize().width / 2;
	this->setPosition(Vec2(xPos, yPos));
	this->setAnchorPoint(Vec2(0.5f,0.5f));

	hitPoints = initialHitPoints;
	this->setVisible(true);

}
