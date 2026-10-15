// PC port only: debugging switches read from the environment.

#include "PcDebug.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants/scene.hpp"

static const struct {
    const char *name;
    int id;
} sSceneNames[] = {
    { "battle", SCENE_BATTLE },
    { "field", SCENE_FIELD },
    { "letter", SCENE_LETTER },
    { "styler", SCENE_STYLER },
    { "option", SCENE_OPTION },
    { "battle_to_field", SCENE_BATTLE_TO_FIELD },
    { "field_to_menu", SCENE_FIELD_TO_MENU },
    { "release", SCENE_RELEASE },
    { "ranger_net_1", SCENE_RANGER_NET_1 },
    { "ranger_net_agb", SCENE_RANGER_NET_AGB },
    { "mission_quest", SCENE_MISSION_QUEST },
    { "flying", SCENE_FLYING },
    { "unused", SCENE_UNUSED },
    { "ranger_net_2", SCENE_RANGER_NET_2 },
    { "title", SCENE_TITLE },
    { "continue", SCENE_CONTINUE },
    { "conf", SCENE_CONF },
    { "company_logo", SCENE_COMPANY_LOGO },
    { "opening_demo", SCENE_OPENING_DEMO },
    { "sex_select", SCENE_SEX_SELECT },
    { "name_input", SCENE_NAME_INPUT },
    { "auto_save", SCENE_AUTO_SAVE },
    { "browser", SCENE_BROWSER },
    { "encyclopedia", SCENE_ENCYCLOPEDIA },
    { "record", SCENE_RECORD },
    { "retry", SCENE_RETRY },
    { "staffroll", SCENE_STAFFROLL },
    { "suite_picture", SCENE_SUITE_PICTURE },
    { "download_mission_start", SCENE_DOWNLOAD_MISSION_START },
    { "download_mission_end", SCENE_DOWNLOAD_MISSION_END },
    { "download_mission_restart", SCENE_DOWNLOAD_MISSION_RESTART },
    { "quest_list", SCENE_QUEST_LIST },
    { "map_disp", SCENE_MAP_DISP },
    { "card_access_error", SCENE_CARD_ACCESS_ERROR },
};

// PC_START_SCENE=<name or number>: the first scene instead of the normal boot sequence (e.g. title). Scenes that
// expect earlier setup (save data, a started game) may not work when entered directly.
int PcDebug_StartScene(int defaultScene)
{
    const char *env = getenv("PC_START_SCENE");
    if (env == NULL || *env == '\0') {
        return defaultScene;
    }
    char *end;
    long n = strtol(env, &end, 10);
    if (*end == '\0') {
        fprintf(stderr, "PC_START_SCENE: starting in scene %ld\n", n);
        return (int)n;
    }
    for (size_t i = 0; i < sizeof(sSceneNames) / sizeof(sSceneNames[0]); i++) {
        if (strcmp(env, sSceneNames[i].name) == 0) {
            fprintf(stderr, "PC_START_SCENE: starting in scene %s (%d)\n", env, sSceneNames[i].id);
            return sSceneNames[i].id;
        }
    }
    fprintf(stderr, "PC_START_SCENE: unknown scene '%s'; known:", env);
    for (size_t i = 0; i < sizeof(sSceneNames) / sizeof(sSceneNames[0]); i++) {
        fprintf(stderr, " %s", sSceneNames[i].name);
    }
    fprintf(stderr, "\n");
    return defaultScene;
}
