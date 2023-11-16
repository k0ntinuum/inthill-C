void print_symbol(int s) {
	switch (s) {
		case 0: printf("O");break;
		case 1: printf("1");break;
		case 2: printf("2");break;
		case 3: printf("3");break;
		case 4: printf("4");break;
	}
}
void print_block(int code) {
	switch (code) {
        case 0 : set_color(30,30,30);break;
        case 1 : set_color(255,255,255);break;
		case 2 : set_color(255,0,0);break;
		case 3 : set_color(0,255,255);break;
		case 4 : set_color(0,255,0);break;
    }
	//printf("\u2588");
	printf("\u2592");
}
void seed() {
	for (int c = 0; c < cols; c++) for (int r = 0; r < rows; r++) cell[r][c] = rand()%2;
}
int f(int x, int b) {
	int s = 1;
	for (int j = 0; j < x; j++) {
		s *= b;
	}
	return s;
}
int safe_col(int x) {
	if (x < 0) return x + cols;
	if (x > cols - 1) return x - cols;
	return x;
}
int safe_row(int x) {
	if (x < 0) return x + rows;
	if (x > rows - 1) return x - rows;
	return x;

}
int code(int r, int c) {
	int sum = 0;
	int counter = 0;
	for (int r_mod = -1; r_mod <= 1; r_mod++) {
		for (int c_mod = -1; c_mod <= 1; c_mod++) {
			sum += f(counter,2)*cell[safe_row(r+r_mod)][safe_col(c+c_mod)];
			counter++;
		}

	}
	return sum;
}
void calc() {
}
void plot_pixel(int r, int c, int col) {
	print_block(cell[r][c]);
}
void plot_row(int r) {
	cursor_to(r+down,0+right);
	for (int c = 0 ; c < cols; c++) {
		plot_pixel(r,c, cell[r][c]);
	}
}
void plot() {
	for (int r = rows -1; r > -1; r--) {
		//cursor_to(r,0);
		plot_row(r);
	}
	printf("\n");

}

void randomize_ants() {
	for (int a = 0; a < ants; a++) {
		for (int i =0 ; i < 512; i++) ant_rule[a][i] = rand()%8;
		ant_row[a] = rand()%rows;
		ant_col[a] = rand()%cols;
		ant_r[a] = rand()%256;
		ant_g[a] = rand()%256;
		ant_b[a] = rand()%256;


	}
}
void randomize_swarm() {
	int common_rule[512];
	for (int i =0 ; i < 512; i++) common_rule[i] = rand()%8;

	for (int a = 0; a < ants; a++) {
		for (int i =0 ; i < 512; i++) ant_rule[a][i] = common_rule[i];
		ant_row[a] = rand()%rows;
		ant_col[a] = rand()%cols;
		ant_r[a] = rand()%256;
		ant_g[a] = rand()%256;
		ant_b[a] = rand()%256;


	}

}
void move_ant(int a) {
	int c = ant_rule[a][code(ant_row[a], ant_col[a])];
	cell[ant_row[a]][ant_col[a]] = !cell[ant_row[a]][ant_col[a]];
	cursor_to(ant_row[a]+down,ant_col[a]+right);
	switch (cell[ant_row[a]][ant_col[a]]) {
		case 0 : set_color(0,0,0);break;
		case 1 : set_color(ant_r[a],ant_g[a],ant_b[a]);break;
	}
	//set_color(ant_r[a],ant_g[a],ant_b[a]);
	printf("\u2592");
	//print_block(cell[ant_row[a]][ant_col[a]]);
	switch (c) {
		case 0: ant_row[a] = safe_row(ant_row[a]-1);ant_col[a] = safe_col(ant_col[a]-1);break;
		case 1: ant_row[a] = safe_row(ant_row[a]-1);ant_col[a] = safe_col(ant_col[a]-0);break;
		case 2: ant_row[a] = safe_row(ant_row[a]-1);ant_col[a] = safe_col(ant_col[a]+1);break;
		case 3: ant_row[a] = safe_row(ant_row[a]-0);ant_col[a] = safe_col(ant_col[a]-1);break;
		case 4: ant_row[a] = safe_row(ant_row[a]-0);ant_col[a] = safe_col(ant_col[a]+1);break;
		case 5: ant_row[a] = safe_row(ant_row[a]+1);ant_col[a] = safe_col(ant_col[a]-1);break;
		case 6: ant_row[a] = safe_row(ant_row[a]+1);ant_col[a] = safe_col(ant_col[a]-0);break;
		case 7: ant_row[a] = safe_row(ant_row[a]+1);ant_col[a] = safe_col(ant_col[a]+1);break;
	}
	printf("\n");
	cursor_to(ant_row[a]+down,ant_col[a]+right);
	//set_color(100,100,100);
	//set_color(255,0,0);
	// set_color(ant_r[a],ant_g[a],ant_b[a]);
	// printf("@");
	//printf("\u2588");
	//start_reverse_text();
	//printf("%c",65+a);
	//stop_reverse_text();
	set_color(255,255,255);
	// printf("\n");

}

void move_ants() {
	for (int a = 0; a < ants; a++) {
		move_ant(a);
	}
}



