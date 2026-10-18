#include "app.h"

void app_preinit(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    SDL_SetHint(SDL_HINT_WEBOS_ACCESS_POLICY_KEYS_EXIT, "true");
    SDL_SetHint(SDL_HINT_WEBOS_CURSOR_SLEEP_TIME, "5000");
    /* webOS 3.x ships SDL 2.0.4, which knows these hints under their old names only.
     * Without them the platform keeps key events (including Back) for itself. */
    SDL_SetHint("SDL_WEBOS_ACCESS_POLICY_KEYS_EXIT", "true");
    SDL_SetHint("SDL_WEBOS_ACCESS_POLICY_KEYS_BACK", "true");
}

void app_ui_set_handle_nav_back(app_ui_t *ui, bool handle) {
    (void) ui;
    SDL_SetHint(SDL_HINT_WEBOS_ACCESS_POLICY_KEYS_BACK, handle ? "true" : "false");
}