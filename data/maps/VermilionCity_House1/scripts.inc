VermilionCity_House1_MapScripts:: @ 816B3A6
	.byte 0

VermilionCity_House1_EventScript_FishingGuru:: @ 816B3A7
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod:: @ 816B3CF
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod:: @ 816B3D9
	checkitemspace ITEM_OLD_ROD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod:: @ 816B41A
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

Vermilion_House1_EventScript_FishingGurusBrother:: @ 816D817
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

Vermilion_House1_EventScript_AlreadyGotGoodRod:: @ 816D83F
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

Vermilion_House1_EventScript_GiveGoodRod:: @ 816D849
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

Vermilion_House1_EventScript_NoRoomForGoodRod:: @ 816D88A
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end
