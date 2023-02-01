#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include "escreve_no_arquivo.h"
#include "ler_o_arquivo.h"
#include <string>
#include <stdio.h>


using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    // Carrega o arquivo de imagem
    Mat frame = imread(argv[1]);
    Mat save_image;
    char placa[10];
    if (frame.empty())
    {
        cout << "Não foi possível carregar a imagem" << endl;
        return -1;
    }

    // Carrega o classificador de cascata para detectar placas de carro
    CascadeClassifier car_cascade("../cascade_files/car_cascade.xml");
    if (car_cascade.empty())
    {
        cout << "Não foi possível carregar o classificador de cascata" << endl;
        return -1;
    }

    // Convert imagem para escala de cinza
    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);
    equalizeHist(gray, gray);

    // Detecta as placas de carro na imagem
    vector<Rect> cars;
    car_cascade.detectMultiScale(gray, cars);

    // Desenha retângulos em torno das placas detectadas
    for (size_t i = 0; i < cars.size(); i++)
    {
        cout << cars[i] << endl;
        rectangle(frame, cars[i], Scalar(0, 255, 255), 2);
        imwrite("../images_and_videos/images/test.jpg", frame); 
        // Corte o retângulo da imagem original
        Mat objects = frame(cars[i]);

        stringstream ss;
        ss << "../images_and_videos/images/placa_" << i << ".jpg";
        
        escrever("jhy4525");
        escrever("asf2563");
        imwrite(ss.str(), objects);
        ler_placas();
    }
    
    // Exibe a imagem com as placas detectadas
    imshow("JHY7532", frame);
    waitKey(0);
    return 0;
}
