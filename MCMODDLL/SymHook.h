// 该文件内容由PDB工具生成。
// 注意：
// 反修饰后的符号原型可能有误，仅供参考！
// 过长的符号将由其对应的md5值表示该符号对应的标识符。
#pragma once

namespace SymHook{
	using RVA = unsigned int;

	// [原型] private: static class std::unordered_map<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class SharedPtr<class BlockLegacy>,struct std::hash<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > >,struct std::equal_to<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > >,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ,class SharedPtr<class BlockLegacy> > > > BlockTypeRegistry::mBlockLookupMap
	// [符号] ?mBlockLookupMap@BlockTypeRegistry@@0V?$unordered_map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@U?$hash@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@U?$equal_to@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VBlockLegacy@@@@@std@@@2@@std@@A
	constexpr RVA MSSYM_MD5_ceb8b47184006e4d7622b39978535236 = 0x012778F0;

	// [原型] void __cdecl VanillaBlockTypes::registerBlocks(void)
	// [符号] ?registerBlocks@VanillaBlockTypes@@YAXXZ
	constexpr RVA MSSYM_B1QE14registerBlocksB1AE17VanillaBlockTypesB2AAA5YAXXZ = 0x0077DC40;

	// [原型] public: short __cdecl BlockLegacy::getBlockItemId(void)const __ptr64
	// [符号] ?getBlockItemId@BlockLegacy@@QEBAFXZ
	constexpr RVA MSSYM_B1QE14getBlockItemIdB1AE11BlockLegacyB2AAA7QEBAFXZ = 0x0071FEF0;

	// [原型] public: virtual void __cdecl BlockLegacy::playerDestroy(class Player & __ptr64,class BlockPos const & __ptr64,class Block const & __ptr64)const __ptr64
	// [符号] ?playerDestroy@BlockLegacy@@UEBAXAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z
	constexpr RVA MSSYM_B1QE13playerDestroyB1AE11BlockLegacyB2AAE15UEBAXAEAVPlayerB2AAE12AEBVBlockPosB2AAA9AEBVBlockB3AAAA1Z = 0x0071EB30;

	// [原型] public: virtual bool __cdecl ItemFrameBlock::attack(class Player * __ptr64,class BlockPos const & __ptr64)const __ptr64
	// [符号] ?attack@ItemFrameBlock@@UEBA_NPEAVPlayer@@AEBVBlockPos@@@Z
	constexpr RVA MSSYM_B1QA6attackB1AE14ItemFrameBlockB2AAA4UEBAB1UE11NPEAVPlayerB2AAE12AEBVBlockPosB3AAAA1Z = 0x0075EAF0;

	// [原型] public: virtual bool __cdecl ItemFrameBlock::playerWillDestroy(class Player & __ptr64,class BlockPos const & __ptr64,class Block const & __ptr64)const __ptr64
	// [符号] ?playerWillDestroy@ItemFrameBlock@@UEBA_NAEAVPlayer@@AEBVBlockPos@@AEBVBlock@@@Z
	constexpr RVA MSSYM_B1QE17playerWillDestroyB1AE14ItemFrameBlockB2AAA4UEBAB1UE11NAEAVPlayerB2AAE12AEBVBlockPosB2AAA9AEBVBlockB3AAAA1Z = 0x0075E9C0;

	// [原型] public: void __cdecl ItemFrameBlockActor::dropFramedItem(class BlockSource & __ptr64,bool) __ptr64
	// [符号] ?dropFramedItem@ItemFrameBlockActor@@QEAAXAEAVBlockSource@@_N@Z
	constexpr RVA MSSYM_B1QE14dropFramedItemB1AE19ItemFrameBlockActorB2AAE20QEAAXAEAVBlockSourceB3AAUA1NB1AA1Z = 0x006FE0C0;

