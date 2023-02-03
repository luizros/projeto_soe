#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include "escreve_no_arquivo.h"
#include "ler_o_arquivo.h"
#include <string>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    // Abra a webcam
    VideoCapture cap(-1);

    // Verifique se a webcam foi aberta com sucesso
    if (!cap.isOpened())
    {
        cout << "Erro ao abrir a webcam" << endl;
        return -1;
    }

    // Crie uma janela para exibir o vídeo
    namedWindow("Placa de Veiculo", WINDOW_NORMAL);

    // Crie um objeto de classificador de placa de veículo
    CascadeClassifier placa_cascade;
    string caminho_classificador = "../cascade_files/car_cascade.xml";

    // Carregue o classificador de placa
    if (!placa_cascade.load(caminho_classificador))
    {
        cout << "Erro ao carregar classificador de placa" << endl;
        return -1;
    }

    while (true)
    {
        // Capture o quadro atual da webcam
        Mat frame;
        cap >> frame;

        // Converte o quadro para escala de cinza
        Mat frame_gray;
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        // Equalize o histograma do quadro em escala de cinza
        equalizeHist(frame_gray, frame_gray);

        // Detecte as placas de veículo no quadro
        vector<Rect> placas;
        placa_cascade.detectMultiScale(frame_gray, placas, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // Desenhe retângulos ao redor das placas detectadas
        for (size_t i = 0; i < placas.size(); i++)
        {
            rectangle(frame, placas[i], Scalar(0, 0, 255), 2, 8, 0);
        }

        // Exiba o quadro com as placas detectadas
        imshow("Placa de Veiculo", frame);

        // Interrompa o loop se a tecla 'q' for pressionada
        if (waitKey(10) == 'q')
        {
            break;
        }
    }
    escrever("JHY7525");
    // Feche a webcam e a janela
    cap.release();
    destroyAllWindows();

    return 0;
}