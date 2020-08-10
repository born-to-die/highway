#include <iostream>
#include "render.h"
#include "colors.h"
#include "player.h"

#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

class Car {

private:
    int x,
        y,
        direction,
        way,
        current_way,
        start_x,
        start_y,
        step_turn,
        current_turn;

public:

    void set(int start_x, int start_y, int x, int y, int direction, int way, int step_turn, RENDER &Render, int current_turn) {
        this->x = x;
        this->y = y;
        this->direction = direction;
        this->way = way;
        this->step_turn = step_turn;
        this->start_x = start_x;
        this->start_y = start_y;
        this->current_way = current_turn;

        Render.addSymbol(x, y, '<', White, Black);

    }

    void update(RENDER &Render, Player player) {

        current_turn += 1;

        if(current_turn == step_turn) {

            current_way += 1;

            current_turn = 0;

            Render.addSymbol(x, y, ' ', White, Black);


            switch(direction) {
                case 0: {
                    if(current_way == way) {
                        y = start_y;
                        current_way = 0;
                    }
                    else {
                        y--;
                    }
                    break;
                }
                case 3: {
                    if(current_way == way) {
                        x = start_x;
                        current_way = 0;
                    }
                    else {
                        if((x - 1 == player.getX() || x == player.getX()) && y == player.getY()) {
                            std::cout << "YOU DEAD";
                            getch();
                        }
                        x--;
                    }
                    break;
                }
            }

            Render.addSymbol(x, y, '<', White, Black);

        }
    }

};

#endif // CAR_H_INCLUDED
