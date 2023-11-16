void clear_screen() {
    write(STDOUT_FILENO, "\x1b[2J", 4);
}
void cursor_to(int r, int c) {
    printf("\x1b[%d;%dH",r+1,c+1);
}
void hide_cursor() {
    printf("\x1b[?25l");
}
void set_color(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void start_reverse_text() {
    printf("\x1b[7m");
}
void stop_reverse_text() {
    printf("\x1b[27m");
}