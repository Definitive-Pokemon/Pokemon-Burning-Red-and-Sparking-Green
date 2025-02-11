.set LOCALID_MACHOKE_MASTER, 2
.set TRAINER, VAR_0x8009

FuchsiaCity_House2_MapScripts:: @ 816D816
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_House2_MapScript_SetMasterTrainerMovementTypes
	.byte 0

FuchsiaCity_House2_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MACHOKE
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq FuchsiaCity_House2_MapScript_MachokeMasterMovementType
	end

FuchsiaCity_House2_MapScript_MachokeMasterMovementType::
	setobjectmovementtype LOCALID_MACHOKE_MASTER, MOVEMENT_TYPE_VS_SEEKER_4D
	return

FuchsiaCity_House2_EventScript_LaprasScience::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SCIENCE, FuchsiaCity_House2_EventScript_AlreadyGotLapras
	msgbox FuchsiaCity_House2_Text_HaveMonForExisting
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 40, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq FuchsiaCity_House2_EventScript_ReceiveLaprasParty
	compare VAR_RESULT, 1
	goto_if_eq FuchsiaCity_House2_EventScript_ReceiveLaprasPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

FuchsiaCity_House2_EventScript_ReceiveLaprasParty:: @ 8161B12
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message FuchsiaCity_House2_Text_ObtainedLaprasFromScientist
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_LAPRAS
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq FuchsiaCity_House2_EventScript_NicknameLaprasParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FuchsiaCity_House2_EventScript_EndReceiveLapras
	FuchsiaCity_House2_EventScript_NicknameLaprasParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto FuchsiaCity_House2_EventScript_EndReceiveLapras
	end

FuchsiaCity_House2_EventScript_ReceiveLaprasPC:: @ 8161B45
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message FuchsiaCity_House2_Text_ObtainedLaprasFromScientist
	waitmessage
	waitfanfare
	getspeciesname 0, SPECIES_LAPRAS
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq FuchsiaCity_House2_EventScript_NicknameLaprasPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FuchsiaCity_House2_EventScript_LaprasTransferredToPC
	FuchsiaCity_House2_EventScript_NicknameLaprasPC::
	call EventScript_NameReceivedBoxMon
	goto FuchsiaCity_House2_EventScript_LaprasTransferredToPC
	end

FuchsiaCity_House2_EventScript_LaprasTransferredToPC:: @ 8161B73
	call EventScript_TransferredToPC
	goto FuchsiaCity_House2_EventScript_EndReceiveLapras
	end

FuchsiaCity_House2_EventScript_EndReceiveLapras:: @ 8161B7E
	textcolor 0
	msgbox FuchsiaCity_House2_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SCIENCE
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotLapras:: @ 8161B8D
	msgbox FuchsiaCity_House2_Text_HowIsLapras
	release
	end