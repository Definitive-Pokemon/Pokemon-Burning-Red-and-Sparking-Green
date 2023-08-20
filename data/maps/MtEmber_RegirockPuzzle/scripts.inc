MtEmber_RegirockPuzzle_MapScripts::
	.byte 0

MtEmber_RegirockPuzzle_OnLoad::
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER, 100
	call_if_ne MtEmber_RegirockPuzzle_EventScript_SetRockBarrier
	call_if_eq MtEmber_RegirockPuzzle_EventScript_MoveSwitchBoulder
	end
	
MtEmber_RegirockPuzzle_EventScript_MoveSwitchBoulder::
	setobjectxyperm 6, 9, 6
	return
	
MtEmber_RegirockPuzzle_SetRockBarrier::
	setmetatile 6, 8, METATILE_Cave_RockBarrier_Top, 1
	return
	
MtEmber_RegirockPuzzle_EventScript_FloorSwitch::
	lockall
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER, 100
	goto_if_eq MtEmber_RegirockPuzzle_EventScript_FloorSwitchAlreadyPressed
	setmetatile 6, 8, METATILE_MtEmber_Braille, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	moveobjectoffscreen 6
	setvar VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER, 100
	releaseall
	end
	
MtEmber_RegirockPuzzle_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end
	
