.set LOCALID_MOM, 1
.set LOCALID_KABUTOPS_SHADOW, 2

FakePallet2_MapScripts::
	.byte 0

FakePallet2_EventScript_Mom1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_FaceMom1
	waitmovement 0
	playse SE_PIN
	waitse
	applymovement LOCALID_MOM FakePallet2_Movement_Ex
	waitmovement 0
	applymovement LOCALID_MOM FakePallet2_Movement_Face
	waitmovement 0
	msgbox FakePallet2_Text_Mom
	applymovement LOCALID_MOM FakePallet2_Movement_Sad
	waitmovement 0
	msgbox FakePallet2_Text_Mom2
	applymovement LOCALID_MOM FakePallet2_Movement_Sad2
	waitmovement 0
	delay 50
	msgbox FakePallet2_Text_Mom3
	playbgm MUS_DUMMY 1
	delay 60
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MOM
	addobject LOCALID_KABUTOPS_SHADOW
	clearflag FLAG_HIDE_MOMBUTOPS
	setflag FLAG_HIDE_MOM
	fadescreen FADE_FROM_BLACK
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW FakePallet2_Movement_Kabutops
	waitmovement 0
	playse SE_BERRY_BLENDER
	goto FakePallet2_EventScript_BrailleMessage
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_Slap1
	waitmovement 0
	warp MAP_MONITORING_STATION_STORAGE, 255, 19, 11
	waitstate
	releaseall
	end
	
FakePallet2_EventScript_Mom2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_FaceMom2
	applymovement LOCALID_MOM FakePallet2_Movement_Face
	playse SE_PIN
	waitse
	applymovement LOCALID_MOM FakePallet2_Movement_Ex
	waitmovement 0
	msgbox FakePallet2_Text_Mom
	applymovement LOCALID_MOM FakePallet2_Movement_Sad
	waitmovement 0
	msgbox FakePallet2_Text_Mom2
	applymovement LOCALID_MOM FakePallet2_Movement_Sad2
	waitmovement 0
	delay 50
	msgbox FakePallet2_Text_Mom3
	playbgm MUS_DUMMY 1
	delay 60
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MOM
	addobject LOCALID_KABUTOPS_SHADOW
	clearflag FLAG_HIDE_MOMBUTOPS
	setflag FLAG_HIDE_MOM
	fadescreen FADE_FROM_BLACK
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW FakePallet2_Movement_Kabutops
	waitmovement 0
	playse SE_BERRY_BLENDER
	goto FakePallet2_EventScript_BrailleMessage
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_Slap2
	waitmovement 0
	warp MAP_MONITORING_STATION_STORAGE, 255, 19, 11
	waitstate
	releaseall
	end

FakePallet2_EventScript_Mom3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_FaceMom3
	applymovement LOCALID_MOM FakePallet2_Movement_Face
	playse SE_PIN
	waitse
	applymovement LOCALID_MOM FakePallet2_Movement_Ex
	waitmovement 0
	msgbox FakePallet2_Text_Mom
	applymovement LOCALID_MOM FakePallet2_Movement_Sad
	waitmovement 0
	msgbox FakePallet2_Text_Mom2
	applymovement LOCALID_MOM FakePallet2_Movement_Sad2
	waitmovement 0
	delay 50
	msgbox FakePallet2_Text_Mom3
	playbgm MUS_DUMMY 1
	delay 60
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MOM
	addobject LOCALID_KABUTOPS_SHADOW
	clearflag FLAG_HIDE_MOMBUTOPS
	setflag FLAG_HIDE_MOM
	fadescreen FADE_FROM_BLACK
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW FakePallet2_Movement_Kabutops
	waitmovement 0
	playse SE_BERRY_BLENDER
	call FakePallet2_EventScript_BrailleMessage
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_Slap3
	waitmovement 0
	warp MAP_MONITORING_STATION_STORAGE, 255, 19, 11
	waitstate
	releaseall
	end
	
FakePallet2_EventScript_BrailleMessage::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Submit
	closemessage
	return
	
FakePallet2_Movement_Face::
	face_player
	step_end
	
FakePallet2_Movement_Ex::
	emote_exclamation_mark
	step_end
	
FakePallet2_Movement_Sad::
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
	face_player
	step_end

FakePallet2_Movement_Sad2::	
	face_original_direction
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
	delay_16
	delay_16
	face_player
	step_end
	
FakePallet2_Movement_FaceMom1::
	walk_in_place_down
	step_end

FakePallet2_Movement_FaceMom2::
	walk_in_place_left
	step_end

FakePallet2_Movement_FaceMom3::
	walk_in_place_up
	step_end
	
FakePallet2_Movement_Slap1::
	jump_down
	step_end
	
FakePallet2_Movement_Slap2::
	jump_left
	step_end
	
FakePallet2_Movement_Slap3::
	jump_up
	step_end
	
FakePallet2_Movement_Kabutops::
	face_player
	step_end