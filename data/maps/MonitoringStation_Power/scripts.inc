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
	playbgm SE_BERRY_BLENDER 1
	return
	
MonitoringStation_Power_EventScript_Rocket::
	lock
	msgbox MonitoringStation_Power_Text_Rocket
	closemessage
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
	msgbox MonitoringStation_Power_Text_Lance
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Mom::
	lock
	msgbox MonitoringStation_Power_Text_Mom
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Giovanni::
	lock
	msgbox MonitoringStation_Power_Text_Giovanni
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Restore_Power::
	lock
	removeobject LOCALID_MOM
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_LANCE
	removeobject LOCALID_GYM_SIGN
	goto_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Working
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
	
MonitoringStation_Power_EventScript_Working::
	msgbox MonitoringStation_Power_Text_Working
	waitmessage
	release
	end