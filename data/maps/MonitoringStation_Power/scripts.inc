MonitoringStation_Power_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Power_EventScript_OnLoad
	.byte 0

MonitoringStation_Power_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Weather
	end

MonitoringStation_Power_EventScript_Weather::
	setflashradius 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Power_EventScript_Restore_Power::
	lock
	goto_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Working
	fadeoutbgm 0
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