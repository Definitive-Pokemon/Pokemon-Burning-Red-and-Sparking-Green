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
	call DottedHole_RegicePuzzle_EventScript_CheckSetIcyMetatiles
	special SetRegicePuzzleCrackedIceMetatiles
	end
	
DottedHole_RegicePuzzle_EventScript_CheckSetIcyMetatiles::
	compare VAR_ICE_STEP_COUNT, 55
	goto_if_lt DottedHole_RegicePuzzle_EventScript_DontShowIcyTile
	
DottedHole_RegicePuzzle_EventScript_DontShowIcyTile::
	return
	
DottedHole_RegicePuzzle_OnFrame::
	map_script_2 VAR_ICE_STEP_COUNT, 55, DottedHole_RegicePuzzle_EventScript_UnlockIcyTile
	map_script_2 VAR_ICE_STEP_COUNT, 0, DottedHole_RegicePuzzle_EventScript_FallThroughIce
	.2byte 0
	
DottedHole_RegicePuzzle_EventScript_UnlockIcyTile::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call DottedHole_RegicePuzzle_EventScript_CheckSetIcyMetatiles
	special DrawWholeMapView
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