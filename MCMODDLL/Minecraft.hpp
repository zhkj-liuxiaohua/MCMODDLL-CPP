/*
该文件存放Minecraft内部逆向分析得到的数据结构，由于用途限制，这里的结构可能不完整。
如果未来版本（高于1.11.4.2版本）更新导致数据结构变化，请您自行分析再修正。
*/
#pragma once

using namespace SymHook;

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
		return (std::string&) * (__int64*)((__int64)this + 104);
	}

	// 获取方块ID号
	auto getBlockItemID() const {
		return SYM_CALL(short (*)(const BlockLegacy*),
			MSSYM_B1QE14getBlockItemIdB1AE11BlockLegacyB2AAA7QEBAFXZ,
			this);
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
		return SYM_CALL(const BlockLegacy * (*)(const Block*),
			MSSYM_B1QE14getLegacyBlockB1AA5BlockB2AAE19QEBAAEBVBlockLegacyB2AAA2XZ,
			this);
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
	const Block* getBlock(const BlockPos* blkpos) {
		return SYM_CALL(const Block * (*)(decltype(this), decltype(blkpos)),
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
		return *reinterpret_cast<int*>(reinterpret_cast<VA>(this) + 188);
	}
	// 取名字标签
	const std::string* getNameTag() const {
		return SYM_CALL(const std::string * (*)(const Actor*),
			MSSYM_B1QE10getNameTagB1AA5ActorB2AAA8UEBAAEBVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ,
			this);
	}
	// 是否悬空
	const byte isStand() {
		return *reinterpret_cast<byte *>(reinterpret_cast<VA>(this) + 376);
	}
	// 取玩家位置
	Vec3* getPos() {
		return (Vec3*)SYM_CALL(Vec3 *(*)(void *),
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
		return SYM_CALL(int(*)(ItemStack*),
			MSSYM_B1QA5getIdB1AE13ItemStackBaseB2AAA7QEBAFXZ,
			this);
	}
	// 取物品名称
	INT64 getName(std::string& str) {
		return SYM_CALL(INT64(*)(decltype(this), decltype(str)),
			MSSYM_B1QA7getNameB1AE13ItemStackBaseB2AAA4QEBAB1QA2AVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ,
			this, str);
	}
	// 取容器内数量
	int getStackSize() {
		return SYM_CALL(int(*)(ItemStack*),
			MSSYM_B1QA8getCountB1AE18ContainerItemStackB2AAA7QEBAHXZ,
			this);
	}
};

struct ContainerItemStack
	:ItemStack {

};

