DottedHole_RegicePuzzle_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DottedHole_RegicePuzzle_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, DottedHole_RegicePuzzle_OnResume
	map_script MAP_SCRIPT_ON_LOAD, DottedHole_RegicePuzzle_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DottedHole_RegicePuzzle_OnTransition
	.byte 0
	
DottedHole_RegicePuzzle_OnTransition::
	setvar VAR_ICE_STEP_COUNT, 1
	end
	
DottedHole_RegicePuzzle_OnResume::
	setstepcallback STEP_CB_REGICE_PUZZLE
	end

DottedHole_RegicePuzzle_OnLoad::
	special SetRegicePuzzleCrackedIceMetatiles
	goto_if_set FLAG_REGICE_DOOR_OPENED, DottedHole_RegicePuzzle_EventScript_UnSetRockBarrier	
	end
	
DottedHole_RegicePuzzle_EventScript_UnSetRockBarrier::
	setmetatile 4, 1, METATILE_SeamfoamIslands_IceUnderIce, 0
	return

DottedHole_RegicePuzzle_OnFrame::
	map_script_2 VAR_ICE_STEP_COUNT, 55, DottedHole_RegicePuzzle_EventScript_UnlockDoor
	map_script_2 VAR_ICE_STEP_COUNT, 0, DottedHole_RegicePuzzle_EventScript_FallThroughIce
	.2byte 0
	
DottedHole_RegicePuzzle_EventScript_UnlockDoor::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	special DrawWholeMapView
	setmetatile 4, 11, METATILE_SeafoamIslands_RockUnderIce, 1
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
	setflag FLAG_REGICE_DOOR_OPENED
	releaseall
	end
	
DottedHole_RegicePuzzle_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, DottedHole_RegicePuzzle_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_DOTTED_HOLE_REGICE_PUZZLE2
	waitstate
	releaseall
	end
	
DottedHole_RegicePuzzle_Movement_FallThroughIce::
	set_invisible
	step_end