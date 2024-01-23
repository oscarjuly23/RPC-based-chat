# RPC-based Chat - Comunicación Primitiva y Estrategias

Este repositorio presenta un chat basado en RPC (Remote Procedure Call), que utiliza primitivas y estrategias de comunicación para facilitar la interacción entre usuarios. La aplicación permite a los usuarios enviar mensajes de forma remota utilizando llamadas a procedimientos en un entorno distribuido. A continuación, se proporciona información sobre RPCs y el uso de la biblioteca ncurses en el proyecto.

### Remote Procedure Calls ¿Que son?

Los RPCs son herramientas básicas para realizar llamadas a procedimientos remotos, siendo útiles en arquitecturas cliente-servidor para invocar funciones a través de la red. Facilitan la comunicación entre procesos en un sistema, permitiendo el intercambio de información entre ellos. Los RPCs implican el envío de parámetros y la recepción de valores en funciones remotas, lo que los hace esenciales para la comunicación entre programas distribuidos.

## Diseño del sistema:
1. Llamadas a Procedimientos Remotos: El código del cliente llama al procedimiento stub.
2. Serialización (Marshalling): El stub genera un mensaje para enviarlo mediante el protocolo RPC. Este proceso implica la serialización de datos. Comunicación con la Red: El stub se comunica directamente con el sistema de comunicación, que se configura para la comunicación en red.
3. eserialización (Demarshalling): El servidor recibe el mensaje y realiza un proceso de demarshalling para desempaquetar el mensaje basado en el protocolo RPC.
4. Procedimiento en el Servidor: El stub del servidor transfiere los parámetros decodificados y llama al procedimiento del servidor local.
5. Respuesta al Cliente: El valor resultante se comunica al stub del servidor.
Proceso Inverso: El resultado se envía de vuelta al cliente, completando el ciclo de comunicación.

## nCurses
La biblioteca ncurses proporciona una interfaz para sistemas basados en Unix, facilitando operaciones de entrada y salida en la consola. En este proyecto, se ha utilizado ncurses para construir una interfaz de chat en la consola del terminal Unix. Se han implementado dos ventanas: una para que los usuarios escriban, lean y envíen mensajes al servidor a través de llamadas RPC, y otra para mostrar el chat global de todos los clientes.

## Estructura
El proyecto incluye los siguientes archivos generados por RPCGEN:
- Makefile.basedChat: Archivo Makefile para compilar los archivos de código generados.
- BasedChat.h: Definición de los prototipos de funciones RPC.
- BasedChat_server.c: Esqueleto de funciones a ser programado en el servidor.
- basedChat_svc.c: Registro del servidor en el sistema Unix para atender solicitudes de clientes.
- basedChat_client.c: Código del cliente para establecer la conexión y realizar llamadas RPC.
- basedChat_clnt.c: Implementación de llamadas desde el cliente a funciones RPC.

## 
El sistema demuestra el uso de primitivas y estrategias de comunicación basadas en RPC para implementar un chat distribuido, permitiendo a los usuarios interactuar y compartir mensajes de manera eficiente en un entorno distribuido.
- @author: Oscar Julian
- @date: Enero 2023
