/*
本文件存放Minecraft内部逆向分析得到的数据结构，由于用途限制，这里的结构可能不完整。
如果未来版本（高于1.16.0.2版本）更新导致数据结构变化，请您自行分析再修正。
*/
#pragma once

#include "符号定位.hpp"

template<typename T>
struct SharedPtr {
	auto get() {
		return **reinterpret_cast<T***>(this);
	}
	auto operator->() {
		return get();
	}
};

struct BlockLegacy {
	// 获取方块名
	auto getFullName() const {
		return  *(std::string*)((VA)this + 112);
	}

	// 获取方块ID号
	auto getBlockItemId() const {
		short v3 = *(short*)((VA)this + 268);
		if (v3 < 0x100) {
			return v3;
		}
		return (short)(255 - v3);
	}

};

struct BlockPos {
	// 获取坐标数组头
	INT32* getPosition() const {
		return reinterpret_cast<INT32*>(reinterpret_cast<VA>(this));
	}
};

struct Block {
	// 获取源
	const BlockLegacy* getLegacyBlock() const {
		return (BlockLegacy*)(**((VA**)this + 2));
	}
};

struct BlockActor {
	// 取方块
	Block* getBlock() {
		return *reinterpret_cast<Block**>(reinterpret_cast<VA>(this) + 16);
	}
	// 取方块位置
	BlockPos* getPosition() {
		return reinterpret_cast<BlockPos*>(reinterpret_cast<VA>(this) + 44);
	}
};

struct BlockSource {
	// 取方块
	Block* getBlock(const BlockPos* blkpos) {
		return SYMCALL(Block *,
			MSSYM_B1QA8getBlockB1AE11BlockSourceB2AAE13QEBAAEBVBlockB2AAE12AEBVBlockPosB3AAAA1Z,
			this, blkpos);
	}
};

struct Vec3 {
	float x;
	float y;
	float z;
};

struct Actor {
	// 取方块源
	BlockSource* getRegion() {
		return *reinterpret_cast<BlockSource**>(reinterpret_cast<VA>(this) + 414*sizeof(void*));
	}
	// 取维度ID
	int getDimension() {
		return *reinterpret_cast<int*>(reinterpret_cast<VA>(this) + 204);
	}
	// 取名字标签
	const std::string* getNameTag() const {
		return SYMCALL(const std::string *,
			MSSYM_MD5_7044ab83168b0fd345329e6566fd47fd,
			this);
	}
	// 是否悬空
	const byte isStand() {
		return *reinterpret_cast<byte *>(reinterpret_cast<VA>(this) + 416);
	}
	// 取玩家位置
	Vec3* getPos() {
		return SYMCALL(Vec3 *,
			MSSYM_B1QA6getPosB1AA5ActorB2AAE12UEBAAEBVVec3B2AAA2XZ,
			this);
	}
};
struct Mob
	:Actor {
};
struct Player
	:Mob {
};

struct GameMode {

};

struct ContainerManagerModel {
	// 取开容者
	Player* getPlayer() {
		return *reinterpret_cast<Player**>(reinterpret_cast<VA>(this) + 8);
	}
};
struct LevelContainerManagerModel
	:ContainerManagerModel {
};

struct ItemStack {
	// 取物品ID
	int getId() {
		return SYMCALL(short,
			MSSYM_B1QA5getIdB1AE13ItemStackBaseB2AAA7QEBAFXZ,
			this);
	}
	// 取物品名称
	std::string getName() {
		std::string str;
		SYMCALL(VA,
			MSSYM_MD5_6d581a35d7ad70fd364b60c3ebe93394,
			this, &str);
		return str;
	}

	// 取容器内数量
	int getCount() {
		return *((char*)this + 34);
	}
};

struct LevelContainerModel {
	// 取开容者
	Player* getPlayer() {
		return ((Player**)this)[26];
	}
};
