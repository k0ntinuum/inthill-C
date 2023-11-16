int main(void) {
    start_raw_mode();
    hide_cursor();
    clear_screen();
    seed();
    plot();
    randomize_ants();
    for (;;) {
            
        move_ants();
        usleep(6300);


        respond();
    }
}