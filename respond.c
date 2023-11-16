

char getch() {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
    return c;
}
void flash() {
    clear_screen();
    plot();
}

void respond() {
    int c = getch();
    switch (c) {
        case 'q': stop_raw_mode();exit(0);break;
        case '=': cols++; if (cols >= max_cols) cols = 1;flash();break;
        case '+': cols--; if (cols < 0 ) cols = max_cols - 1;flash();break;
        case '-': rows++; if (rows >= max_rows) rows = 1;flash();break;
        case '_': rows--; if (rows < 0 ) rows = max_rows - 1;flash();break;
        case 's': randomize_swarm();break;
        case 'r': randomize_ants();break;
    }
}