	// [原型] public: class BlockLegacy const & __ptr64 __cdecl Block::getLegacyBlock(void)const __ptr64
	// [符号] ?getLegacyBlock@Block@@QEBAAEBVBlockLegacy@@XZ
	constexpr RVA MSSYM_B1QE14getLegacyBlockB1AA5BlockB2AAE19QEBAAEBVBlockLegacyB2AAA2XZ = 0x00059940;

	// [原型] public: virtual class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const & __ptr64 __cdecl Actor::getNameTag(void)const __ptr64
	// [符号] ?getNameTag@Actor@@UEBAAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
	constexpr RVA MSSYM_B1QE10getNameTagB1AA5ActorB2AAA8UEBAAEBVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ = 0x003E6C30;

	// [原型] public: virtual class AutomaticID<class Dimension,int> __cdecl Actor::getDimensionId(void)const __ptr64
	// [符号] ?getDimensionId@Actor@@UEBA?AV?$AutomaticID@VDimension@@H@@XZ
	constexpr RVA MSSYM_B1QE14getDimensionIdB1AA5ActorB2AAA4UEBAB1QA2AVB2QDE11AutomaticIDB1AE10VDimensionB2AAA1HB2AAA2XZ = 0x003EBD70;

	// [原型] private: bool __cdecl Level::_playerChangeDimension(class Player * __ptr64,class ChangeDimensionRequest & __ptr64) __ptr64
	// [符号] ?_playerChangeDimension@Level@@AEAA_NPEAVPlayer@@AEAVChangeDimensionRequest@@@Z
	constexpr RVA MSSYM_B2QUE21playerChangeDimensionB1AA5LevelB2AAA4AEAAB1UE11NPEAVPlayerB2AAE26AEAVChangeDimensionRequestB3AAAA1Z = 0x0085F390;

	// [原型] public: virtual void __cdecl Player::teleportTo(class Vec3 const & __ptr64,bool,int,int) __ptr64
	// [符号] ?teleportTo@Player@@UEAAXAEBVVec3@@_NHH@Z
	constexpr RVA MSSYM_B1QE10teleportToB1AA6PlayerB2AAE13UEAAXAEBVVec3B3AAUA3NHHB1AA1Z = 0x00594870;

	// [原型] private: class ServerPlayer * __ptr64 __cdecl ServerNetworkHandler::_getServerPlayer(class NetworkIdentifier const & __ptr64,unsigned char) __ptr64
	// [符号] ?_getServerPlayer@ServerNetworkHandler@@AEAAPEAVServerPlayer@@AEBVNetworkIdentifier@@E@Z
	constexpr RVA MSSYM_B2QUE15getServerPlayerB1AE20ServerNetworkHandlerB2AAE20AEAAPEAVServerPlayerB2AAE21AEBVNetworkIdentifierB2AAA1EB1AA1Z = 0x00251DF0;

	// [原型] public: virtual void __cdecl ServerNetworkHandler::handle(class NetworkIdentifier const & __ptr64,class PlayerActionPacket const & __ptr64) __ptr64
	// [符号] ?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVPlayerActionPacket@@@Z
	constexpr RVA MSSYM_B1QA6handleB1AE20ServerNetworkHandlerB2AAE26UEAAXAEBVNetworkIdentifierB2AAE22AEBVPlayerActionPacketB3AAAA1Z = 0x0024EEA0;

	// [原型] public: virtual void __cdecl ServerNetworkHandler::handle(class NetworkIdentifier const & __ptr64,class MovePlayerPacket const & __ptr64) __ptr64
	// [符号] ?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVMovePlayerPacket@@@Z
	constexpr RVA MSSYM_B1QA6handleB1AE20ServerNetworkHandlerB2AAE26UEAAXAEBVNetworkIdentifierB2AAE20AEBVMovePlayerPacketB3AAAA1Z = 0x0024DC70;

	// [原型] public: virtual void __cdecl Player::jumpFromGround(void) __ptr64
	// [符号] ?jumpFromGround@Player@@UEAAXXZ
	constexpr RVA MSSYM_B1QE14jumpFromGroundB1AA6PlayerB2AAA7UEAAXXZ = 0x00597800;

