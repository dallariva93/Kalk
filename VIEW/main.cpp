#include<QApplication>
#include"colorslider.h"

int main(int argc, char* argv[])
{
    QApplication colorbox(argc,argv);
    ColorSlider col;
    col.show();
    return colorbox.exec();
}
