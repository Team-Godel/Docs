## Notas preliminares
Este documento ha sido traducido desde el inglés al español especificamente con el motivo de compartir información con mis compañeros hispanohablantes, con algunas pequeñas modificaciones para añadir mas claridad al texto, ya que si se traduce tal cual como está el libro, es posible que el contenido se desvirtúe. Todo hecho desde un miembro del equipo de Gödel para el equipo completo de Gödel, espero que sea de utilidad para todos y que sirva como un buen recurso educativo (porque sinceramente, este libro es uno de los mejores en su tipo).

Traducido por: _Alberto Williams_.
# Patrones de arquitectura de software: Entendiendo los patrones mas comunes en la arquitectura de software y cuando usarlos
Escrito por Mark Richards.
# Introducción
Es muy común para los desarrolladores empezar a programar sin una arquitectura formal. Sin una limpia y bien arquitectura, la mayoría de los desarrolladores recurrirán al estandar tradicional de facto de la arquitectura por capas (formalmente llamada la arquitectura de nivel n), creando capas implícitas de codigo fuente separado en paquetes. Desafortunadamente, lo que resulta a menudo de esta practica es una colección de modulos de codigo fuente desorganizado que carecen de roles claros. Esta es comúnmente referida como la arquitectura de la gran bola de barro de antipatrones (Así de mala es).

Programas carentes de una arquitectura formal son generalmente debilmente estrechas en su relación, son frágiles y dificiles de modificar, y sin una visión o dirección clara. Como resultado de eso, es muy dificil determinar las caracteristicas de la arquitectura de estos programas sin comprender el funcionamiento interno de cada componente y módulo del sistema. Las preguntas basicas acerca del despliegue y el mantenimiento de programas sin una arquitectura formal son dificiles de responder: ¿Escala la arquitectura? ¿Cuales son las caracteristicas del rendimiento del programa? ¿Cuan facilmente responde el programa a un conjunto de cambios? ¿Qué es el despliegue de caracteristicas de un programa? ¿Cuan sensible es la arquitectura?

