#include <psp2/kernel/processmgr.h>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include "debugScreen.h"

enum ColorNames {black, red, green, yellow, blue, magenta, cyan, white};

class DebugScreen {
public:
    std::map<ColorNames, unsigned short> Colors;

    DebugScreen(uint32_t bgColor=0xFF000000) {
        colorBg = defaultBg = bgColor;

        this->Colors[black] = 30;
        this->Colors[red] = 31;
        this->Colors[green] = 32;
        this->Colors[yellow] = 33;
        this->Colors[blue] = 34;
        this->Colors[magenta] = 35;
        this->Colors[cyan] = 36;
        this->Colors[white] = 97;

        psvDebugScreenInit();
        this->clear(bgColor);
    }

    void printf(const std::string& msg, ColorNames fgColor = white) {
        psvDebugScreenPrintf("\e[%um" "%s\n", this->Colors[fgColor], msg.c_str());
    }

    void clear(uint32_t bgColor=0xFF000000) {
        colorBg = defaultBg = bgColor;
        this->printf("\e[2J"); // clear the screen
        this->printf("\e[1J"); // move cursor to home
    }

    void setFontSizes(unsigned char fontWidth,
                 unsigned char fontHeight,
                 unsigned char fontSizeW,
                 unsigned char fontSizeH
                 ){
        psvDebugScreenFont.width = fontWidth;
        psvDebugScreenFont.height = fontHeight;
        psvDebugScreenFont.size_w = fontSizeW;
        psvDebugScreenFont.size_h = fontSizeH;
    }
};


int main(int argc, char *argv[]) {
    auto ds = new DebugScreen(0x444444);
    ds->printf("TEST1 :D");
    ds->printf("RED ", red);
    ds->printf("CYAN", cyan);
    ds->printf("YYYY", yellow);

    sceKernelDelayThread(20*1000*1000);
	sceKernelExitProcess(0);
    return 0;
}
