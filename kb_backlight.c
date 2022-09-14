#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    fp = fopen("/sys/class/leds/smc::kbd_backlight/brightness", "r+");
    char buff[4];
    fgets(buff, 4, (FILE*)fp);

    int v = atoi(buff);

    if (argv[1][0] == '-') {
        if (v > 25) {   
            fprintf(fp, "%i", v - 25);
        } else {fprintf(fp, "%i", 0);}
    } else if (argv[1][0] == '+') {
        fprintf(fp, "%i", v + 25);
    }     
    
    fclose(fp);
    return 0;
} 
