## Modelo en C++ 

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
1. Asegurarse de tener instalada la librería de Eigen. Además de tener BOOST y CMAKE. Si no posee alguna de las anteriores
   utilice los siguientes comandos según sea necesario.
* Eigen:
```     
sudo apt install libeigen3-dev
sudo apt update
```
enlace simbolico a la biblioteca Eigen:
```
ln -sf  /usr/include/eigen3/Eigen Eigen
ln -sf  /usr/include/eigen3/unsupported unsupported
sudo apt update
```
* CMAKE:
```
sudo apt install cmake
sudo apt update
```
* BOOST:
```
sudo apt-get install libboost-all-dev
sudo apt update
```
enlace simbolico a la biblioteca boost:
```  
ln -sf /usr/include/boost boost
sudo apt update
```

2. Una vez descargada la carpeta  **LinearRegression - WineQuality**, ubique dónde está ubicada y ábrala. 
   Con **LinearRegression - WineQuality** abierta abra una terminal en dicha carpeta. 
    - Clic derecho dentro de la carpeta, posteriormente **Abrir en una terminal**
   ![image](![image](https://user-images.githubusercontent.com/110064371/203450814-62bcc315-b4d7-493a-89d5-8037fffe1971.png))
   
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
