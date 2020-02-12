// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class SnakesLadders {
	private:
		int playerPos[2];
		int current_player;
		bool game_on;
	public:
		SnakesLadders() {
			playerPos[0] = 0;
			playerPos[1] = 0;
			current_player = 0;
			game_on = true;
		}
		int escalarOResbalar(int posicion) {
			int nueva_posicion = posicion;
			switch (posicion) {
				case 2: nueva_posicion=38; break;
				case 7: nueva_posicion=14; break;
				case 8: nueva_posicion=31; break;
			}
			return nueva_posicion;
		}
		string play(int die1, int die2) {
			if (game_on==false) {
				return "Game over!";
			}
			string mensaje = "Player " + to_string(current_player + 1);
			playerPos[current_player] += die1 + die2;
			if (playerPos[current_player] > 100) {
				playerPos[current_player] = 200 - playerPos[current_player];
			}
			playerPos[current_player] = escalarOResbalar(playerPos[current_player]);
			if (playerPos[current_player]==100) {
				mensaje += " Wins!";
				game_on = false;
				return mensaje;
			}
			mensaje += " is on square " + to_string(playerPos[current_player]);
			if (die1 != die2) {
				current_player = (current_player == 0) ? 1: 0;
			}
			return mensaje;
		}
};


int main(void)
{
	SnakesLadders game = SnakesLadders();
	cout << game.play(51,50) << endl;
	cout << game.play(1,5) << endl;
	cout << game.play(1,6) << endl;
	return 0;
}
