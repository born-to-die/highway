#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "colors.h"
#include "render.h"
#include "car.h"
#include "player.h"

int main() {

    RENDER Render(true);
    Render.setCursor(false);
    Render.clear();
    Car car[10];
    Player player(5, 12, Render);
    bool game_active = true;

    Render.drawHLine(13, 0, 13, '-', White, Black);
    Render.drawVLine(0, 12, 13, '|', White, Black);

    srand(time(0));

    for(int i = 0; i < 10; i++) {
        int pos = rand() % 12;
        car[i].set(11, i + 1, pos, i + 1, 3, 12, i + 1, Render, 11 - pos);
    }
    /*
        car[0].set(11, 1, 9, 1, 3, 12, 1, Render, 2);
        car[1].set(11, 2, 11, 2, 3, 12, 2, Render, 0);
        car[2].set(11, 3, 11, 3, 3, 12, 3, Render, 0);
        car[3].set(11, 4, 11, 4, 3, 12, 4, Render, 0);
        car[4].set(11, 5, 11, 5, 3, 12, 5, Render, 0);
        car[5].set(11, 6, 11, 6, 3, 12, 6, Render, 0);
        car[6].set(11, 7, 11, 7, 3, 12, 7, Render, 0);
        car[7].set(11, 8, 11, 8, 3, 12, 8, Render, 0);
        car[8].set(11, 9, 11, 9, 3, 12, 9, Render, 0);
        car[9].set(11, 10, 11, 10, 3, 12, 10, Render, 0);
    */

    Render.draw();

    while(game_active) {
        while(!kbhit()) {
            for(int i = 0; i < 10; i++)
                car[i].update(Render, player);
            Render.draw();
            Sleep(50);
        }

        player.update(Render, getch());
        Render.draw();
    }
    
	return 0;
}
