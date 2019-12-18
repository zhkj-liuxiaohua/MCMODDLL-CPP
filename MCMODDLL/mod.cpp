#include "pch.h"
#include "mod.h"
#include "SymHook.h"
#include "Minecraft.hpp"
using namespace SymHook;

/**——————————————————————————————————————**
 |              MOD C++文件               |
 **——————————————————————————————————————**
说明：
该cpp文件的目的是包含MOD功能主要代码，请将主要部分代码写在这个文件内！
“T”开头的系列Hook宏在模块加载的时候调用，使用方法请参考MCMrARM的modloader。
地址：https://github.com/minecraft-linux/server-modloader/wiki
请注意：使用方法略有不同，本文件的函数符号用的是PDB工具生成的C++变量，而不是字符串字面量！
另外，该文件包含两个函数mod_init和mod_exit，分别在该模块加载或退出时调用。
本模块例子：
THook(void,							// 函数返回类型
	MSSYM_XXXXXXXXXXXXXXXXXXXXX,	// 函数符号名对应的C++变量（位于SymHook.h）
	__int64 a1, __int64 a2) {		// 函数参数类型列表（假设存在参数a1与a2）
	std::cout << "Hello world!" << std::endl;
	original(a1, a2);				// 调用该函数Hook前的原始函数
}
*/
// 此处开始编写MOD代码

#include <map>
#include <unordered_map>
#include <string>
#include <chrono>

//std::map<short, std::string> BlockRegMap;

// 注册方块的时候构建方块ID查找表
//THook(void,
//	MSSYM_B1QE14registerBlocksB1AE17VanillaBlockTypesB2AAA5YAXXZ,
//	void* _this) {
//	original(_this);
//	std::unordered_map<std::string, SharedPtr<BlockLegacy>>* pMap;
//	pMap = SYM_PTR(decltype(pMap), MSSYM_MD5_ceb8b47184006e4d7622b39978535236);
//	for (auto i = pMap->begin(); i != pMap->end(); ++i) {
//		auto id = i->second->getBlockItemID();
//		auto str = std::string("Mincraft: " + id);
//			//i->second->getFullName();
//		BlockRegMap.emplace(id, str);
//	}
//}

namespace Log {
	namespace Helper {
		template<size_t size>
		void UtoA_Fill(char (&buf)[size], int num) {
			int nt = size - 1;
			buf[nt] = 0;
			for (auto i = nt - 1; i >= 0; --i) {
				char d = '0' + (num % 10);
				num /= 10;
				buf[i] = d;
			}
		}

		auto TimeNow() {
			auto timet = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			tm time;
			char buf[3] = { 0 };
			localtime_s(&time, &timet);
			std::string str(std::to_string((time.tm_year + 1900)));
			str += "-";
			UtoA_Fill(buf, time.tm_mon + 1);
			str += buf; str += "-";
			UtoA_Fill(buf, time.tm_mday);
			str += buf; str += " ";
			UtoA_Fill(buf, time.tm_hour);
			str += buf; str += ":";
			UtoA_Fill(buf, time.tm_min);
			str += buf; str += ":";
			UtoA_Fill(buf, time.tm_sec);
			str += buf;
			return str;
		}

		auto Title(const std::string& content) {
			return std::string("{[") + TimeNow() + " " + content + "]";
		}
		auto Coordinator(INT32 coordinator[]) {
			return std::string("(")
				+ std::to_string(coordinator[0]) + ", "
				+ std::to_string(coordinator[1]) + ", "
				+ std::to_string(coordinator[2]) + ")";
		}

		auto Pos(Vec3* v) {
			return "(" +
				std::to_string(int(v->x)) + ", "
				+ std::to_string(int(v->y)) + ", "
				+ std::to_string(int(v->z))
				+ ")";
		}

		auto Dimension(int v) {
			switch (v) {
			case 0: return u8"主世界";
			case 1: return u8"地狱";
			case 2: return u8"末地";
			}
			return u8"未知维度";
		}
	}

	namespace Player {
		using namespace Helper;

