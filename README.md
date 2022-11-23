# Tercer Examen Parcial 
### Modelo regresión lineal - Predicción calidad del vino blanco

Buen día.

Este repositorio almacena dos implentaciones de un modelo regresión lineal.
El modelo utiliza los datos de muestras de vino blanco y sus características, 
registrados en "winequality-white" para realizar una predicción
sobre su calidad. Las implementaciones se realizaron en C++ y Python, para las 
cuales a continuación se detalla cómo están organizadas para su visualización y
ejecucción. 🤔

### Modelo en C++

🗃️​ Contenidos: 

    📂​ LinearRegression - WineQuality: 
        Carpeta principal. Almacena las carpetas con las clases que describen 
        las funciones para el funcionamiento del modelo. Un archivo csv que 
        contiene todos los datos registrados de las muestras de vino. Y por 
        último el archivo main.cpp, que sirve como clase principal para realizar
        la ejecución del modelo.
    
    📂​ ClassExtraction: 
        * extractiondata.cpp -> define todas las funciones para la manipulación del fichero csv como matriz de Eigen.
        * extractiondata.h -> header que define la clase extracción de datos para leer el fichero csv. 
    📂​ Regression: 
        * linearregresion.cpp -> define el funcionamiento de las funciones de la clase de regresión lineal, utilizando los datos del dataset.
        * linearregresion.h -> header que define la clase regresión lineal donde establece la función de costo y la métrica de rendimiento. 
    📂​ main.cpp:
        * Clase principal que define las cómo serán ejecutadas las operaciones de las clases al momento de que el usuario pase como parámetros, 
        las entradas del modelo, es decir, el dataset y el tipo de separción de los datos en este (,).
    📂​ dataset.csv:
        * Archivo separado por comas que contiene los datos de caraterísticas de muestras de vino blanco.
      
       
💻​ Pasos de ejecucción:   
1. Asegurarse de tener instalada la librería de Eigen, puesto que se trata al dataset como una matriz es necesaria 
   esta librería para su manipulación. 
```     
sudo apt install libeigen3-dev
```       
2. Una vez descargada la carpeta  **LinearRegression - WineQuality**, abra una terminal en dicha carpeta. 
    - Clic derecho dentro de la carpeta, posteriormente **Abrir en una terminal**
   ![image](https://user-images.githubusercontent.com/110064371/203443960-b5e109d0-05a7-4411-8fb8-f94b9e04b020.png)
   
3. En la terminal proceda a ejecutar el siguente comando:
```
g++ -std=c++11 Regression/linearregresion.cpp ClassExtraction/extractiondata.cpp main.cpp -o output
```
4. Se tuvo que crear un archivo llamado output que puede ser ejecutado por la orden **./**, para que la implementación
   utilice el dataset hay que pasarlo como parámetro junto al separador como sigue:
```
./output dataset.csv ","
```
5. Finalización, depués de ejcutar el anterior comando las métricas R2 score de entrenamiento y prueba se mostrarán en 
   pantalla.

   
   

        
        
       

        
        
       
    



