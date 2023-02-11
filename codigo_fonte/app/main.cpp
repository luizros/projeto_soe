#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include "interface.h"
#include "escreve_no_arquivo.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include "processa_imagem.h"

using namespace std;
using namespace cv;

void cria_dialogo(int argumentosqt, char** valores){
    dialogo(argumentosqt, valores);
}
int cria_detector(){
    
    // Abra a webcam
    VideoCapture cap(0);

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
        cout << "Erro ao carregar arquivo xml" << endl;
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
            Mat placa = frame(placas[i]);
            //rectangle(frame, placas[i], Scalar(0, 255, 0), 2, 8, 0);
            string placa_detectada = "placa_" + to_string(i) + ".jpg";
            string pastaArquivo = "../images_and_videos/" + placa_detectada;
            imwrite(pastaArquivo, placa);
            
        }

        // Exiba o quadro com as placas detectadas
        imshow("Placa de Veiculo", frame);

        // Interrompa o loop se a tecla 'ESC' for pressionada
        int key = cv::waitKey(1); // Aguardando uma tecla ser pressionada
        if (key == 27) { // Verificando se a tecla pressionada foi a tecla 'ESC' (código 27)
      break; // Saindo do loop
        }
    }
    // Feche a webcam e a janela
    escrever("jhy3545", 1);
    escrever("jhy7532", 0);
    cap.release();
    destroyAllWindows();
}


int main(int argc, char** argv)
{
    // rodando os processos em paralelo
    int flag;
    pid_t pid;
    pid = fork();
    if (pid == 0){
        cria_dialogo(argc, argv);
    }else{
        cria_detector();

    }
    return 0;
}