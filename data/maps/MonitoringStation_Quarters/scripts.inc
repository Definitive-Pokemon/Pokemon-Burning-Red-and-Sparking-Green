.set LOCALID_ROCKET_F1, 1
.set LOCALID_ROCKET_M1, 2
.set LOCALID_ROCKET_M2, 3
.set LOCALID_ROCKET_M3, 4
.set LOCALID_ROCKET_F2, 5
.set LOCALID_ROCKET_M4, 6

MonitoringStation_Quarters_MapScripts::
	.byte 0

MonitoringStation_Quarters_EventScript_RocketM1::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketM1
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM2::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketM2
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM3::
	lock
	faceplayer
	goto_if_set FLAG_QUARTET_TALKED, MonitoringStation_Quarters_EventScript_RocketM3Again
	msgbox MonitoringStation_Quarters_Text_RocketM3
	goto_if_set FLAG_HIDE_MOM, MonitoringStation_Quarters_EventScript_RocketM3Solution
	setflag FLAG_QUARTET_TALKED
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM3Again::
	msgbox MonitoringStation_Quarters_Text_RocketM3Again
	goto_if_set FLAG_HIDE_MOM, MonitoringStation_Quarters_EventScript_RocketM3Solution
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM3Solution::
	msgbox MonitoringStation_Quarters_Text_RocketM3Solution
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROCKET_M3
	setflag FLAG_QUARTET_ACTIVE
	clearflag FLAG_HIDE_CHONKDUO
	fadescreen FADE_FROM_BLACK
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM4::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketM4
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketF1::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketF1
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketF2::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketF2
	waitmessage
	release
	end
