# TC1030-HBuild
Este proyecto es un manejador de builds para el juego de computadora Hades. El usuario puede crear una build de como va a manejar su personaje durante el juego, seleccionando que clase de mejoras va a agregar, y que equipamento va a utilizar en su "run". Dependiendo el tipo de habilidad, el programa le pedira su posicion en las ranuras, que prerequisitos necesita para ser equipada o la duracion del efecto. El arma y sus aspectos se pueden guardar, pero para mantener las clases reducidas y la tarea sencilla, el usuario no puede agregar los martillos. 

## Funcionalidad
El programa solo permite agregar nuevas habilidades a la build. Inicia el programa creando una nueva build, y despues sera un menu con ocpiones. Se puede agregar habilidades a esta build, mostrar las habilidades de una Build, crear una nueva Build, y cambiar la Build en la que se trabaja. Corre en la consola. Al momento de agregar texto, usar espacios puede romper el codigo, entonces se necesita usar _ para remarcar espacios. De igual forma, cuando se pide un numero, en caso de responder con algun otro simbolo o string que no sea un int, el programa se rompe. 

## Consideraciones
Este programa solo corre en consola y esta hecho en c++. Para compilar el programa, utilice "g++ main.cpp". Despues, para correr el programa utilice "a.exe" en el caso de Windows. 
