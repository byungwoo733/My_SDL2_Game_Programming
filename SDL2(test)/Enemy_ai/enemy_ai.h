// Here is an example of an enemy_ai.h file that defines the EnemyAI struct and its associated functions
#ifndef ENEMY_AI_H
#define ENEMY_AI_H

#include "enemy.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    int direction;
    int speed;
} EnemyAI;

void initEnemyAI(EnemyAI* enemy_ai);
void updateEnemyAI(EnemyAI* enemy_ai, Enemy* enemy);

#endif

/*
This is a simple example, you can expand it to fit your needs.
It moves the enemy randomly around the screen, when the enemy hit the border of the screen it will change the direction randomly.
You can add more complex behavior like following the player, or attacking the player, or even spawning other enemies, it depends on the game you are building.
It uses a struct structure to encapsulate the AI

[번역]
이것은 간단한 예이므로 필요에 맞게 확장할 수 있습니다.
그것은 화면 주위에 적을 무작위로 이동하고, 적이 화면의 경계에 부딪히면 무작위로 방향을 바꿀 것입니다.
플레이어를 따르거나, 플레이어를 공격하거나, 심지어 다른 적을 생성하는 것과 같은 더 복잡한 동작을 추가할 수 있습니다. 빌드 중인 게임에 따라 다릅니다.
구조체 구조를 사용하여 AI를 캡슐화합니다.
*/