	// [原型] public: void __cdecl Player::handleJumpEffects(void) __ptr64
	// [符号] ?handleJumpEffects@Player@@QEAAXXZ
	constexpr RVA MSSYM_B1QE17handleJumpEffectsB1AA6PlayerB2AAA7QEAAXXZ = 0x005976B0;

	// [原型] protected: virtual void __cdecl Player::onBounceStarted(class BlockPos const & __ptr64,class Block const & __ptr64) __ptr64
	// [符号] ?onBounceStarted@Player@@MEAAXAEBVBlockPos@@AEBVBlock@@@Z
	constexpr RVA MSSYM_B1QE15onBounceStartedB1AA6PlayerB2AAE17MEAAXAEBVBlockPosB2AAA9AEBVBlockB3AAAA1Z = 0x00596B20;

	// [原型] public: void __cdecl Player::stopGliding(void) __ptr64
	// [符号] ?stopGliding@Player@@QEAAXXZ
	constexpr RVA MSSYM_B1QE11stopGlidingB1AA6PlayerB2AAA7QEAAXXZ = 0x005A3930;

	// [原型] public: virtual void __cdecl Player::travel(float,float,float) __ptr64
	// [符号] ?travel@Player@@UEAAXMMM@Z
	constexpr RVA MSSYM_B1QA6travelB1AA6PlayerB2AAA8UEAAXMMMB1AA1Z = 0x00597390;

	// [原型] public: void __cdecl Actor::setCanFly(bool) __ptr64
	// [符号] ?setCanFly@Actor@@QEAAX_N@Z
	constexpr RVA MSSYM_B1QA9setCanFlyB1AA5ActorB2AAA5QEAAXB1UA1NB1AA1Z = 0x003DF220;

	// [原型] public: __cdecl MovePlayerPacket::MovePlayerPacket(class Player & __ptr64,enum Player::PositionMode,int,int) __ptr64
	// [符号] ??0MovePlayerPacket@@QEAA@AEAVPlayer@@W4PositionMode@1@HH@Z
	constexpr RVA MSSYM_B2QQE170MovePlayerPacketB2AAA4QEAAB1AE10AEAVPlayerB2AAE14W4PositionModeB1AA11B1AA2HHB1AA1Z = 0x00163B20;

	// [原型] protected: virtual void __cdecl Player::onMovePlayerPacketNormal(class Vec3 const & __ptr64,class Vec2 const & __ptr64,float) __ptr64
	// [符号] ?onMovePlayerPacketNormal@Player@@MEAAXAEBVVec3@@AEBVVec2@@M@Z
	constexpr RVA MSSYM_B1QE24onMovePlayerPacketNormalB1AA6PlayerB2AAE13MEAAXAEBVVec3B2AAA8AEBVVec2B2AAA1MB1AA1Z = 0x0059E620;

	// [原型] public: virtual void __cdecl ChestBlockActor::startOpen(class Player & __ptr64) __ptr64
	// [符号] ?startOpen@ChestBlockActor@@UEAAXAEAVPlayer@@@Z
	constexpr RVA MSSYM_B1QA9startOpenB1AE15ChestBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z = 0x006EB510;

	// [原型] public: virtual void __cdecl BarrelBlockActor::startOpen(class Player & __ptr64) __ptr64
	// [符号] ?startOpen@BarrelBlockActor@@UEAAXAEAVPlayer@@@Z
	constexpr RVA MSSYM_B1QA9startOpenB1AE16BarrelBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z = 0x006D4890;

	// [原型] public: virtual void __cdecl FurnaceBlockActor::startOpen(class Player & __ptr64) __ptr64
	// [符号] ?startOpen@FurnaceBlockActor@@UEAAXAEAVPlayer@@@Z
	constexpr RVA MSSYM_B1QA9startOpenB1AE17FurnaceBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z = 0x006F85F0;

