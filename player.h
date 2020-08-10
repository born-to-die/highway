#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player {

private:
    int x, y;

public:

    Player(int x, int y, RENDER &Render) {
        this->x = x;
        this->y = y;
        Render.addSymbol(x, y, '@', White, Black);
    }

    void update(RENDER &Render, int dir) {
        Render.addSymbol(x, y, ' ', White, Black);
        switch(dir) {
            case 72: {
            	if(y != 0)
                	y--;
                break;
            }
            case 77: {
            	if(x != 11)
                	x++;
                break;
            }
            case 75: {
            	if(x != 0)
                	x--;
                break;
            }
            case 80: {
            	if(y != 12)
                	y++;
                break;
            }
        }
        Render.addSymbol(x, y, '@', White, Black);
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

#endif // PLAYER_H_INCLUDED
