#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char **argv)
{
    if(argc < 2){
        printf("Imagem nao encontrada\n");
        return -1;
    }
    Mat image;
    image = imread(argv[1]);
    if(!image.data){
        printf("Imagem nao encontrada\n");
    }
    namedWindow(argv[1], WINDOW_AUTOSIZE);
    imshow(argv[1], image);
    waitKey(0);
    return 0;
}