#include "extractiondata.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>
#include <list>
#include <vector>
#include <fstream>

/*Primera función miembro:
 * Lectura del fichero csv.
 * Se almacena en un vector de vectores del tipo string*/

std::vector<std::vector<std::string>> ExtractionData::LeerCSV()
{
    /* En primer lugar se abre y almacena el ficehero en un buffer temporal "archivo" */
    std::fstream archivo(dataset);
    /* Se crea un vector de vectores del tipo string*/
    std::vector<std::vector<std::string>> datosString;

    /* Idea: Recorrer cada linea del fichero y enviarla como vector al vector de vectores del tipo string*/
    std::string linea = "";
    while(getline(archivo,linea)){
        std::vector<std::string> vector;
        /*Se identifica cada elemento que compone el vector*/
        //Se divide o segmenta cada elemento con boost
        boost::algorithm::split(vector,linea,boost::is_any_of(delimitador));
        /*Finalmente se ingresa al buffer temporal*/
        datosString.push_back(vector);
    }
    /* Se cierra el fichero csv */
    archivo.close();
    /* Se retorna el vector de vectores*/
    return datosString;
}

/* Segunda función miembro:
 * Pasar el vector de vectores del tipo string a un objeto del tipo Eigen: para las correspondientes operaciones*/
Eigen::MatrixXd ExtractionData::CSVtoEigen(
        std::vector<std::vector<std::string>> dataSet,
        int filas,
        int columnas){
    /* Se revisa si tiene o no cabecera*/
    if(header==true){
        filas = filas - 1;
    }
    Eigen::MatrixXd matriz(columnas, filas);
    //Se llena la matriz con los datos del dataSet
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
           //Se pasa a flotante el tipo string
            matriz(j,i) = atof(dataSet[i][j].c_str());
        }
    }
    //Se retorna la matriz traspuesta
    return matriz.transpose();
}


/* Función para extraer el promedio
* Cuando el programador no esta seguro de que tipo de dato debe retornar la función,
* se usa auto *nombre_función* decltype*/
auto ExtractionData::Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean()){
    return datos.colwise().mean();
}

/* Función para calcular la desviación estándar*/

auto ExtractionData::DevStand(Eigen::MatrixXd datos) -> decltype(((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt()){
    return ((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt();
}

/* Función para normalizar los datos
Se retorna la matriz de datos normalizada. La función recibe como argumentos la matriz*/
Eigen::MatrixXd ExtractionData::Norm(Eigen::MatrixXd datos) {

    /* Se escalan los datos:
     *  Xi - mean */
    Eigen::MatrixXd mat_escalado = datos.rowwise() - Promedio(datos);
    // Se calcula la normalización
    Eigen::MatrixXd mat_normal = mat_escalado.array().rowwise() / DevStand(mat_escalado);
    return mat_normal;
}

/* Función para dividir en cuatro grandes grupos:
 * x_train, y_train, x_test, y_test */
std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> ExtractionData::TrainTestSplit(Eigen::MatrixXd datos, float size_train){
   // Cantidad de filas totales
    int filas_totales = datos.rows();
    // Cantidad de filas para entrenamiento
    int filas_train = round(filas_totales * size_train);
    // Cantidad de filas para prueba
    int filas_test = round(filas_totales - filas_train);
    Eigen::MatrixXd Train = datos.topRows(filas_train);
    // Se desprenden para independientes y dependientes
    Eigen::MatrixXd X_train = Train.leftCols(datos.cols()-1);
    Eigen::MatrixXd Y_train = Train.rightCols(1);

    Eigen::MatrixXd Test = datos.bottomRows(filas_test);
    Eigen::MatrixXd X_test = Test.leftCols(datos.cols()-1);
    Eigen::MatrixXd Y_test = Test.rightCols(1);
    // Se compacta la tupla y se retorna
    return std::make_tuple(X_train, Y_train, X_test, Y_test);
}

/* Para efectos de visualización se creará la función vector a fichero*/
void ExtractionData::VectorToFile(std::vector<float> vector, std::string file_name){
    std::ofstream file_salida(file_name);
    //Se crea un iterador para almacenar la salida del vector
    std::ostream_iterator<float> salida_iterador(file_salida, "\n");
    // Se copia cada valor desde el inicio hasta el fin del iterador en el fichero
    std::copy(vector.begin(), vector.end(), salida_iterador);
}

//Para efectos de manipulación y visualización se la función matriz Eigen a fichero
void ExtractionData::EigenToFile(Eigen::MatrixXd matriz, std::string file_name){
    std::ofstream file_salida(file_name);
    if (file_salida.is_open()){
        file_salida << matriz << "\n";
    }
}




















































