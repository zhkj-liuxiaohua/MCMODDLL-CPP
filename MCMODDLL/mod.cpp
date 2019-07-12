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

std::map<short, std::string> BlockRegMap;

static std::string UTF8ToGBK(const char* strUTF8);

// 注册方块的时候构建方块ID查找表
THook(void,
	MSSYM_B1QE14registerBlocksB1AE17VanillaBlockTypesB2AAA5YAXXZ,
	void* _this) {
	original(_this);
	std::unordered_map<std::string, SharedPtr<BlockLegacy>>* pMap;
	pMap = SYM_PTR(decltype(pMap), MSSYM_MD5_ceb8b47184006e4d7622b39978535236);
	for (auto i = pMap->begin(); i != pMap->end(); ++i) {
		auto id = i->second->getBlockItemID();
		auto str = std::string("Mincraft: " + id);
			//i->second->getFullName();
		BlockRegMap.emplace(id, str);
	}
}

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

		auto Dimension(int v) {
			switch (v) {
			case 0: return "主世界";
			case 1: return "地狱";
			case 2: return "末地";
			}
			return "未知维度";
		}
	}

	namespace Player {
		using namespace Helper;

		void Error(const std::string& title, const std::string& player_name, int dimension, const std::string& content) {
			std::cout
				<< Title(title) << " "
				<< "玩家" << " " << player_name << " "
				<< "在" << Dimension(dimension)
				<< content << std::endl;
		}
		void Block(const std::string& title, const std::string& player_name, int dimension, const std::string& operation, const std::string & block_name, INT32 coordinator[]) {
			auto block_name_inner = block_name;
			if (block_name_inner == "")
				block_name_inner = "未知类型";
			std::cout
				<< Title(title) << " "
				<< "玩家" << " " << player_name << " "
				<< "在" <<Dimension(dimension)<< " " << Coordinator(coordinator) << " "
				<< operation << " "
				<< block_name_inner << " " << "方块。"
				<< std::endl;
		}
		void Item(const std::string& title, const std::string& player_name, int dimension, const std::string& operation, const std::string& item_name, INT32 coordinator[]) {
			std::cout
				<< Title(title) << " "
				<< "玩家" << " " << player_name << " "
				<< "在" << Dimension(dimension) << " " << Coordinator(coordinator) << " "
				<< operation << " "
				<< UTF8ToGBK(item_name.data()) << " " << "物品。"
				<< std::endl;
		}
		void Interaction(const std::string& title, const std::string& player_name, int dimension, const std::string& operation, const std::string& object_name, INT32 coordinator[]) {
			std::cout
				<< Title(title) << " "
				<< "玩家" << " " << player_name << " "
				<< operation
				<< "在" << Dimension(dimension) << " " << Coordinator(coordinator) << " " << "的"
				<< object_name << " " << "。"
				<< std::endl;
		}
		void Container_In(const std::string& title, const std::string& player_name, int dimension, int slot, int count, const std::string& object_name) {
			std::cout
				<< Title(title) << " "
				<< "玩家" << " " << player_name << " "
				<< "在" << " " << slot << " " << "槽内"
				<< "放入" << " "
				<< count << " " << "个" << " "
				<< UTF8ToGBK(object_name.data()) << " " << "物品。"
				<< std::endl;
		}
		void Container_Out(const std::string& title, const std::string& player_name, int dimension, int slot) {
			std::cout
				<< Title(title) << " "
				<< "玩家" << " " << player_name << " "
				<< "取出" << " " << slot << " " << "槽内物品。"
				<< std::endl;
		}

	}

	namespace Dieinfo {
		using namespace Helper;
		void showDie(const std::string& title, const std::string& mob_name, const std::string& src_name) {
			std::cout
				<< Title(title) << " "
				<< UTF8ToGBK(mob_name.data()) << " 被 " << ((src_name != "") ? src_name : " ") << " 杀死了" << std::endl;
		}
	}
};

