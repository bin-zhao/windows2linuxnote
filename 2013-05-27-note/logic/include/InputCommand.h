#ifndef  _NINJIATRIBE_INPUTCOMMAND_H_
#define  _NINJIATRIBE_INPUTCOMMAND_H_


enum InputCommand
{
	_TYPED_INPUT_COMMAND_UNKOWN_,                           // 未知的输入事件类型
	_TYPED_INPUT_COMMAND_SELECTED_,                         // 对象选择Selected
	_TYPED_INPUT_COMMAND_UNSELECTED_,                       // 对象被取消选择UnSelected

	_TYPED_INPUT_COMMAND_BULLET_COLLISION_MONSTER_,         // 子弹碰撞怪物事件类型
	_TYPED_INPUT_COMMAND_BULLET_COLLISION_BUILDING_,        // 子弹碰撞建筑事件类型

	_TYPED_INPUT_COMMAND_LIGHTNING_COLLISION_MONSTER_,      // 雷电碰撞怪物事件类型
	_TYPED_INPUT_COMMAND_LIGHTNING_COLLISION_BUILDING_,     // 雷电碰撞建筑事件类型

	_TYPED_INPUT_COMMAND_MONSTER_COLLISION_CHEESE_,         // 怪物碰撞奶酪事件类型

	_TYPED_INPUT_COMMAND_BULLET_ADD_ATTACK_MONSTER_,        // 子弹溅射怪物事件类型
	_TYPED_INPUT_COMMAND_BULLET_ADD_ATTACK_BUILDING_,       // 子弹溅射建筑事件类型

	_TYPED_INPUT_COMMAND_BOMB_MONSTER_,                     // 炸弹炸到怪物事件类型
	_TYPED_INPUT_COMMAND_BOMB_BUILDING_,                    // 炸弹炸到建筑事件类型

	_TYPED_INPUT_COMMAND_KILL_MONSTER_,                     // 杀死怪物事件类型

	_TYPED_INPUT_COMMAND_KILL_BUILDING_,                    // 杀死建筑事件类型

	_TYPED_INPUT_COMMAND_KILL_CHEESE_,                      // 杀死奶酪事件类型

	_TYPED_INPUT_COMMAND_HEROTOMONSTER_,					// 英雄和怪物攻击事件类型

	_TYPED_INPUT_COMMAND_HEROWEAPONTOMONSTER_,				// 英雄武器和怪物攻击事件类型

	_TYPED_INPUT_COMMAND_MONSTERTOHERO,					    // 怪物和英雄攻击事件类型

	_TYPED_INPUT_COMMAND_MONSTERWEAPONTOHERO_,				// 怪物武器和英雄攻击事件类型

	_TYPED_INPUT_COMMAND_WEAPON_PLAYEFFECT_,				// 武器播放特效动画类型

	_TYPED_INPUT_COMMAND_NUMBER_,                           // 输入事件类型个数

};


#endif
