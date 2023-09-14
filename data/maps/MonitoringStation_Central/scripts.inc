.set LOCALID_KABUTOPS_SHADOW, 1
.set LOCALID_ROCKET_M, 2
.set LOCALID_MACHOKE, 3
.set LOCALID_PUSHABLE_BOULDER, 4

MonitoringStation_Central_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Central_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Central_EventScript_OnFrame
	.byte 0
	
MonitoringStation_Central_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Central_EventScript_GreyDoorAdminShadows
	end
	
MonitoringStation_Central_EventScript_OnFrame::
	map_script_2 VAR_MONITORING_STATION_CENTRAL_STATE, 0, MonitoringStation_Central_EventScript_Kabutops
	
MonitoringStation_Central_EventScript_GreyDoorAdminShadows::
	setmetatile 2, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 3, 22, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 3, 23, METATILE_SilphCo_HideoutFloor, 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Central_EventScript_GreyDoors::
	lock
	textcolor 2
	msgbox MonitoringStation_Central_Text_GreyDoor
	closemessage
	release
	end
	
MonitoringStation_Central_EventScript_Kabutops::
	lockall
	setflag FLAG_HORROR_HIDE_BOULDER
	fadeoutbgm 0
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Central_Movement_PanToActionFromTop
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Central_Text_RocketAttack
	waitmessage
	playmoncry SPECIES_MACHOKE, 2
	textcolor 2
	msgbox MonitoringStation_Central_Text_MachokeNoise
	waitmessage
	playse SE_M_VITAL_THROW
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttack
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsTurn
	waitmovement 0
	playse SE_M_VITAL_THROW
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttackBack
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsTurnBack
	waitmovement 0
	playmoncry SPECIES_KABUTOPS, 4
	addobject LOCALID_PUSHABLE_BOULDER
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack
	playmoncry SPECIES_MACHOKE, 5
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeSlammedAway
	waitmovement 0
	releaseall
	end

MonitoringStation_Central_Movement_PanToActionFromTop::
	walk_slow_southeast
	walk_slow_southeast
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

MonitoringStation_Central_Movement_MachokeAttack::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_right
	delay_16
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsTurn::
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_MachokeAttackBack::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_left
	delay_16
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_KabutopsTurnBack::
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsAttack::
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	step_end
	
MonitoringStation_Central_Movement_MachokeSlammedAway::
	walk_in_place_up
	lock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end