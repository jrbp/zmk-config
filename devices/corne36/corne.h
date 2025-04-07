/* Comments are regarding things that if defined here
 * (or removed from elsewhere) would enable deleting
 * miryoku_babel directory */

#define MIRYOKU_LAYER_BASE \
&kp Q,              &kp W,           &kp E,               &kp R,               &kp T,               &kp Y,       &kp U,              &kp I,             &kp O,             &kp P,                \
U_MTL(LGUI, A),     U_MTL(LALT, S),  U_MTL(LCTRL, D),     U_MTL(LSHFT, F),     &kp G,               &kp H,       U_MTR(LSHFT, J),    U_MTR(LCTRL, K),   U_MTR(LALT, L),    U_MTR(LGUI, SQT),     \
U_LT(U_BUTTON, Z),  U_MTL(RALT, X),  &kp C,               &kp V,               &kp B,               &kp N,       &kp M,              &kp COMMA,         U_MTR(RALT, DOT),  U_LT(U_BUTTON, SLASH),\
U_NP,               U_NP,            U_LT(U_MEDIA, ESC),  U_LT(U_NAV, SPACE),  U_LT(U_MOUSE, TAB),  &kp LSHIFT,  U_LT(U_NUM, BSPC),  U_LT(U_FUN, RET),  U_NP,              U_NP

/* #if !defined(MIRYOKU_LAYERMAPPING_BASE) */
/*   #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_MAPPING */
/* #endif */
/* #define MIRYOKU_LAYERMAPPING_EXTRA MIRYOKU_MAPPING */
/* #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_MAPPING */
/* #if !defined(MIRYOKU_LAYER_BUTTON) */
/*   #define MIRYOKU_LAYER_BUTTON MIRYOKU_ALTERNATIVES_BUTTON */
/* #endif */
/* #if !defined(MIRYOKU_LAYERMAPPING_BUTTON) */
/*   #define MIRYOKU_LAYERMAPPING_BUTTON MIRYOKU_MAPPING */
/* #endif */

#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         &u_caps_word,      \
U_NA,              &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       U_NA,              &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           &kp INS,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp LSHIFT,        &kp DEL,           &kp RET,           U_NP,              U_NP

/* #if !defined(MIRYOKU_LAYERMAPPING_NAV) */
/*   #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_MAPPING */
/* #endif */

#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_MS_L,            U_MS_D,            U_MS_U,            U_MS_R,            U_NU,              \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     U_NA,              U_WH_L,            U_WH_D,            U_WH_U,            U_WH_R,            U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP

/* #if !defined(MIRYOKU_LAYERMAPPING_MOUSE) */
/*   #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_MAPPING */
/* #endif */

#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RGB_EFF,         U_RGB_HUI,         U_RGB_SAI,         U_RGB_BRI,         U_RGB_TOG,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &kp C_PREV,        &kp C_VOL_DN,      &kp C_VOL_UP,      &kp C_NEXT,        U_EP_TOG,          \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     U_NA,              &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       &u_out_tog,        \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
&kp LBKT,          &kp N7,            &kp N8,            &kp N9,            &kp RBKT,          U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp SEMI,          &kp N4,            &kp N5,            &kp N6,            &kp EQUAL,         U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
&kp GRAVE,         &kp N1,            &kp N2,            &kp N3,            &kp BSLH,          U_NA,              &kp SPACE,         &kp COMMA,         &kp RALT,          U_NA,              \
U_NP,              U_NP,              &kp DOT,           &kp N0,            &kp MINUS,         &kp LSHIFT,        U_NA,              &kp RET,           U_NP,              U_NP

/* #if !defined(MIRYOKU_LAYER_SYM) */
/*   #if defined (MIRYOKU_LAYERS_FLIP) */
/*     #define MIRYOKU_LAYER_SYM MIRYOKU_ALTERNATIVES_SYM_FLIP */
/*   #else */
/*     #define MIRYOKU_LAYER_SYM MIRYOKU_ALTERNATIVES_SYM */
/*   #endif */
/* #endif */
/* #if !defined(MIRYOKU_LAYERMAPPING_SYM) */
/*   #define MIRYOKU_LAYERMAPPING_SYM MIRYOKU_MAPPING */
/* #endif */


/* #if !defined(MIRYOKU_LAYERMAPPING_MEDIA) */
/*   #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_MAPPING */
/* #endif */

#define MIRYOKU_LAYER_FUN \
&kp F12,           &kp F7,            &kp F8,            &kp F9,            &kp PSCRN,         U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp F11,           &kp F4,            &kp F5,            &kp F6,            &kp SLCK,          U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
&kp F10,           &kp F1,            &kp F2,            &kp F3,            &kp PAUSE_BREAK,   U_NA,              &u_to_U_FUN,       &u_to_U_MEDIA,     &kp RALT,          U_NA,              \
U_NP,              U_NP,              &kp K_APP,         &kp SPACE,         &kp TAB,           U_NA,              &kp DEL,           U_NA,              U_NP,              U_NP

/* #if !defined(MIRYOKU_LAYERMAPPING_FUN) */
/*   #define MIRYOKU_LAYERMAPPING_FUN MIRYOKU_MAPPING */
/* #endif */


#if !defined (MIRYOKU_LAYOUTMAPPING_CORNE)

#define XXX &none

#define MIRYOKU_LAYOUTMAPPING_CORNE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
XXX  K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  XXX \
XXX  K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  XXX \
XXX  K20  K21  K22  K23  K24       K25  K26  K27  K28  K29  XXX \
               K32  K33  K34       K35  K36  K37

#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTPINKIE 2 3
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTINNERINDEX 3 4
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTINNERINDEX 7 8
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTPINKIE 8 9

#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTPINKIE 26 27
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTINNERINDEX 27 28
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTINNERINDEX 31 32
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTPINKIE 32 33

#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 37 38
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 39 40

#define MIRYOKU_TIMERLESS_THUMBS 36 37 38 39 40 41
#define MIRYOKU_TIMERLESS_LEFT  1 2 3 4  5    13 14 15 16 17   25 26 27 28 29
#define MIRYOKU_TIMERLESS_RIGHT 6 7 8 9 10    18 19 20 21 22   30 31 32 33 34

#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_CORNE
