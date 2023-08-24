#include "global.h"
#include "gflib.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "field_camera.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "quest_log.h"
#include "script.h"
#include "task.h"
#include "constants/field_tasks.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

// TODO: Metatile IDs in this file

static void DummyPerStepCallback(u8 taskId);
static void AshGrassPerStepCallback(u8 taskId);
static void IcefallCaveIcePerStepCallback(u8 taskId);
static void RegicePuzzleIcePerStepCallback(u8 taskId);
static void CrackedFloorPerStepCallback(u8 taskId);

static const TaskFunc sPerStepCallbacks[] =
{
    [STEP_CB_DUMMY]             = DummyPerStepCallback,
    [STEP_CB_ASH]               = AshGrassPerStepCallback,
    [STEP_CB_FORTREE_BRIDGE]    = DummyPerStepCallback,
    [STEP_CB_PACIFIDLOG_BRIDGE] = DummyPerStepCallback,
    [STEP_CB_ICE]               = IcefallCaveIcePerStepCallback,
    [STEP_CB_REGICE_PUZZLE]     = RegicePuzzleIcePerStepCallback,
    [STEP_CB_SECRET_BASE]       = DummyPerStepCallback,
    [STEP_CB_CRACKED_FLOOR]     = CrackedFloorPerStepCallback
};

static const u8 sIcefallCaveIceTileCoords[][2] =
{
    {  8,  3 },
    { 10,  5 },
    { 15,  5 },
    {  8,  9 },
    {  9,  9 },
    { 16,  9 },
    {  8, 10 },
    {  9, 10 },
    {  8, 14 }
};

static const u16 sRegicePuzzleIceColumnVars[] =
{
    0,
    0,
    0,
    VAR_TEMP_1,
    VAR_TEMP_2,
    VAR_TEMP_3,
    VAR_TEMP_4,
    VAR_TEMP_5,
    VAR_TEMP_6,
    VAR_TEMP_7,
    VAR_TEMP_8,
    VAR_TEMP_9,
    0,
    0,
    0,
};

static void Task_RunPerStepCallback(u8 taskId)
{
    int idx = gTasks[taskId].data[0];
    sPerStepCallbacks[idx](taskId);
}

static void Task_RunTimeBasedEvents(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!ScriptContext2_IsEnabled())
    {
        if (!QL_IS_PLAYBACK_STATE)
        {
            UpdateAmbientCry(&data[1], &data[2]);
        }
    }
}

void SetUpFieldTasks(void)
{
    if (!FuncIsActiveTask(Task_RunPerStepCallback))
    {
        u8 taskId = CreateTask(Task_RunPerStepCallback, 0x50);
        gTasks[taskId].data[0] = 0;
    }

    if (!FuncIsActiveTask(Task_RunTimeBasedEvents))
        CreateTask(Task_RunTimeBasedEvents, 0x50);
}

void ActivatePerStepCallback(u8 callbackId)
{
    u8 taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != 0xff)
    {
        s32 i;
        s16 *data = gTasks[taskId].data;

        for (i = 0; i < 16; i++)
            data[i] = 0;

        if (callbackId >= NELEMS(sPerStepCallbacks))
        {
            data[0] = 0;
        }
        else
        {
            data[0] = callbackId;
        }
    }
}

void ResetFieldTasksArgs(void)
{
    u8 taskId;
    s16 *data;

    taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != 0xff)
    {
        data = gTasks[taskId].data;
    }
    taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);
    if (taskId != 0xff)
    {
        data = gTasks[taskId].data;
        data[1] = 0;
        data[2] = 0;
    }
}

static void DummyPerStepCallback(u8 taskId)
{
}

static void MarkIcefallCaveCoordVisited(s16 x, s16 y)
{
    u8 i = 0;
    for (; i < NELEMS(sIcefallCaveIceTileCoords); ++i)
    {
        if (sIcefallCaveIceTileCoords[i][0] + 7 == x && sIcefallCaveIceTileCoords[i][1] + 7 == y)
        {
            FlagSet(i + 1);
            break;
        }
    }
}

void SetIcefallCaveCrackedIceMetatiles(void)
{
    u8 i = 0;
    for (; i < NELEMS(sIcefallCaveIceTileCoords); ++i)
    {
        if (FlagGet(i + 1) == TRUE)
        {
            int x = sIcefallCaveIceTileCoords[i][0] + 7;
            int y = sIcefallCaveIceTileCoords[i][1] + 7;
            MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
        }
    }
}

