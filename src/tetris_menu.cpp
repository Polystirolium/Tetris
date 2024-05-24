#include "tetris_menu.h"

void DrawIntroImg(int posX, int posY, int fontSize, Color color)
{
    DrawText("B############BPBB#######BBB###BPG#####&&&&&&&&&BG##&&&&&&&#&&&&&&##?Y&&&&&&&&&&&&&###&&G!#&&&&&#PYP?", posX, posY, fontSize, color);
    DrawText("##############BB#######BPYB###B5G#####&&&&&&&&#P5#&&&&&&&&B#&&&&&&&Y5&&&&&&&&&&&&#BY#&&B!&&&&&&G5YJJ", posX, posY + fontSize, fontSize, color);
    DrawText("#########BBG5YJJJY5GBB##BB###########&&&&##&&&&&&&&&&&&&&&&&&#B#&&&J5&&&&&&&&&&&&&&&&&&G^#&#BGP55J?7", posX, posY + fontSize * 2, fontSize, color);
    DrawText("B##BBGBBP?^.       .~JPBB############&&&#5P#&&&&&&&&&&&&&&&&&#G#&&#!!&&&&&&&&&&&&&&&&&&J:B&&#P5Y5J~!", posX, posY + fontSize * 3, fontSize, color);
    DrawText("BBBBBGPJ:             :JGB#################&&&#B#&&&&&&&&&&&&&&#BB#:~&&&&&&&&&&&###&&&&J.B&&&BBGBP??", posX, posY + fontSize * 4, fontSize, color);
    DrawText("BBBBBGJ.               :YGBB###########GP#&&&&#####B#&&&&&&&&&&#5P#57#&&&&&&&&&#GY#&&&BJ^G&&##B7YBJJ", posX, posY + fontSize * 5, fontSize, color);
    DrawText("BBBBBP7                 ?PBBBBB###################GYB###########&#GY??&&&&&&&&&&&&&&&G?7!^JB#BP557!7", posX, posY + fontSize * 6, fontSize, color);
    DrawText("BBBBBPJ.               :YGBBBBBBGYGB############################B57?7~J#&#PY##&&&&#P!^!:~:::YPYGY77?", posX, posY + fontSize * 7, fontSize, color);
    DrawText("BBBBBGPJ:             ^JPBBBBBBBG5GBB################BYYB######GJ~7?:J^?G#BB####PJ^.^7.^!.^~.^J55777", posX, posY + fontSize * 8, fontSize, color);
    DrawText("BGPPGBBGPJ~..     .:~JPGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGBB##BP?!!7^.!5^:J7P###G!?:.?J. ?7. !7 .~^7YJ", posX, posY + fontSize * 9, fontSize, color);
    DrawText("GG5PGGGGGGGP5YJJ??5PGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGJ7?Y7:.~J5?. YJ^!BB^JP JYJ .5?: :Y^ ~~.!?", posX, posY + fontSize * 10, fontSize, color);
    DrawText("GGBGGGGGGGGGBBBBBBBBGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBGJ5BB!.~5PPJ..!P5~ JB^GG.5GP .BY~ ^G~ ~? 7J", posX, posY + fontSize * 11, fontSize, color);
    DrawText("GGGGGGGGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBGGBB5B&&J~Y#BBY^:7BGY::G&PY&J7&&~:&GJ.GG::5:~GP", posX, posY + fontSize * 12, fontSize, color);
    DrawText("GGGGBBGGGGGGGGGGGGGGGGGGGBBBBBBBBBBBBBBBBBBBBBBBBBBBBGGBBB&@GPB&&&5??P##5~^Y#@#GP#JPG5?PY?7Y7~57!YJ?", posX, posY + fontSize * 13, fontSize, color);
    DrawText("GPGGY5GGGGGGGGGYYGGGGGGGBBBBGYPGBBBBBBBBBBBBBBBBBBGBBBBBB#&@&@@@@&#&@@@#GB^#&#BB55Y?7???^::..:^~~PP7", posX, posY + fontSize * 14, fontSize, color);
   
}
