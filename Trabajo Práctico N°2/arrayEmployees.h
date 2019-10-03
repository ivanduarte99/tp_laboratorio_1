#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Menu de opciones de las cuales el usuario selecciona una
 *         Si el Usuario selecciona una opcion que no se encuentra en el menu da un mensaje de error
 *         Si se eligen las opciones 2 y 3 antes de tener registrado al menos 1 empleado da un mensaje de error
 * \return Retorna la opcion seleccionada
 */
int menu();

/** \brief Menu de opciones para modificar un empleado
 *         El usuario selecciona una de ellas, y si elige una invalida da un mensaje de error
 * \return Retorna la opcion seleccionada
 */
int modifyMenu(Employee employees[], int len, int id);

/** \brief Menu de opciones para modificar datos de un empleado
 *         El usuario selecciona el dato que desea modificar e ingresa el nuevo valor
 *         Lo verifica y pregunta al usuario si desea realizar el cambio
 *         Le asigna el nuevo valor del dato que el usuario quiso cambiar al empleado
 */
void modifyMenuCases(Employee employess[], int tam, int id);

/** \brief Funcion que recibe todos los valores verificados de un empleado nuevo
 *         Y se los asigna
 * \param
 * \param
 * \return Retorna un newEmployee
 *
 */
Employee addEmployee(int id, char name[],char lastName[],float salary,int sector);

/** \brief Funcion que dice si todas las posicionesd de un array
 *         Le cambia el valor a isEmpty a true
 * \return Retorna -1 ssi hubo un error y un 0 si no lo hubo
 *
 */
int initEmployees(Employee employees[], int len);

/** \brief Añade un nuevo empleado, preguntando y verificando los datos que se le dan
* \param
 * \param
 * \return Retorna 1 si se pudo cargar y un 0 si hubo un error
 *
 */
int newEmployee(Employee employees[], int len, int id);

/** \brief  Encuentra un empleado por su ID
 *
 * \param
 * \param
 * \return Retorna el indice del empleado o un -1 si recibio un puntero invalido
 *
 */
int findEmployeeById(Employee employees[], int len, int id);

/** \brief Verifica si es posible añadir mas empleados
 *
 * \param
 * \param
 * \return Retorna -1 si no se pueden añadir mas o el indice del espacio vacio que encontro
 *
 */
int searchEmpty(Employee employees[], int len);

/** \brief Da de baja un empleado por su ID
 *         Cambia el estado del isEmpty a 1
 * \param
 * \param
 * \return Retorna -1 si hubo un error y un 0 si no hubo problemas
 *
 */
int removeEmployee(Employee employees[], int len, int id);

/** \brief  Ordena todos los empleados por sector y apellido
 *
 * \param
 * \param
 * \return Retorna -1 si hubo un error y un 0 si no hubo problemas
 *
 */
int sortEmployees(Employee employees[], int len);

/** \brief Averigua si existen empleados activos en el sistema
 *
 * \param
 * \param
 * \return Retorna 1 si hay y 0 si no hay ninguno
 *
 */
int checkEmployee(Employee employees[], int len);

/** \brief  Muestra los datos de 1 empleado
 *
 * \param
 * \param
 * \return  Retorna un empleado en especifico
 *
 */
void printEmployee(Employee employeeX);

/** \brief Muestra a todos los empleados que estan activos (isEmpty 1= 0)
 *
 * \param
 * \param
 * \return  Retorna todos los empleados activos del sistema, o un mensaje de error
 *
 */
void printEmployees(Employee employees[], int len);

/** \brief Pregunta por el ID y llama a removeEmployee
 *
 * \param
 * \param
 * \return Retorna -1 si tuvo un error, y un 0 si no tuvo ninguno
 *
 */
void removingEmployee(Employee employees[], int len);

/** \brief Pregunta por un ID y llama a modifyMenuOptions
 *
 * \param
 * \param
 * \return Retorna al empleado modificado o un mensaje de que se cancelo la operacion
 *
 */
void modifyEmployee(Employee employees[], int len);

/** \brief Saca el total de todos los salarios activos, el promedio y la cantidad de empleados que lo superaron
 *
 * \param
 * \param
 * \return Retorna todo lo mencionado
 *
 */
void sortEmployeesProm(Employee employees[], int len);

/** \brief Muestra un menu donde el usuario selecciona el reporte que quiere ver
 *         La funcion llama a sortEmployees y sortEmployeesProm en sus debidos casos
 * \param
 * \param
 * \return Retorna el reporte seleccionado
 *
 */
void reportEmployees(Employee employees[], int len);
