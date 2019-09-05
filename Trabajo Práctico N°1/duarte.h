float sumar(float a, float b);

/** \brief  Funcion para sumar numeros
 *
 * \param   Sumo los operadores
 * \param
 * \return  Devuelvo el resultado de la suma
 *
 */

float restar(float a, float b);

/** \brief  Funcion para restar numeros
 *
 * \param   Resto los operadores
 * \param
 * \return  Devuelvo el resultado de la resta
 *
 */

float dividir(float a, float b);

/** \brief  Funcion para dividir numeros
 * \param   Me aseguro de que el divisor no sea 0
 * \param   Si el divisor es 0, devuelve -1 y se muestra el mensaje de error
 * \param   Divido los operadores
 * \return  Devuelvo el resultado de la division
 *
 */

float multiplicar(float a, float b);

/** \brief  Funcion para multiplicar numeros
 *
 * \param   Multiplico los operadores
 * \param
 * \return  Devuelvo el resultado de la multiplicacion
 *
 */

int factorial(int a);

/** \brief  Funcion para sacar el factorial de numeros
 *
 * \param   Me aseguro de que el operador sea mayor a 0
 * \param   Si el operador es negativo, devuelvo -1 y muestro el mensaje de error
 * \param   Saco el factorial del numero
 * \return  Devuelvo el factorial del operador
 *
 */

int menuOpciones(float* a, float* b);
/** \brief  Funcion para elegir las opciones
 *
 * \param   Recibo los 2 operadores para mostrarlos
 * \param   Pido la opcion al usuario
 * \return  Devuelvo el resultado de la funcion seleccionada
 *
 */

void todas(float a, float b);
/** \brief  Funcion para realizar todas las operaciones
 *
 * \param   Me aseguro de que se puedan realizar todas las operaciones con los operadores actuales
 * \param   Si no puedo realizar alguna muestro el respectivo mensaje de error
 * \param   Realizo todas las operaciones con mis funciones
 * \return  Devuelvo el resultado de todas las operaciones que se completaron
 *
 */

