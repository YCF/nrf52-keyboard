/*
Copyright (C) 2019 Geno Kolar <geno@live.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "user_fn.h"
#include "action_util.h"
#include "ble_services.h"
#include "main.h"
#include "status_led.h"
#include "usb_comm.h"
#include "user_func.h"

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))

uint8_t level;
static uint8_t x;
static uint8_t y;
static uint8_t keycode_num[10]={0x27,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26};//0x27=KC_0,0x1E=KC_1..0x26=KC_9

void type_num(uint8_t num)
{
	type_code(keycode_num[num]);
}

void action_function(keyrecord_t* record, uint8_t id, uint8_t opt)
{
    static uint8_t tricky_esc_registered;
    static uint8_t tricky_slsh_registered;
    switch (id) {
    case AF_POWER_SLEEP:
        if (!record->event.pressed) {
            sleep(SLEEP_MANUALLY);
        }
        break;
    case AF_POWER_OFF:
        if (!record->event.pressed) {
            systemoff();
        }
        break;
    case AF_SWITCH_MODE:
        if (!record->event.pressed) {
#ifdef HAS_USB
            usb_comm_switch();
#endif
        }
        break;
    case AF_DELETE_BOND:
        if (!record->event.pressed) {
            delete_bonds();
        }
        break;
    case AF_LED_DISPLAY:
        if (!record->event.pressed) {
            if (!usb_working()) {
                status_led_display();
            }
        }
        break;
    case AF_TRICKY_ESC:
        if (record->event.pressed) {
            if (get_mods() & MODS_SHIFT_MASK) {
                tricky_esc_registered = KC_GRV;
            } else {
                tricky_esc_registered = KC_ESC;
            }
            register_code(tricky_esc_registered);
            send_keyboard_report();
        } else {
            unregister_code(tricky_esc_registered);
            send_keyboard_report();
        }
        break;
    case AF_TRICKY_SLSH:
        if (record->event.pressed) {
            if (get_mods() & MODS_SHIFT_MASK) {
                tricky_slsh_registered = KC_SLSH;
            } else {
                tricky_slsh_registered = KC_UP;
            }
            register_code(tricky_slsh_registered);
            send_keyboard_report();
        } else {
            unregister_code(tricky_slsh_registered);
            send_keyboard_report();
        }
        break;
    case BT_BAT:
        if (record->event.pressed) {
            if (level==100) {
              type_code(KC_1);
              type_code(KC_0);
              type_code(KC_0);
            }else{
              x=level/10;
              y=level-x*10; // y=level%10; which one is faster?
              type_num(x);
              type_num(y);
	   }
        }
        break;
    default:
        break;
    }
}