		void Error(const std::string& title, const std::string& player_name, int dimension, const std::string& content) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家" << " " << player_name << " "
				<< u8"在" << Dimension(dimension)
				<< content << std::endl;
		}
		void Block(const std::string& title, const std::string& player_name, char isStand, int dimension, const std::string& operation, const std::string & block_name, INT32 coordinator[]) {
			auto block_name_inner = block_name;
			if (block_name_inner == "")
				block_name_inner = u8"未知类型";
			std::cout
				<< Title(title) << " "
				<< u8"玩家" << " " << player_name << " " << (!isStand ? u8"悬空地 " : "")
				<< u8"在" <<Dimension(dimension)<< " " << Coordinator(coordinator) << " "
				<< operation << " "
				<< block_name_inner << " " << u8"方块。"
				<< std::endl;
		}
		void Item(const std::string& title, const std::string& player_name, char isStand, int dimension, const std::string& operation, const std::string& item_name, INT32 coordinator[]) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家" << " " << player_name << " " << (!isStand ? u8"悬空地 " : "")
				<< u8"在" << Dimension(dimension) << " " << Coordinator(coordinator) << " "
				<< operation << " "
				<< item_name << " " << u8"物品。"
				<< std::endl;
		}
		void Interaction(const std::string& title, const std::string& player_name, char isStand, int dimension, const std::string& operation, const std::string& object_name, INT32 coordinator[]) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家" << " " << player_name << " " << (!isStand ? u8"悬空地 " : "")
				<< operation 
				<< u8"在" << Dimension(dimension) << " " << Coordinator(coordinator) << " " << u8"的"
				<< object_name << u8"。"
				<< std::endl;
		}
		void Container_In(const std::string& title, const std::string& player_name, int dimension, int slot, int count, const std::string& object_name) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家" << " " << player_name << " "
				<< u8"在" << " " << slot << " " << u8"槽内"
				<< u8"放入" << " "
				<< count << " " << u8"个" << " "
				<< object_name << " " << u8"物品。"
				<< std::endl;
		}
		void Container_Out(const std::string& title, const std::string& player_name, int dimension, int slot) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家" << " " << player_name << " "
				<< u8"取出" << " " << slot << " " << u8"槽内物品。"
				<< std::endl;
		}

		void ChangeDimension(const std::string& title, const std::string& player_name, int dimension, Vec3 *v) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家 " << player_name << u8" 改变维度至 "
				<< Dimension(dimension) << " " << Pos(v) + u8"。"
				<< std::endl;
		}

		void ChatMessage(const std::string& title, const std::string& player_name, const std::string& target,
			const std::string& msg, const std::string& chat_style) {
			std::cout
				<< Title(title) << " "
				<< u8"玩家 " << player_name << (target != "" ? u8" 悄悄地对 " + target : "")
				<< u8" 说:" << msg
				<< std::endl;
		}

	}

	namespace Dieinfo {
		using namespace Helper;
		void showDie(const std::string& title, const std::string& mob_name, const std::string& src_name) {
			std::cout
				<< Title(title) << " "
				<< mob_name << u8" 被 " << ((src_name != "") ? src_name : " ") << u8" 杀死了" << std::endl;
		}
	}
};

// 玩家放置方块
THook(__int64,
	MSSYM_B1QE21onBlockPlacedByPlayerB1AE34VanillaServerGameplayEventListenerB2AAA4UEAAB1QE14AW4EventResultB2AAE10AEAVPlayerB2AAA9AEBVBlockB2AAE12AEBVBlockPosB3AAUA1NB1AA1Z,
	void* _this, Player* pPlayer, const Block* pBlk, const BlockPos* pBlkpos, bool _bool) {
	Log::Player::Block("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"放置", pBlk->getLegacyBlock()->getFullName(), pBlkpos->getPosition());
	return original(_this, pPlayer, pBlk, pBlkpos, _bool);
}
// 玩家操作物品
THook(bool,
	MSSYM_B1QA9useItemOnB1AA8GameModeB2AAA4UEAAB1UE14NAEAVItemStackB2AAE12AEBVBlockPosB2AAA9EAEBVVec3B2AAA9PEBVBlockB3AAAA1Z,
	void* _this, ItemStack* item, const BlockPos* pBlkpos, unsigned __int8 a4, void *v5, Block* pBlk) {
	auto pPlayer = *reinterpret_cast<Player * *>(reinterpret_cast<VA>(_this) + 8);
	std::string mstr = "";
	item->getName(mstr);
	bool ret = original(_this, item, pBlkpos, a4, v5, pBlk);
	if (ret) {
		Log::Player::Item("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"操作", mstr, pBlkpos->getPosition());
	}
	return ret;
}
// 玩家破坏方块
THook(bool,
	MSSYM_B2QUE20destroyBlockInternalB1AA8GameModeB2AAA4AEAAB1UE13NAEBVBlockPosB2AAA1EB1AA1Z,
	void * _this, const BlockPos* pBlkpos) {
	auto pPlayer = *reinterpret_cast<Player * *>(reinterpret_cast<VA>(_this) + 8);
	auto pBlockSource = *(BlockSource * *)(*((__int64*)_this + 1) + 840i64);
	auto pBlk = pBlockSource->getBlock(pBlkpos);
	auto block_name = pBlk->getLegacyBlock()->getFullName();
	bool ret = original(_this, pBlkpos);
	if (!ret)
		return ret;
	Log::Player::Block("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"破坏", block_name, pBlkpos->getPosition());
	return ret;
}

// 玩家打开箱子
THook(void,
	MSSYM_B1QA9startOpenB1AE15ChestBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player* pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"开启", u8"箱子", pBlkpos->getPosition());
	original(_this, pPlayer);
}
// 玩家打开木桶
THook(void,
	MSSYM_B1QA9startOpenB1AE16BarrelBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player* pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"开启", u8"木桶", pBlkpos->getPosition());
	original(_this, pPlayer);
}
// 玩家关闭箱子
THook(__int64,
	MSSYM_B1QA8stopOpenB1AE15ChestBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player * pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"关闭", u8"箱子", pBlkpos->getPosition());
	return original(_this, pPlayer);
}
// 玩家关闭木桶
THook(__int64,
	MSSYM_B1QA8stopOpenB1AE16BarrelBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player* pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->isStand(), pPlayer->getDimension(), u8"关闭", u8"木桶", pBlkpos->getPosition());
	return original(_this, pPlayer);
}

