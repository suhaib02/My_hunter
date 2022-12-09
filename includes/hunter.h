/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** hunter
*/

#ifndef HUNTER_H_
    #define HUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

typedef struct winback {
    sfWindow *wond;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfMusic *music;
} r_win;

typedef struct menu {
    sfTexture *menu_txt;
    sfSprite *menu_spr;
    sfSprite *let_spr;
    sfTexture *let_txt;
    sfVector2f let_pos;
    sfVector2f let_size;
    sfClock *let_clock;
    sfSprite *cat_menu_spr;
    sfTexture *cat_menu_txt;
    sfVector2f cat_menu_pos;
    sfVector2f cat_menu_size;
    sfClock *cat_menu_clock;
} r_menu;

typedef struct backg {
    sfTexture *city_tex;
    sfSprite *city_spr;
    sfClock *clock;
    sfVector2f position;

} r_backg;

typedef struct catpower {
    sfTexture *cat_tex;
    sfSprite *cat_spr;
    sfClock *clock;
    sfVector2f size;
    sfVector2f position;
    sfIntRect cat_rec;
    sfTexture *win_txt;
    sfSprite *win_spr;
    sfVector2f win_position;
    sfTexture *levelup_txt;
    sfSprite *levelup_spr;
    sfVector2f levelup_position;
} r_catpower;

typedef struct mouse {
    sfVector2i mouse_pos_i;
    sfVector2f mouse_pos;
    sfMouseButton mouse_button;
    sfSprite *mouse_spr;
    sfTexture *mouse_txt;
    sfVector2f fmouse;
} r_mouse;

typedef struct score {
    sfTexture *score_txt;
    sfSprite *score_spr;
    sfVector2f score_size;
    sfVector2f score_pos;
    sfIntRect score_rec;
} r_score;

typedef struct struct_box {
    r_win *win_r;
    r_backg *backg_r;
    r_catpower *cat_r;
    r_mouse *mouse_r;
    r_menu *menu_r;
    r_score *score_r;
} r_box;


void create_cat(r_catpower *cat);
int open_a_window(r_box *box);
void creat_background(r_backg *city);
void set_cat(r_catpower *cat);
void move_rect(sfIntRect *rect, int offset, int max_value);
int get_mouse(r_catpower *cat, r_win *wind, r_mouse *mouse, r_score *score);
void create_music(r_win *sing);
void clock_city(r_backg *city);
void create_score(r_score *score);
void create_bgmenu(r_menu *menu);
void tools(r_box *box);
void create_let_chase_the_cat(r_menu *menu);
void clock_let(r_menu *menu);
void create_cat_menu(r_menu *menu);
void clock_cat_menu(r_menu *menu);
void draw_game(r_box *box);
void draw_win(r_box *box);
void create_winner(r_catpower *cat);
int level_up(r_score *score, r_catpower *cat, r_win *wind);
void create_levelup(r_catpower *cat);
void loop_game(r_box *box);
void handle_window(r_win *wind);
void clock_cat(r_catpower *cat, r_score *score);

#endif /* !HUNTER_H_ */