static void IcefallCaveIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u8 tileBehavior;
    u16 *iceStepCount;
    s16 *data = gTasks[taskId].data;
    switch (data[1])
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            data[2] = x;
            data[3] = y;
            data[1] = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            if (x != data[2] || y != data[3])
            {
                data[2] = x;
                data[3] = y;
                tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
                {
                    MarkIcefallCaveCoordVisited(x, y);
                    data[6] = 4;
                    data[1] = 2;
                    data[4] = x;
                    data[5] = y;
                }
                else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
                {
                    data[6] = 4;
                    data[1] = 3;
                    data[4] = x;
                    data[5] = y;
                }
            }
            break;
        case 2:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
                CurrentMapDrawMetatileAt(x, y);
                data[1] = 1;
            }
            break;
        case 3:
            ScriptFreezeObjectEvents();
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_IceHole);
                CurrentMapDrawMetatileAt(x, y);
                VarSet(VAR_TEMP_1, 1);
                data[1] = 1;
            }
            break;
    }
}

static bool32 CoordInIcePuzzleRegion(s16 x, s16 y)
{
    if ((u16)(x - 3) < 11 && (u16)(y - 6) < 14 && sRegicePuzzleIceColumnVars[y])
        return TRUE;
    else
        return FALSE;
}

static void MarkIcePuzzleCoordVisited(s16 x, s16 y)
{
    //if (CoordInIcePuzzleRegion(x, y))
    *GetVarPointer(sRegicePuzzleIceColumnVars[x]) |= (1 << (y - 4));
}

static bool32 IsIcePuzzleCoordVisited(s16 x, s16 y)
{
    u32 var;
    //if (!CoordInIcePuzzleRegion(x, y))
    //    return FALSE;

    var = VarGet(sRegicePuzzleIceColumnVars[x]) << 16;
    if ((0x10000 << (y - 4)) & var) // TODO: fix that if
        return TRUE;
    else
        return FALSE;
}

void SetRegicePuzzleCrackedIceMetatiles(void)
{
    s32 x, y;
    s32 width = gMapHeader.mapLayout->width;
    s32 height = gMapHeader.mapLayout->height;
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            if (IsIcePuzzleCoordVisited(x, y) == TRUE)
                MapGridSetMetatileIdAt(x + 7, y + 7, METATILE_SeafoamIslands_CrackedIce);
        }
    }
}

static void RegicePuzzleIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 tileBehavior;
    u16 *iceStepCount;
    s16 *data = gTasks[taskId].data;
    switch (data[1])
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            data[2] = x;
            data[3] = y;
            data[1] = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            if (x != data[2] || y != data[3])
            {
                data[2] = x;
                data[3] = y;
                tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                iceStepCount = GetVarPointer(VAR_ICE_STEP_COUNT);
                if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
                {
                    (*iceStepCount)++;
                    data[6] = 4;
                    data[1] = 2;
                    data[4] = x;
                    data[5] = y;
                }
                else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
                {
                    *iceStepCount = 0;
                    data[6] = 4;
                    data[1] = 3;
                    data[4] = x;
                    data[5] = y;
                }
            }
            break;
        case 2:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
                CurrentMapDrawMetatileAt(x, y);
                MarkIcePuzzleCoordVisited(x - 7, y - 7);
                data[1] = 1;
            }
            break;
        case 3:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_IceHole);
                CurrentMapDrawMetatileAt(x, y);
                data[1] = 1;
            }
            break;
    }
}

static void AshGrassPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 *ashGatherCount;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    if (x != data[1] || y != data[2])
    {
        data[1] = x;
        data[2] = y;
        if (MetatileBehavior_IsAshGrass(MapGridGetMetatileBehaviorAt(x, y)))
        {
            if (MapGridGetMetatileIdAt(x, y) == METATILE_SeviiIslands123_OneIsland_AshGrass)
                StartAshFieldEffect(x, y, METATILE_SeviiIslands123_OneIsland_Grass, 4);

            if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
            {
                ashGatherCount = GetVarPointer(VAR_ASH_GATHER_COUNT);
                if (*ashGatherCount < 9999)
                    (*ashGatherCount)++;
            }
        }
    }
}

static void SetCrackedFloorHoleMetatile(s16 x, s16 y)
{
    MapGridSetMetatileIdAt(x, y, MapGridGetMetatileIdAt(x, y) == 0x22f ? 0x206 : 0x237);
    CurrentMapDrawMetatileAt(x, y);
}

// This is leftover from pokeruby and effectively a no-op.
static void CrackedFloorPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 behavior;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);
    if (data[4] != 0 && (--data[4]) == 0)
        SetCrackedFloorHoleMetatile(data[5], data[6]);

    if (data[7] != 0 && (--data[7]) == 0)
        SetCrackedFloorHoleMetatile(data[8], data[9]);

    if ((x != data[2] || y != data[3]))
    {
        data[2] = x;
        data[3] = y;
        if (MetatileBehavior_ReturnFalse_13(behavior))
        {
            if (GetPlayerSpeed() != 4)
                VarSet(VAR_ICE_STEP_COUNT, 0);

            if (data[4] == 0)
            {
                data[4] = 3;
                data[5] = x;
                data[6] = y;
            }
            else if (data[7] == 0)
            {
                data[7] = 3;
                data[8] = x;
                data[9] = y;
            }
        }
    }
}

static void sub_806ED38(void)
{
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_SYS_POKEMON_GET);
}