// 玩家放入取出数量
THook(void,
	MSSYM_B1QA7setSlotB1AE26LevelContainerManagerModelB2AAE28UEAAXHAEBUContainerItemStackB3AAUA1NB1AA1Z,
	LevelContainerManagerModel * _this, int a2, ContainerItemStack * a3) {
	auto slot = a2;
	auto pItemStack = a3;
	auto id = pItemStack->getId();
	auto size = pItemStack->getStackSize();
	auto pPlayer = _this->getPlayer();
	if (id >= 0) {
		std::string object_name;
		pItemStack->getName(object_name);
		if (size == 0) {
			Log::Player::Container_Out("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), slot);
		} else
			Log::Player::Container_In("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), slot, size, object_name);
	} else
		Log::Player::Error("Warning", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), u8"使用了未知方块！");
	original(_this, a2, a3);
}

// 玩家切换维度
THook(bool,
	MSSYM_B2QUE21playerChangeDimensionB1AA5LevelB2AAA4AEAAB1UE11NPEAVPlayerB2AAE26AEAVChangeDimensionRequestB3AAAA1Z,
	void* _this, Player* pPlayer, void* req) {
	bool ret = original(_this, pPlayer, req);
	if (ret)
		Log::Player::ChangeDimension("Dimension", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), pPlayer->getPos());
	return ret;
}

// 命名生物死亡
THook(void,
	MSSYM_B1QA3dieB1AA3MobB2AAE26UEAAXAEBVActorDamageSourceB3AAAA1Z,
	Mob* _this, void* dmsg) {
	auto mob_name = _this->getNameTag()->c_str();
	if (strlen(mob_name) != 0) {
		char v72;
		__int64  v2[2];
		v2[0] = (__int64)_this;
		v2[1] = (__int64)dmsg;
		auto v7 = *((__int64*)(v2[0] + 856));
		auto srActid = (__int64*)(*(__int64(__fastcall * *)(__int64, char*))(*(__int64*)v2[1] + 56i64))(
			v2[1],
			&v72);
		auto SrAct = SYM_CALL(const Actor * (*)(__int64, __int64, char),
			MSSYM_B1QE11fetchEntityB1AA5LevelB2AAE13QEBAPEAVActorB2AAE14UActorUniqueIDB3AAUA1NB1AA1Z,
			v7, *srActid, 0);
		auto sr_name = "";
		if (SrAct) {
			sr_name = SrAct->getNameTag()->c_str();
		}
		Log::Dieinfo::showDie("DeathInfo", mob_name, sr_name);
	}
	original(_this, dmsg);
}

// 聊天消息
THook(void,
	MSSYM_MD5_ad251f2fd8c27eb22c0c01209e8df83c,
	void * _this, std::string& player_name, std::string& target, std::string& msg, std::string& char_style) {
	original(_this, player_name, target, msg, char_style);
	Log::Player::ChatMessage("Chat", player_name, target, msg, char_style);
}



// 下面两个函数不是必要的，你可以使用，也可以不使用。
void mod_init() {
	// 此处填写模块加载时候的操作
	// system("chcp 65001");
	std::cout << u8"{监控插件已加载。" << std::endl;
}
void mod_exit() {
	// 此处填写模块卸载时候的操作
}
