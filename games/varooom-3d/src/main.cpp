/*
 * Copyright (c) 2020-2022 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "bn_core.h"
#include "bn_memory.h"
#include "bn_string_view.h"

#include "fr_win_scene.h"
#include "fr_scene_type.h"
#include "fr_lose_scene.h"
#include "fr_race_scene.h"
#include "fr_title_scene.h"
#include "fr_common_stuff.h"
#include "fr_credits_scene.h"
#include "fr_jam_intro_scene.h"
#include "fr_brightness_scene.h"
#include "fr_how_to_play_scene.h"
#include "fr_butano_intro_scene.h"
#include "fr_model_viewer_scene.h"

#if FR_PROFILE
    #include "bn_log.h"
#endif

int main()
{
    #if FR_PROFILE
        constexpr const char* profile_keys =
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"
            "10101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"
            "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0101010101010101010101010101010101010A0A0A0A0A0A0A0"
            "A0A0A0A0A0A01010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101011111111111111101010101010101010101010101010101010101010"
            "1010A0A0A0A0A0A01010101010101010101010101010101010101010101010101010101010101010101010A0A0A0A0A0A0A01010101010101010101010101010101010101010101010101010101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0101010101010101010101010101010"
            "10A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A01010101010101010A0A0A0A0A010101010101010101818181818181818A8A8A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0101010101010101010101010101010101010101010101010101010"
            "101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A01010101010101010101010101010101011111111111111111111111111111111111111111111111110101010101010101010101010101010101111111111111111111111111111111111111111111111111111111111111111111111"
            "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110101010101010101010101010111111111111111111111111111111111111111111111111111111101010101010101010101010101010101111111111111110"
            "1010101010101010101010101010101010101010101010101010111111111111111110101010101010101010101010101010101010101010101010101011111111111111111111111010101010101010101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A010101010101010101010101010A0A0"
            "A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A010101010101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0"
            "A0A0A0A0A0A0A0A0A0A0A0A010101010101010101010101010101010101010101010101010181818181818181818181810101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101011111111111111111111111111111111"
            "1110101010101010101010101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A01010101010101010101010A0A0A0A0A0A0A0A0101010101010101010A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A01010101010101010A0A0A0A0A0A0"
            "A0A0A0A0A0A010101010101010101010101010101010101010101010101010101010101010101010101010101010101011111111101010101010101010101010101010101010101010101011111111101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"
            "10101010101010101010101010101010101010100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010101010101010101010101010101010101010101010101010101010"
            "10101010101010101010100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

        bn::core::init(profile_keys);

        BN_LOG("iwram: ", bn::memory::used_static_iwram());
        BN_LOG("ewram: ", bn::memory::used_static_ewram());

        bn::unique_ptr<fr::common_stuff> common_stuff(new fr::common_stuff());
        common_stuff->storage.set_difficulty(fr::difficulty_level::EASY);
        common_stuff->storage.set_reverse_race(false);

        bn::optional<fr::scene_type> next_scene = fr::scene_type::RACE;
    #else
        bn::core::init();

        bn::unique_ptr<fr::common_stuff> common_stuff(new fr::common_stuff());

        #if FR_SKIP_RACE_INTRO
            bn::optional<fr::scene_type> next_scene = fr::scene_type::RACE;
        #else
            bn::optional<fr::scene_type> next_scene;

            if(common_stuff->storage.brightness_scene_shown())
            {
                next_scene = fr::scene_type::BUTANO_INTRO;
            }
            else
            {
                next_scene = fr::scene_type::BRIGHTNESS;
            }
        #endif
    #endif

    bn::unique_ptr<fr::scene> scene;

    while(true)
    {
        if(scene)
        {
            next_scene = scene->update();
        }

        if(next_scene)
        {
            if(scene)
            {
                scene.reset();
            }
            else
            {
                switch(*next_scene)
                {

                case fr::scene_type::BRIGHTNESS:
                    scene.reset(new fr::brightness_scene(*common_stuff));
                    break;

                case fr::scene_type::BUTANO_INTRO:
                    scene.reset(new fr::butano_intro_scene(*common_stuff));
                    break;

                case fr::scene_type::JAM_INTRO:
                    scene.reset(new fr::jam_intro_scene());
                    break;

                case fr::scene_type::TITLE:
                    scene.reset(new fr::title_scene(*common_stuff));
                    break;

                case fr::scene_type::HOW_TO_PLAY_AND_RACE:
                    scene.reset(new fr::how_to_play_scene(fr::scene_type::RACE, *common_stuff));
                    break;

                case fr::scene_type::HOW_TO_PLAY_AND_TITLE:
                    scene.reset(new fr::how_to_play_scene(fr::scene_type::TITLE, *common_stuff));
                    break;

                case fr::scene_type::RACE:
                    scene.reset(new fr::race_scene(*common_stuff));
                    break;

                case fr::scene_type::WIN:
                    scene.reset(new fr::win_scene(*common_stuff));
                    break;

                case fr::scene_type::LOSE:
                    scene.reset(new fr::lose_scene(*common_stuff));
                    break;

                case fr::scene_type::MODEL_VIEWER:
                    scene.reset(new fr::model_viewer_scene(*common_stuff));
                    break;

                case fr::scene_type::CREDITS:
                    scene.reset(new fr::credits_scene(*common_stuff));
                    break;

                default:
                    BN_ERROR("Invalid next scene: ", int(*next_scene));
                    break;
                }
            }
        }

        common_stuff->update();
        bn::core::update();
    }
}
