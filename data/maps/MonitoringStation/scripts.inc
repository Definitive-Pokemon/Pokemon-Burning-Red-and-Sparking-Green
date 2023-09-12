.set LOCALID_ROCKET_M, 1
.set LOCALID_RED_DOOR, 2
.set LOCALID_RED_DOOR, 3

MonitoringStation_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MonitoringStation_OnTransition
	.byte 0
	
MonitoringStation_EventScript_OnLoad::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	call_if_set FLAG_RED_DOOR_SHORTCUT, MonitoringStation_EventScript_RedDoorShadows
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_EventScript_Restore_Power
	call MonitoringStation_EventScript_CheckBrokenElevator
	end
	
MonitoringStation_EventScript_RedDoorShadows::
	setmetatile 9, 8, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 10, 9, METATILE_SilphCo_HideoutFloor , 0
	setmetatile 10, 10, METATILE_SilphCo_HideoutFloor , 0
	return
	
MonitoringStation_EventScript_RedDoor::
	lock
	checkitem ITEM_RED_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_EventScript_RemoveRedDoor
	message MonitoringStation_Text_RedDoor
	release
	end
	
MonitoringStation_EventScript_RemoveRedDoor::
	setflag FLAG_RED_DOOR_SHORTCUT
	playse SE_UNLOCK
	removeobject LOCALID_RED_DOOR
	message MonitoringStation_Text_RedDoorGone
	release
	end
	
MonitoringStation_EventScript_Restore_Power::
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_OnFrame::
	map_script_2 VAR_TEMP_D, 2, MonitoringStation_EventScript_ExitElevator
	.2byte 0
	
MonitoringStation_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MONITORING_STATION
	getplayerxy VAR_RESULT, VAR_TEMP_D
	end

MonitoringStation_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Movement_ExitElevator
	waitmovement 0
	setvar VAR_TEMP_D, 0
	releaseall
	end
	
MonitoringStation_EventScript_CheckBrokenElevator::
	goto_if_set FLAG_HORROR_DONE, MonitoringStation_EventScript_ElevatorBackOpen
	return
	
MonitoringStation_EventScript_ElevatorBackOpen::
	setvar VAR_TEMP_1, 1
	return
	
MonitoringStation_EventScript_ElevatorBroken::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	msgbox MonitoringStation_Text_OutOfOrder
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Movement_ForcePlayerFromDoor
	waitmovement 0
	releaseall
	end	
	
MonitoringStation_Movement_ForcePlayerFromDoor::
	walk_down
	step_end
	
MonitoringStation_EventScript_RocketLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto MonitoringStation_EventScript_Rocket
	end

MonitoringStation_EventScript_RocketMiddle::
	lockall
	setvar VAR_TEMP_1, 1
	goto MonitoringStation_EventScript_Rocket
	end

MonitoringStation_EventScript_RocketRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto MonitoringStation_EventScript_Rocket
	end
	
MonitoringStation_EventScript_Rocket::
	playbgm MUS_ENCOUNTER_ROCKET, 0
	compare VAR_TEMP_1, 0
	call_if_eq MonitoringStation_EventScript_RocketTwoSteps
	compare VAR_TEMP_1, 1
	call_if_eq MonitoringStation_EventScript_RocketOneStep
	compare VAR_TEMP_1, 2
	call_if_eq MonitoringStation_EventScript_RocketNoSteps
	textcolor 0
	msgbox MonitoringStation_Text_RocketWhat
	closemessage
	fadeoutbgm 0
	playmoncry SPECIES_KABUTOPS, 2
	waitmoncry
	playse SE_PIN
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketScared
	waitmovement 0
	msgbox MonitoringStation_Text_RocketAh
	waitmessage
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveToPlayer
	waitmovement 0
	msgbox MonitoringStation_Text_RocketCheck
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq MonitoringStation_EventScript_RocketMoveTwoSteps
	compare VAR_TEMP_1, 1
	call_if_eq MonitoringStation_EventScript_RocketMoveOneStep
	compare VAR_TEMP_1, 2
	call_if_eq MonitoringStation_EventScript_RocketMoveNoSteps
	playse SE_EXIT
	removeobject LOCALID_ROCKET_M
	setflag FLAG_HORROR_ROCKET_MOVED
	delay 100
	msgbox MonitoringStation_Text_RocketNo
	closemessage
	playbgm MUS_WEATHER_GROUDON, 0
	fadeinbgm 1
	setvar VAR_MAP_SCENE_MONITORING_STATION, 1
	end
	
MonitoringStation_EventScript_RocketMoveTwoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveTwoSteps
	waitmovement 0
	return

MonitoringStation_EventScript_RocketMoveOneStep::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveOneStep
	waitmovement 0
	return

MonitoringStation_EventScript_RocketMoveNoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveNoSteps
	waitmovement 0
	return
	
MonitoringStation_EventScript_RocketTwoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketTwoSteps
	waitmovement 0
	return

MonitoringStation_EventScript_RocketOneStep::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketOneStep
	waitmovement 0
	return

MonitoringStation_EventScript_RocketNoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketNoSteps
	waitmovement 0
	return
	
MonitoringStation_Movement_RocketMoveTwoSteps::
	walk_down
	walk_down
	walk_down
	step_end
	
MonitoringStation_Movement_RocketMoveOneStep::
	walk_down
	walk_left
	walk_down
	walk_down
	step_end
	
MonitoringStation_Movement_RocketMoveNoSteps::
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
	
MonitoringStation_Movement_RocketMove::
	walk_down
	
MonitoringStation_Movement_RocketMoveToPlayer::
	walk_in_place_left
	walk_in_place_down
	walk_in_place_left
	step_end
	
MonitoringStation_Movement_RocketScared::
	emote_exclamation_mark
	walk_in_place_down
	step_end

MonitoringStation_Movement_RocketTwoSteps::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left	
	step_end
	
MonitoringStation_Movement_RocketOneStep::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left	
	step_end
	
MonitoringStation_Movement_RocketNoSteps::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16	
	step_end
	
MonitoringStation_Movement_ExitElevator::
	walk_down
	step_end