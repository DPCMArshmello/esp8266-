#include <TJpg_Decoder.h>
#include<jpg.h>
#include"dog.h"
void gif_d(int code,int xpos,int ypos){
     switch(code)
    {
    case 0:{TJpgDec.drawJpg(xpos, ypos,d1, sizeof(d1));break;}
    case 2:{TJpgDec.drawJpg(xpos, ypos,d2, sizeof(d2));break;}
    case 1:{TJpgDec.drawJpg(xpos, ypos,d3, sizeof(d3));break;}
    case 3:{TJpgDec.drawJpg(xpos, ypos,d4, sizeof(d4));break;}
    case 4:{TJpgDec.drawJpg(xpos, ypos,d5, sizeof(d5));break;}
    case 5:{TJpgDec.drawJpg(xpos, ypos,d6, sizeof(d6));break;}
    case 6:{TJpgDec.drawJpg(xpos, ypos,d7, sizeof(d7));break;}
    case 7:{TJpgDec.drawJpg(xpos, ypos,d8, sizeof(d8));break;}
    case 8:{TJpgDec.drawJpg(xpos, ypos,d9, sizeof(d9));break;}
    case 9:{TJpgDec.drawJpg(xpos, ypos,d10, sizeof(d10));break;}
    case 10:{TJpgDec.drawJpg(xpos, ypos,d11, sizeof(d11));break;}
    case 11:{TJpgDec.drawJpg(xpos, ypos,d12, sizeof(d12));break;}
    case 12:{TJpgDec.drawJpg(xpos, ypos,d13, sizeof(d13));break;}
    case 13:{TJpgDec.drawJpg(xpos, ypos,d14, sizeof(d14));break;}
    case 14:{TJpgDec.drawJpg(xpos, ypos,wifi, sizeof(wifi));break;}
     
    }
}
      