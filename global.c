const int max_rows = 50;
const int max_cols = 500;
const int max_rule = 16808;
const int max_ants = 200; 
int cell[max_rows][max_cols];
int rule[max_rule];
int ant_rule[max_ants][512];
int ant_row[max_ants];
int ant_col[max_ants];
int ant_r[max_ants];
int ant_g[max_ants];
int ant_b[max_ants];
int current_target= 0;
int ants = 25;
struct termios orig_termios;
int down = 5;
int right = 5;
int rows = 20;
int cols = 40;
int display_mode = 0;








