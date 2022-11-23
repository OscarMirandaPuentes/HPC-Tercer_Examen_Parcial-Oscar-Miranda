#include "linearregresion.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include <cmath>

/*Primer Función: Función de costo para la regresión lineal
 * Basada en los mínimos cuadrados ordinarios demostrado en clase*/

float LinearRegression::F_OLS_Costo(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta)
{
    Eigen::MatrixXd m_interior = pow((X*theta - y).array(),2);
    return (m_interior/(2*X.rows())).sum();
}

/*Función de gradiente descendiente: En función de un ratio de
 * aprendizaje se avanza hasta encontrar el punto mínimo que representa
 * el valor óptimo para la función*/

std::tuple<Eigen::VectorXd, std::vector<float>> LinearRegression::GD(Eigen::MatrixXd X,
                                                                     Eigen::MatrixXd y,
                                                                     Eigen::VectorXd theta,
                                                                     float alpha,
                                                                     int num_iter)
{
    Eigen::MatrixXd temporal = theta;
    int parametros = theta.rows();
    std::vector<float> costo;
    // En costo ingresaremos los valores de la función de costo
    costo.push_back(F_OLS_Costo(X, y, theta));
    //Se itera según el número de iteraciones y el ratio de aprendizaje
    // para encontrar los valores óptimos
    for (int i = 0; i < num_iter; ++i) {
        Eigen::MatrixXd error = X*theta - y;
        for (int j = 0; j < parametros; ++j) {
            Eigen::MatrixXd X_i = X.col(j);
            Eigen::MatrixXd termino = error.cwiseProduct(X_i);
            temporal(j,0)= theta(j,0) -  (alpha/X.rows())*termino.sum();
        }
        theta = temporal;
        // En costo ingresaremos los valores de la función de costo
        costo.push_back(F_OLS_Costo(X, y, theta));
    }
    return std::make_tuple(theta,costo);
}

/* A continuación se presenta la función para revisar que tan bueno es nuestro modelo:
 * Se procede a crear la métrica de rendimiento:
 *  - R² score: Coeficiente de determinación, en donde el mejor valor posible es 1*/
float LinearRegression::R2_score(Eigen::MatrixXd y, Eigen::MatrixXd y_hat){
    auto numerador = (pow((y - y_hat).array(),2)).sum();
    auto denominador = (pow((y.array() - y.mean()),2)).sum();
    return (1 - (numerador/denominador));
}































