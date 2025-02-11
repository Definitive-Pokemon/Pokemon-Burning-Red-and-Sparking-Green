.set LOCALID_ANABEL, 10

SafariZone_NorthEast_MapScripts::
	.byte 0

SafariZone_NorthEast_EventScript_AreaSign::
	msgbox SafariZone_NorthEast_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_NorthEast_Text_AreaSign::
	.string "AREA 5$"

SafariZone_NorthEast_EventScript_RoughTerrainSign::
	msgbox SafariZone_NorthEast_Text_RoughTerrainSign, MSGBOX_SIGN
	end

SafariZone_NorthEast_Text_RoughTerrainSign::
	.string "NOTICE!\p"
	.string "Rough terrain ahead!\n"
	.string "Exercise caution while exploring!$"
	
SafariZone_NorthEast_EventScript_Anabel::
	lock
	faceplayer
	msgbox SafariZone_NorthEast_Text_Anabel
	closemessage
	applymovement LOCALID_ANABEL, SafariZone_NorthEast_Movement_AnabelConcentrate
	waitmovement 0
	playmoncry SPECIES_AERODACTYL, 2
	waitmoncry
	playmoncry SPECIES_LATIAS, 11
	waitmoncry
	playse SE_PING
	applymovement LOCALID_ANABEL, SafariZone_NorthEast_Movement_AnabelInterrupt
	waitmovement 0
	msgbox SafariZone_NorthEast_Text_AnabelHelp
	closemessage
	applymovement SafariZone_NorthEast_Movement_AnabelContinue
	waitmovement 0
	msgbox SafariZone_NorthEast_Text_AnabelHm
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ANABEL
	setflag FLAG_HIDE_ANABEL_SECOND
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_HIDE_ANABEL_THIRD
	release
	end
	
	
SafariZone_NorthEast_Movement_AnabelConcentrate::
	face_away_player
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end
	
SafariZone_NorthEast_Movement_AnabelInterrupt::
	emote_exclamation_mark
	step_end
	
SafariZone_NorthEast_Movement_AnabelContinue::
	face_player
	step_end
	
SafariZone_NorthEast_Text_Anabel::
	.string "Once again, we were too late…\n"
	.string "LATIAS is gone…\p"
	.string "At this rate, we will keep\n"
	.string "running after it without\p"
	.string "yielding any results…\p"
	.string "For now, I will just connect with\n"
	.string "LATIAS once more…$"
	
SafariZone_NorthEast_Text_AnabelHelp::
	.string "What is going on?\n"
	.string "Something is blocking the eyes…$"
	
SafariZone_NorthEast_Text_AnabelHm::
	.string "I can only see shades of pink.\n"
	.string "Somehow, it reminds me of CLEFAIRY…\p"
	.string "What could this all mean?\p"
	.string "I will have to think about this.\n"
	.string "We will meet again.$"