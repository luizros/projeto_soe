#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int display_image(char imagem[100]){
    Mat frame = imread(imagem);
    if (frame.empty())
    {
        cout << "Não foi possível carregar a imagem" << endl;
        return -1;
    } 
    // Exibe a imagem com as placas detectadas
    imshow("Placas de carro detectadas", frame);
    waitKey(0);
    return 0;
}