.set LOCALID_ROCKET_M, 1

SageCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SageCave_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SageCave_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SageCave_OnTransition
	.byte 0
	
SageCave_EventScript_OnLoad::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	call SageCave_EventScript_CheckBrokenElevator
	end
	
SageCave_OnFrame::
	map_script_2 VAR_TEMP_D, 2, SageCave_EventScript_ExitElevator
	.2byte 0
	
SageCave_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAGE_CAVE
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

SageCave_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SageCave_Movement_ExitElevator
	waitmovement 0
	releaseall
	end
	
SageCave_EventScript_CheckBrokenElevator::
	goto_if_set FLAG_HORROR_DONE, SageCave_EventScript_ElevatorBackOpen
	return
	
SageCave_EventScript_ElevatorBackOpen::
	setvar VAR_TEMP_1, 1
	return
	
SageCave_EventScript_ElevatorBroken::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	msgbox SageCave_Text_OutOfOrder
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SageCave_Movement_ForcePlayerFromDoor
	waitmovement 0
	releaseall
	end	
	
SageCave_Movement_ForcePlayerFromDoor::
	walk_down
	step_end
	
SageCave_EventScript_RocketLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SageCave_EventScript_Rocket
	end

SageCave_EventScript_RocketMiddle::
	lockall
	setvar VAR_TEMP_1, 1
	goto SageCave_EventScript_Rocket
	end

SageCave_EventScript_RocketRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto SageCave_EventScript_Rocket
	end
	
SageCave_EventScript_Rocket::
	playbgm MUS_ENCOUNTER_ROCKET, 0
	compare VAR_TEMP_1, 0
	call_if_eq SageCave_EventScript_RocketTwoSteps
	compare VAR_TEMP_1, 1
	call_if_eq SageCave_EventScript_RocketOneStep
	compare VAR_TEMP_1, 2
	call_if_eq SageCave_EventScript_RocketNoSteps
	textcolor 0
	msgbox SageCave_Text_RocketWhat
	closemessage
	fadeoutbgm 0
	fadeinbgm 1
	end
	
SageCave_EventScript_RocketTwoSteps::
	applymovement LOCALID_ROCKET_M, SageCave_Movement_RocketTwoSteps
	waitmovement 0
	return

SageCave_EventScript_RocketOneStep::
	applymovement LOCALID_ROCKET_M, SageCave_Movement_RocketOneStep
	waitmovement 0
	return

SageCave_EventScript_RocketNoSteps::
	applymovement LOCALID_ROCKET_M, SageCave_Movement_RocketNoSteps
	waitmovement 0
	return

SageCave_Movement_RocketTwoSteps::
	emote_exclamation_mark
	delay_16
	walk_left
	walk_left	
	step_end
	
SageCave_Movement_ExitElevator::
	walk_down
	walk_down
	step_end
	
SageCave_Movement_RocketOneStep::
	emote_exclamation_mark
	delay_16
	walk_left	
	step_end
	
SageCave_Movement_RocketNoSteps::
	emote_exclamation_mark
	delay_16	
	step_end