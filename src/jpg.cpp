#include <TJpg_Decoder.h>

#include<jpg.h>
#include<ST.h>
void show_weather(int code,int xpos,int ypos){
        
    switch(code)
    {
    case 0:
    case 2:{
            TJpgDec.drawJpg(xpos, ypos,Sunny, sizeof(Sunny));
           break;
    }
    case 1:
    case 3:{
            TJpgDec.drawJpg(xpos, ypos,Clear, sizeof(Clear));
            break;
    }
    case 4:{TJpgDec.drawJpg(xpos, ypos,Cloudy, sizeof(Cloudy));break;}
    case 5:
    case 6:{TJpgDec.drawJpg(xpos, ypos,Partly_Cloudy, sizeof(Partly_Cloudy));break;}
    case 7:
    case 8:{TJpgDec.drawJpg(xpos, ypos,Mostly_Cloudy, sizeof(Mostly_Cloudy));break;}
    case 9:{TJpgDec.drawJpg(xpos, ypos,Overcast, sizeof(Overcast));break;}
    case 10:{TJpgDec.drawJpg(xpos, ypos,Shower, sizeof(Shower));break;}
    case 11:{TJpgDec.drawJpg(xpos, ypos,Thundershower, sizeof(Thundershower));break;}
    case 12:{TJpgDec.drawJpg(xpos, ypos,Thundershower_with_Hail, sizeof(Thundershower_with_Hail));break;}
    case 13:{TJpgDec.drawJpg(xpos, ypos,Light_Rain, sizeof(Light_Rain));break;}
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:{TJpgDec.drawJpg(xpos, ypos,Light_Rain, sizeof(Light_Rain));break;}
    case 19:{TJpgDec.drawJpg(xpos, ypos,Ice_Rain, sizeof(Ice_Rain));break;}
    case 20:{TJpgDec.drawJpg(xpos, ypos,Sleet, sizeof(Sleet));break;}
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:{TJpgDec.drawJpg(xpos, ypos,Snow_Flurry, sizeof(Snow_Flurry));break;}
    case 26:
    case 27:
    case 28:
    case 29:{TJpgDec.drawJpg(xpos, ypos,Dust, sizeof(Dust));break;}
    case 30:{TJpgDec.drawJpg(xpos, ypos,Foggy, sizeof(Foggy));break;}
    case 31:{TJpgDec.drawJpg(xpos, ypos,Haze, sizeof(Haze));break;}
    case 32:
    case 33:{TJpgDec.drawJpg(xpos, ypos,Windy, sizeof(Windy));break;}
    case 34:
    case 35:
    case 36:
    case 37:{TJpgDec.drawJpg(xpos, ypos,Cold, sizeof(Cold));break;}
    case 38:{TJpgDec.drawJpg(xpos, ypos,Hot, sizeof(Hot));break;}
    case 99:{TJpgDec.drawJpg(xpos, ypos,Unknown, sizeof(Unknown));break;}
    case 100:{TJpgDec.drawJpg(xpos, ypos,ShiDU, sizeof(ShiDU));break;}
    case 101:{TJpgDec.drawJpg(xpos, ypos,WenDU, sizeof(WenDU));break;}
    case 102:{TJpgDec.drawJpg(xpos, ypos,bottom, sizeof(bottom));break;}



    }
    
//         
  
}


