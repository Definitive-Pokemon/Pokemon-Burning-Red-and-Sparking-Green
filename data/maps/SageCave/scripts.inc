SageCave_MapScripts::
	.byte 0
	
SageCave_OnFrame::
	map_script_2 VAR_TEMP_D, 17, SageCave_EventScript_ExitElevator
	.2byte 0

SageCave_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	releaseall
	end