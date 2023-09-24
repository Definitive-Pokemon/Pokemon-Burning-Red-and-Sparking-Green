.set LOCALID_KABUTOPS_SHADOW, 1
.set LOCALID_ROCKET_ADMIN, 2

MonitoringStation_Office_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Office_OnFrame
	.byte 0

MonitoringStation_Office_OnFrame::
	map_script_2 VAR_WELCOME, 0, MonitoringStation_Office_EventScript_Welcome
	.2byte 0
	
MonitoringStation_Office_EventScript_Welcome::
	lock
	setvar VAR_WELCOME, 1
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Office_Movement_PanToActionFromTop
	waitmovement 0
	delay 120
	playmoncry SPECIES_KABUTOPS, 2
	call MonitoringStation_Office_EventScript_BrailleMessage1
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_Walk
	waitmovement 0
	delay 100
	call MonitoringStation_Office_EventScript_BrailleMessage2
	delay 80
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminRun
	textcolor 1
	msgbox MonitoringStation_Office_Text_Admin
	closemessage
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_Admin
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminHelp
	closemessage
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Office_Movement_KabWalkUp
	waitmovement 0
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_Attack1
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Office_Movement_KabTurn
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_Attack2
	waitmovement 0
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_Admin
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminNo
	closemessage
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminRunUp
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminPokemon
	closemessage
	release
	end
	
MonitoringStation_Office_Movement_Walk::
	walk_slow_down
	walk_slow_down
	step_end
	
MonitoringStation_Office_Movement_AdminRun::
	set_visible
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end
	
MonitoringStation_Office_Movement_Admin::
	walk_in_place_down
	step_end
	
MonitoringStation_Office_Movement_KabWalkUp::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
	
	MonitoringStation_Office_Movement_Attack1::
	lock_facing_direction
	walk_fast_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_down
	jump_down
	step_end
	
MonitoringStation_Office_Movement_KabTurn::
	walk_fast_down
	step_end
	
MonitoringStation_Office_Movement_Attack2::
	walk_in_place_up
	step_end
	
MonitoringStation_Office_Movement_AdminRunUp::
	walk_fast_up
	walk_fast_right
	walk_in_place_down
	step_end
	
MonitoringStation_Office_EventScript_BrailleMessage1::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Welcome
	closemessage
	return
	
MonitoringStation_Office_EventScript_BrailleMessage2::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Journey
	braillemessage_wait Braille_Text_Gone
	braillemessage_wait Braille_Text_For
	braillemessage_wait Braille_Text_Enough
	closemessage
	return

	
MonitoringStation_Office_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	step_end
	
MonitoringStation_Office_EventScript_BlockAdmin::
	lock
	textcolor 2
	msgbox MonitoringStation_Office_Text_BlockAdmin
	closemessage
	release
	end