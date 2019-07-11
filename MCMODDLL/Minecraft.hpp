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


	auto getFullName() const {
		return (std::string&) * (__int64*)((__int64)this + 104);
	}


	auto getBlockItemID() const {
		return SYM_CALL(short (*)(const BlockLegacy*),
			MSSYM_B1QE14getBlockItemIdB1AE11BlockLegacyB2AAA7QEBAFXZ,
			this);
	}

};

struct BlockPos {
	INT32* getPosition() const {
		return reinterpret_cast<INT32*>(reinterpret_cast<VA>(this));
	}
};

struct Block {
	const BlockLegacy* getLegacyBlock() const {
		return SYM_CALL(const BlockLegacy * (*)(const Block*),
			MSSYM_B1QE14getLegacyBlockB1AA5BlockB2AAE19QEBAAEBVBlockLegacyB2AAA2XZ,
			this);
	}
};

struct BlockActor {
	Block* getBlock() {
		return *reinterpret_cast<Block**>(reinterpret_cast<VA>(this) + 16);
	}

	BlockPos* getPosition() {
		return reinterpret_cast<BlockPos*>(reinterpret_cast<VA>(this) + 44);
	}
};

struct BlockSource {
	const Block* getBlock(const BlockPos* blkpos) {
		return SYM_CALL(const Block * (*)(decltype(this), decltype(blkpos)),
			MSSYM_B1QA8getBlockB1AE11BlockSourceB2AAE13QEBAAEBVBlockB2AAE12AEBVBlockPosB3AAAA1Z,
			this, blkpos);
	}
};

struct Actor {
	BlockSource* getRegion() {
		return *reinterpret_cast<BlockSource**>(reinterpret_cast<VA>(this) + 414*sizeof(void*));
	}
	int getDimension() {
		return *reinterpret_cast<int*>(reinterpret_cast<VA>(this) + 172);
	}

	const std::string* getNameTag() const {
		return SYM_CALL(const std::string * (*)(const Actor*),
			MSSYM_B1QE10getNameTagB1AA5ActorB2AAA8UEBAAEBVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ,
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
	Player* getPlayer() {
		return *reinterpret_cast<Player**>(reinterpret_cast<VA>(this) + 8);
	}
};
struct LevelContainerManagerModel
	:ContainerManagerModel {
};

struct ItemStack {
	int getId() {
		return SYM_CALL(int(*)(ItemStack*),
			MSSYM_B1QA5getIdB1AA9ItemStackB2AAA7QEBAFXZ,
			this);
	}

	INT64 getName(std::string& str) {
		return SYM_CALL(INT64(*)(decltype(this), decltype(str)),
			MSSYM_B1QA7getNameB1AA9ItemStackB2AAA4QEBAB1QA2AVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ,
			this, str);
	}
	UINT8 getStackSize() {
		return *reinterpret_cast<UINT8*>(reinterpret_cast<VA>(this) + 26);
	}
};

struct ContainerItemStack
	:ItemStack {

};

