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
	end

DottedHole_RegicePuzzle_OnFrame::
	map_script_2 VAR_ICE_STEP_COUNT, 55, DottedHole_RegicePuzzle_EventScript_UnlockDoor
	map_script_2 VAR_ICE_STEP_COUNT, 0, DottedHole_RegicePuzzle_EventScript_FallThroughIce
	.2byte 0
	
DottedHole_RegicePuzzle_EventScript_UnlockDoor::
	goto_if_set FLAG_REGICE_DOOR_OPENED, DottedHole_RegicePuzzle_EventScript_AlreadyDone
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	waitse
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
	fadescreen FADE_TO_BLACK
	setmetatile 3, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 4, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 6, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 7, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 10, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 11, 4, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 3, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 4, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 6, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 7, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 11, 5, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 3, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 4, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 5, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 6, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 7, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 10, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 11, 6, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 3, 7, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 5, 7, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 6, 7, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 7, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 7, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 10, 7, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 3, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 4, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 5, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 7, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 10, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 11, 8, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 3, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 4, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 5, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 6, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 7, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 11, 9, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 3, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 4, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 6, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 7, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 8, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 9, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 10, 10, METATILE_SeafoamIslands_SlidingIce, 0
	setmetatile 11, 10, METATILE_SeafoamIslands_SlidingIce, 0
	playse SE_M_EARTHQUAKE
	waitse
	fadescreen FADE_FROM_BLACK
	fadeinbgm 0
	setflag FLAG_REGICE_DOOR_OPENED
	releaseall
	end
	
DottedHole_RegicePuzzle_EventScript_AlreadyDone::
	releaseall
	end
	
DottedHole_RegicePuzzle_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, DottedHole_RegicePuzzle_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_DOTTED_HOLE_REGICE_PUZZLE
	waitstate
	releaseall
	end
	
DottedHole_RegicePuzzle_Movement_FallThroughIce::
	set_invisible
	step_end