#include <nds.h>
#include <stdio.h>

// Functie om de speler te tekenen
void drawPlayer(int x, int y) {
    // Dit is slechts een voorbeeld voor het tekenen van een blokje als speler
    // Je zou hier de eigenlijke sprite rendering code moeten implementeren.
    iprintf("Player at (%d, %d)\n", x, y);
}

int main(void) {
    // Zet de console om tekst te tonen op het bovenste scherm
    consoleDemoInit();

    // Initialiseer de knoppen en de grafische mode voor de DS
    consoleClear();

    // Variabelen voor de speler
    int playerX = 50, playerY = 50;
    
    while (1) {
        // Lees de knopstatus
        scanKeys();
        int keys = keysDown();

        // Verplaats de speler op basis van de knopdruk
        if (keys & KEY_UP) {
            playerY--;
        }
        if (keys & KEY_DOWN) {
            playerY++;
        }
        if (keys & KEY_LEFT) {
            playerX--;
        }
        if (keys & KEY_RIGHT) {
            playerX++;
        }

        // Wis het scherm
        consoleClear();

        // Teken de speler
        drawPlayer(playerX, playerY);

        // Maak een schermupdate
        swiWaitForVBlank();
    }
}
