#ifndef GUARD_SAVE_LOCATION_H
#define GUARD_SAVE_LOCATION_H

// specialSaveWarp flags
#define CONTINUE_GAME_WARP           (1 << 0)
#define POKECENTER_SAVEWARP          (1 << 1)
#define LOBBY_SAVEWARP               (1 << 2)
#define UNK_SPECIAL_SAVE_WARP_FLAG_3 (1 << 3)

void TrySetMapSaveWarpStatus(void);
bool32 IsCurMapPokeCenter(void);
void sub_810B810(void);
void sub_810B82C(void);

#endif // GUARD_SAVE_LOCATION_H