// 玩家放置方块
THook(__int64,
	MSSYM_B1QE21onBlockPlacedByPlayerB1AE34VanillaServerGameplayEventListenerB2AAA4UEAAB1QE14AW4EventResultB2AAE10AEAVPlayerB2AAA9AEBVBlockB2AAE12AEBVBlockPosB3AAUA1NB1AA1Z,
	void* _this, Player* pPlayer, const Block* pBlk, const BlockPos* pBlkpos, bool _bool) {
	Log::Player::Block("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "放置", pBlk->getLegacyBlock()->getFullName(), pBlkpos->getPosition());
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
		Log::Player::Item("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "操作", mstr, pBlkpos->getPosition());
	}
	return ret;
}
// 玩家破坏方块
THook(bool,
	MSSYM_B2QUE20destroyBlockInternalB1AA8GameModeB2AAA4AEAAB1UE13NAEBVBlockPosB2AAA1EB1AA1Z,
	void * _this, const BlockPos* pBlkpos) {
	auto pPlayer = *reinterpret_cast<Player * *>(reinterpret_cast<VA>(_this) + 8);
	auto pBlockSource = *(BlockSource * *)(*((__int64*)_this + 1) + 3320i64);
	auto pBlk = pBlockSource->getBlock(pBlkpos);
	auto block_name = pBlk->getLegacyBlock()->getFullName();
	bool ret = original(_this, pBlkpos);
	if (!ret)
		return ret;
	Log::Player::Block("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "破坏", block_name, pBlkpos->getPosition());
	return ret;
}

// 玩家打开箱子
THook(void,
	MSSYM_B1QA9startOpenB1AE15ChestBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player* pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "开启", "箱子", pBlkpos->getPosition());
	original(_this, pPlayer);
}
// 玩家打开木桶
THook(void,
	MSSYM_B1QA9startOpenB1AE16BarrelBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player* pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "开启", "木桶", pBlkpos->getPosition());
	original(_this, pPlayer);
}

// 玩家关闭箱子
THook(__int64,
	MSSYM_B1QA8stopOpenB1AE15ChestBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player * pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "关闭", "箱子", pBlkpos->getPosition());
	return original(_this, pPlayer);
}
// 玩家关闭木桶
THook(__int64,
	MSSYM_B1QA8stopOpenB1AE16BarrelBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z,
	void* _this, Player* pPlayer) {
	auto real_this = reinterpret_cast<void*>(reinterpret_cast<VA>(_this) - 248);
	auto pBlkpos = reinterpret_cast<BlockActor*>(real_this)->getPosition();
	Log::Player::Interaction("Event", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "关闭", "木桶", pBlkpos->getPosition());
	return original(_this, pPlayer);
}

THook(void,
	MSSYM_B1QA7setSlotB1AE26LevelContainerManagerModelB2AAE28UEAAXHAEBUContainerItemStackB3AAAA1Z,
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
		Log::Player::Error("Warning", pPlayer->getNameTag()->c_str(), pPlayer->getDimension(), "使用了未知方块！");
	original(_this, a2, a3);
}

// 命名生物死亡
THook(void,
	MSSYM_B1QA3dieB1AA3MobB2AAE26UEAAXAEBVActorDamageSourceB3AAAA1Z,
	Mob* _this, void* dmsg) {
	auto mob_name = _this->getNameTag()->c_str();
	if (strlen(mob_name) != 0) {
		char v72;
		auto v7 = *((__int64*)_this + 417);
		auto srActid = (__int64*)(*(__int64(__fastcall * *)(void*, char*))(*(__int64*)dmsg + 56i64))(
			dmsg,
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


// 下面两个函数不是必要的，你可以使用，也可以不使用。
void mod_init() {
	// 此处填写模块加载时候的操作
	std::cout << "{监控插件已加载。" << std::endl;
}
void mod_exit() {
	// 此处填写模块卸载时候的操作
}


/*
 UTF-8 转 GBK
 */
static std::string UTF8ToGBK(const char* strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	std::string strTemp(szGBK);

	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;

	return strTemp;
}