	// [原型] public: virtual void __cdecl ChestBlockActor::stopOpen(class Player & __ptr64) __ptr64
	// [符号] ?stopOpen@ChestBlockActor@@UEAAXAEAVPlayer@@@Z
	constexpr RVA MSSYM_B1QA8stopOpenB1AE15ChestBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z = 0x006EB840;

	// [原型] public: virtual void __cdecl BarrelBlockActor::stopOpen(class Player & __ptr64) __ptr64
	// [符号] ?stopOpen@BarrelBlockActor@@UEAAXAEAVPlayer@@@Z
	constexpr RVA MSSYM_B1QA8stopOpenB1AE16BarrelBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z = 0x006D4A00;

	// [原型] public: virtual void __cdecl FurnaceBlockActor::stopOpen(class Player & __ptr64) __ptr64
	// [符号] ?stopOpen@FurnaceBlockActor@@UEAAXAEAVPlayer@@@Z
	constexpr RVA MSSYM_B1QA8stopOpenB1AE17FurnaceBlockActorB2AAE15UEAAXAEAVPlayerB3AAAA1Z = 0x006F8640;

	// [原型] public: void __cdecl BlockEventCoordinator::sendBlockPlacedByPlayer(class Player & __ptr64,class Block const & __ptr64,class BlockPos const & __ptr64,bool) __ptr64
	// [符号] ?sendBlockPlacedByPlayer@BlockEventCoordinator@@QEAAXAEAVPlayer@@AEBVBlock@@AEBVBlockPos@@_N@Z
	constexpr RVA MSSYM_B1QE23sendBlockPlacedByPlayerB1AE21BlockEventCoordinatorB2AAE15QEAAXAEAVPlayerB2AAA9AEBVBlockB2AAE12AEBVBlockPosB3AAUA1NB1AA1Z = 0x005D6090;

	// [原型] public: virtual enum EventResult __cdecl BlockEventListener::onBlockPlacedByPlayer(class Player & __ptr64,class Block const & __ptr64,class BlockPos const & __ptr64,bool) __ptr64
	// [符号] ?onBlockPlacedByPlayer@BlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlock@@AEBVBlockPos@@_N@Z
	constexpr RVA MSSYM_B1QE21onBlockPlacedByPlayerB1AE18BlockEventListenerB2AAA4UEAAB1QE14AW4EventResultB2AAE10AEAVPlayerB2AAA9AEBVBlockB2AAE12AEBVBlockPosB3AAUA1NB1AA1Z = 0x0010EC10;

	// [原型] public: virtual enum EventResult __cdecl VanillaServerGameplayEventListener::onBlockPlacedByPlayer(class Player & __ptr64,class Block const & __ptr64,class BlockPos const & __ptr64,bool) __ptr64
	// [符号] ?onBlockPlacedByPlayer@VanillaServerGameplayEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlock@@AEBVBlockPos@@_N@Z
	constexpr RVA MSSYM_B1QE21onBlockPlacedByPlayerB1AE34VanillaServerGameplayEventListenerB2AAA4UEAAB1QE14AW4EventResultB2AAE10AEAVPlayerB2AAA9AEBVBlockB2AAE12AEBVBlockPosB3AAUA1NB1AA1Z = 0x009B4590;

	// [原型] public: virtual enum EventResult __cdecl ScriptServerBlockEventListener::onBlockPlacedByPlayer(class Player & __ptr64,class Block const & __ptr64,class BlockPos const & __ptr64,bool) __ptr64
	// [符号] ?onBlockPlacedByPlayer@ScriptServerBlockEventListener@@UEAA?AW4EventResult@@AEAVPlayer@@AEBVBlock@@AEBVBlockPos@@_N@Z
	constexpr RVA MSSYM_B1QE21onBlockPlacedByPlayerB1AE30ScriptServerBlockEventListenerB2AAA4UEAAB1QE14AW4EventResultB2AAE10AEAVPlayerB2AAA9AEBVBlockB2AAE12AEBVBlockPosB3AAUA1NB1AA1Z = 0x0035DA10;

