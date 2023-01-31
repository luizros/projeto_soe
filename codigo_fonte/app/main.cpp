#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include "escreve_no_arquivo.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    // Carrega o arquivo de imagem
    Mat frame = imread(argv[1]);
    Mat save_image;
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
    }
    escrever("jhy7532");
    // Exibe a imagem com as placas detectadas
    imshow("Placas de carro detectadas", frame);
    waitKey(0);
    return 0;
}
