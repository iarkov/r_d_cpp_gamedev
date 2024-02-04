#include "Victory.h"
#include "Munchkin.h"

void Victory_LevelUp::apply(Munchkin* munchkin) {
	munchkin->updateLevelBy(m_levelUp);
}