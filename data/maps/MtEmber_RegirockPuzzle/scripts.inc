MtEmber_RegirockPuzzle_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_RegirockPuzzle_OnLoad
	.byte 0

MtEmber_RegirockPuzzle_OnLoad::
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER1, 100
	call_if_ne MtEmber_RegirockPuzzle_EventScript_SetRockBarrier
	call_if_eq MtEmber_RegirockPuzzle_EventScript_MoveSwitchBoulder1
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER2, 100
	call_if_eq MtEmber_RegirockPuzzle_EventScript_MoveSwitchBoulder2
	end
	
MtEmber_RegirockPuzzle_EventScript_MoveSwitchBoulder1::
	setobjectxyperm 6, 9, 6
	return
	
MtEmber_RegirockPuzzle_EventScript_MoveSwitchBoulder2::
	setobjectxyperm 1, 6, 6
	return
	
MtEmber_RegirockPuzzle_EventScript_SetRockBarrier::
	setmetatile 6, 8, METATILE_MtEmber_Braille, 1
	return
	
MtEmber_RegirockPuzzle_EventScript_FloorSwitch1::
	lockall
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER1, 100
	goto_if_eq MtEmber_RegirockPuzzle_EventScript_FloorSwitchAlreadyPressed1
	setmetatile 6, 8, METATILE_MtEmber_Floor, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	moveobjectoffscreen 6
	setvar VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER1, 100
	setflag FLAG_REGIROCK_BRAILLE_GONE
	releaseall
	end
	
MtEmber_RegirockPuzzle_EventScript_FloorSwitch2::
	lockall
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER2, 100
	goto_if_eq MtEmber_RegirockPuzzle_EventScript_FloorSwitchAlreadyPressed2
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	moveobjectoffscreen 6
	setvar VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER2, 100
	fadeoutbgm 0
	special ShakeScreen
	delay 60
	special ShakeScreen
	delay 60
	playse SE_LAVARIDGE_FALL_WARP
	waitse
	playse SE_DOOR
	waitse
	msgbox MtEmberRegirockPuzzle_Text_SomethingHappened, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGIROCK_DOOR_OPENED
	releaseall
	end
	
MtEmber_RegirockPuzzle_EventScript_FloorSwitchAlreadyPressed1::
	releaseall
	end
	
MtEmber_RegirockPuzzle_EventScript_FloorSwitchAlreadyPressed2::
	releaseall
	end
	
MtEmberRegirockPuzzle_EventScript_Braille::
	compare VAR_MAP_SCENE_MT_EMBER_REGIROCK_BOULDER1, 100
	goto_if_eq	MtEmber_RegirockPuzzle_EventScript_NoBraille
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Push
	braillemessage_wait Braille_Text_Rocks
	braillemessage_wait Braille_Text_Onto
	braillemessage Braille_Text_Buttons
	waitbuttonpress
	releaseall
	end
	
MtEmber_RegirockPuzzle_EventScript_NoBraille::
	end