	// [原型] public: virtual bool __cdecl GameMode::useItemOn(class ItemStack & __ptr64,class BlockPos const & __ptr64,unsigned char,class Vec3 const & __ptr64,class Block const * __ptr64) __ptr64
	// [符号] ?useItemOn@GameMode@@UEAA_NAEAVItemStack@@AEBVBlockPos@@EAEBVVec3@@PEBVBlock@@@Z
	constexpr RVA MSSYM_B1QA9useItemOnB1AA8GameModeB2AAA4UEAAB1UE14NAEAVItemStackB2AAE12AEBVBlockPosB2AAA9EAEBVVec3B2AAA9PEBVBlockB3AAAA1Z = 0x005E3DE0;

	// [原型] public: virtual void __cdecl LevelContainerManagerModel::setSlot(int,struct ContainerItemStack const & __ptr64) __ptr64
	// [符号] ?setSlot@LevelContainerManagerModel@@UEAAXHAEBUContainerItemStack@@@Z
	constexpr RVA MSSYM_B1QA7setSlotB1AE26LevelContainerManagerModelB2AAE28UEAAXHAEBUContainerItemStackB3AAAA1Z = 0x005CC8E0;

	// [原型] public: short __cdecl ItemStack::getId(void)const __ptr64
	// [符号] ?getId@ItemStack@@QEBAFXZ
	constexpr RVA MSSYM_B1QA5getIdB1AA9ItemStackB2AAA7QEBAFXZ = 0x00646550;

	// [原型] public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __cdecl ItemStack::getName(void)const __ptr64
	// [符号] ?getName@ItemStack@@QEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
	constexpr RVA MSSYM_B1QA7getNameB1AA9ItemStackB2AAA4QEBAB1QA2AVB2QDA5basicB1UA6stringB1AA2DUB2QDA4charB1UA6traitsB1AA1DB1AA3stdB2AAA1VB2QDA9allocatorB1AA1DB1AA12B2AAA3stdB2AAA2XZ = 0x006504B0;

	// [原型] private: bool __cdecl GameMode::_destroyBlockInternal(class BlockPos const & __ptr64,unsigned char) __ptr64
	// [符号] ?_destroyBlockInternal@GameMode@@AEAA_NAEBVBlockPos@@E@Z
	constexpr RVA MSSYM_B2QUE20destroyBlockInternalB1AA8GameModeB2AAA4AEAAB1UE13NAEBVBlockPosB2AAA1EB1AA1Z = 0x005E25F0;

	// [原型] public: class Block const & __ptr64 __cdecl BlockSource::getBlock(class BlockPos const & __ptr64)const __ptr64
	// [符号] ?getBlock@BlockSource@@QEBAAEBVBlock@@AEBVBlockPos@@@Z
	constexpr RVA MSSYM_B1QA8getBlockB1AE11BlockSourceB2AAE13QEBAAEBVBlockB2AAE12AEBVBlockPosB3AAAA1Z = 0x00806C10;

	// [原型] public: virtual void __cdecl Mob::die(class ActorDamageSource const & __ptr64) __ptr64
	// [符号] ?die@Mob@@UEAAXAEBVActorDamageSource@@@Z
	constexpr RVA MSSYM_B1QA3dieB1AA3MobB2AAE26UEAAXAEBVActorDamageSourceB3AAAA1Z = 0x005656F0;

	// [原型] public: class Actor * __ptr64 __cdecl Level::fetchEntity(struct ActorUniqueID,bool)const __ptr64
	// [符号] ?fetchEntity@Level@@QEBAPEAVActor@@UActorUniqueID@@_N@Z
	constexpr RVA MSSYM_B1QE11fetchEntityB1AA5LevelB2AAE13QEBAPEAVActorB2AAE14UActorUniqueIDB3AAUA1NB1AA1Z = 0x00863F60;

}

// 文件结束
