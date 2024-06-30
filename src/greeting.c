#include "printf.h"

char * greeting_str =    
"$$\\     $$\\                                   $$$$$$$\\  $$\\                                \n"
"\\$$\\   $$  |                                  $$  __$$\\ \\__|                               \n"
" \\$$\\ $$  /$$$$$$\\   $$$$$$\\   $$$$$$$\\       $$ |  $$ |$$\\  $$$$$$$\\  $$$$$$$\\ $$\\    $$\\ \n"
"  \\$$$$  / \\____$$\\ $$  __$$\\ $$  _____|      $$$$$$$  |$$ |$$  _____|$$  _____|\\$$\\  $$  |\n"
"   \\$$  /  $$$$$$$ |$$ |  \\__|$$ /            $$  __$$< $$ |\\$$$$$$\\  $$ /       \\$$\\$$  / \n"
"    $$ |  $$  __$$ |$$ |      $$ |            $$ |  $$ |$$ | \\____$$\\ $$ |        \\$$$  /  \n"
"    $$ |  \\$$$$$$$ |$$ |      \\$$$$$$$\\       $$ |  $$ |$$ |$$$$$$$  |\\$$$$$$$\\    \\$  /   \n"
"    \\__|   \\_______|\\__|       \\_______|      \\__|  \\__|\\__|\\_______/  \\_______|    \\_/\n";

void print_greeting() {
    
    printf(greeting_str);   
    printf("\n\n\nReady to receive program via UART...\n");
}