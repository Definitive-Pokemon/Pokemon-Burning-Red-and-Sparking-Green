SageCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SageCave_EventScript_OnLoad
	.byte 0
	
SageCave_EventScript_OnLoad::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	end
	
SageCave_OnFrame::
	map_script_2 VAR_TEMP_D, 17, SageCave_EventScript_ExitElevator
	.2byte 0

SageCave_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	releaseall
	end
	
SageCave_EventScript_Sign::
	lock
	message SageCave_Text_OutOfOrder
	
SageCave_Text_OutOfOrder::
	.string "The elevator seems to be out of order.$"