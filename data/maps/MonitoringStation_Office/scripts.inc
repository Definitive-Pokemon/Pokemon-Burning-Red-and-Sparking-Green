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
	special RemoveCameraObject
	delay 60
	playmoncry SPECIES_KABUTOPS, 2
	call MonitoringStation_Office_EventScript_BrailleMessage
	delay 100
	release
	end
	
MonitoringStation_Office_EventScript_BrailleMessage::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Welcome
	closemessage
	return
	
MonitoringStation_Office_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	step_end