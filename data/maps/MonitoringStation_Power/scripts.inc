.set LOCALID_MOM, 1
.set LOCALID_GIOVANNI, 2
.set LOCALID_LANCE, 3
.set LOCALID_GYM_SIGN, 4
.set LOCALID_KABUTOPS_SHADOW, 5

MonitoringStation_Power_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Power_EventScript_OnLoad
	.byte 0

MonitoringStation_Power_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Weather
	call_if_unset FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Music
	end

MonitoringStation_Power_EventScript_Weather::
	setflashradius 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Power_EventScript_Music::
	fadeoutbgm 0
	return
	
MonitoringStation_Power_EventScript_Rocket::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Rocket
	closemessage
	playse SE_M_BUBBLE_BEAM
	waitse
	release
	end
	
MonitoringStation_Power_EventScript_Gym::
	lock
	msgbox MonitoringStation_Power_Text_Gym
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Lance::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Lance
	closemessage
	playse SE_M_LEER
	waitse
	release
	end
	
MonitoringStation_Power_EventScript_Honey1::
	msgbox MonitoringStation_Power_Text_Honey1
	closemessage
	setvar VAR_HONEY1, 1
	end
	
MonitoringStation_Power_EventScript_Honey2::
	msgbox MonitoringStation_Power_Text_Honey2
	closemessage
	setvar VAR_HONEY2, 1
	end
	
MonitoringStation_Power_EventScript_Mom::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Mom
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Giovanni::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Giovanni
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Restore_Power::
	lock
	goto_if_unset FLAG_HORROR_ABSOLUTE, MonitoringStation_Power_EventScript_Absolute
	goto_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Working
	removeobject LOCALID_MOM
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_LANCE
	removeobject LOCALID_GYM_SIGN
	playse SE_PC_LOGIN
	delay 60
	playse SE_M_CONFUSE_RAY
	animateflash 0
	setflashradius 0
	playse SE_SLIDING_DOOR
	setweather WEATHER_NONE
	doweather
	delay 60
	msgbox MonitoringStation_Power_Text_Restore_Power
	waitmessage
	setflag FLAG_HORROR_POWER_RESTORED
	fadeinbgm 1
	release
	end
	
MonitoringStation_Power_EventScript_Absolute::
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Power_Movement_Jump
	fadescreen FADE_TO_BLACK
	fadeinbgm 1
	warp MAP_POKE_CENTER, 255, 8, 5
	release
	end
	
MonitoringStation_Power_EventScript_Working::
	msgbox MonitoringStation_Power_Text_Working
	waitmessage
	release
	end
	
MonitoringStation_Power_Movement_Jump::
	walk_fast_down
	walk_fast_down
	step_end