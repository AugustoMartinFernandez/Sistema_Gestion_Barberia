<!-- PORTADA -->
<p align="center">
  <img src="docs/Img.png" alt="Sistema de Gestión de Turnos para Barbería" width="100%">
</p>

<h1 align="center">💈 Sistema de Gestión de Turnos para Barbería</h1>

<p align="center">
  Un sistema de gestión completo hecho en <strong>C++</strong>, desde cero, como proyecto integrador de <strong>Programación II</strong> en la UTN.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Lenguaje-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/IDE-Code::Blocks-41AD48?style=for-the-badge" alt="Code::Blocks">
  <img src="https://img.shields.io/badge/Paradigma-POO-orange?style=for-the-badge" alt="POO">
  <img src="https://img.shields.io/badge/Persistencia-Archivos%20Binarios-blueviolet?style=for-the-badge" alt="Archivos binarios">
  <img src="https://img.shields.io/badge/Estado-Terminado-success?style=for-the-badge" alt="Estado">
</p>

---

## 📌 Índice

- [Sobre el proyecto](#-sobre-el-proyecto)
- [¿Qué hace el sistema?](#-qué-hace-el-sistema)
- [Conceptos de programación aplicados](#-conceptos-de-programación-aplicados)
- [Arquitectura del proyecto](#-arquitectura-del-proyecto)
- [Cómo ejecutarlo](#-cómo-ejecutarlo)
- [Para los que van a cursar Programación II](#-para-los-que-van-a-cursar-programación-ii)
- [Equipo](#-equipo)
- [Licencia](#-licencia)

---

## 🎯 Sobre el proyecto

Este es el sistema que armamos como **proyecto integrador de Programación II** en la **Tecnicatura Universitaria en Programación (TUP) de la UTN**. La consigna era simple de enunciar pero grande de hacer, construir, **desde cero y en C++**, un sistema real que gestione la operación diaria de una barbería.

Y eso hicimos. Un sistema de consola que maneja clientes, barberos, servicios, turnos, pagos e informes, con todos los datos guardados de forma **permanente en archivos**, validaciones entre entidades y reportes de gestión. Nada de librerias solo arreglos, punteros, clases y manejo de archivos a mano, que es justo lo que se aprende en la materia.

Más allá de la nota, lo dejamos público con dos intenciones: que sirva como **carta de presentación** de lo que sabemos hacer, y como **guía** para quien venga detrás nuestro en la carrera.

---

## ⚙️ ¿Qué hace el sistema?

El sistema arranca con un menú principal y submenús para cada módulo. Esto es lo que podés hacer:

- 👥 **Clientes** — alta, baja, modificación, listado y consulta por ID. Cada cliente acumula puntos.
- ✂️ **Barberos** — ABM completo con su especialidad y estado.
- 🧾 **Servicios** — catálogo con precio y puntos; consulta por ID y **por rango de precios**.
- 📅 **Turnos** — se asignan a un cliente, un barbero y un servicio en una fecha y hora. **Solo se pueden crear si esas tres entidades existen y están activas.**
- 💳 **Pagos** — se registra el pago de cada turno (monto, fecha, método). Al listar los pagos, también muestra los **turnos que quedaron sin pagar**.
- 📊 **Informes** — recaudación por día/mes/año, servicio más caro, servicios más solicitados, ventas por servicio, cantidad de turnos por barbero, clientes frecuentes, métodos de pago y turnos realizados/cancelados.

Todo se guarda en archivos `.dat`, así que **los datos no se pierden** cuando cerrás el programa.

---

## 🧠 Conceptos de programación aplicados

Esta es la parte que más nos interesa mostrar, porque el sistema es básicamente una excusa para aplicar bien los fundamentos:

| Concepto | Dónde se ve en el sistema |
|---|---|
| **Programación Orientada a Objetos** | Cada entidad (Cliente, Barbero, Servicio, Turno, Pago) es una clase con sus atributos y métodos. |
| **Herencia** | `Cliente` y `Barbero` heredan de `Persona` los datos comunes (nombre, apellido, contacto). Relación **ES-UN**. |
| **Composición** | Un `Turno` y un `Pago` **tienen** una `Fecha` y una `Hora` como objetos. Relación **TIENE-UN**. |
| **Encapsulamiento** | Atributos `private` accesibles solo por getters/setters, que además **validan** los datos. |
| **Constructores y destructores** | Inicialización controlada de cada objeto y liberación de recursos. |
| **Memoria dinámica** | `new` / `delete[]` para los arreglos de conteo de los informes, porque la cantidad de registros se conoce recién en ejecución. |
| **Archivos binarios** | Persistencia con `fwrite`, `fread`, `fseek`, `ftell` y `sizeof` sobre registros de longitud fija. |
| **Sobrecarga de métodos** | `guardar()` con uno o dos parámetros según sea alta o modificación. |
| **Baja lógica** | Nada se borra físicamente: un campo `activo` preserva la integridad entre archivos. |
| **Punteros** | Paso por dirección, recorrido de estructuras y el puntero `this` en la serialización. |

---

## 🗂️ Arquitectura del proyecto

El código está separado en tres capas, para que cada cosa tenga su lugar:

```
Sistema_Gestion_Barberia/
├── include/                  # Headers (.h) — las "interfaces"
│   ├── entidades/            #   Clases del dominio y sus archivos
│   ├── interfaz/             #   Menús de consola
│   └── utilidades/           #   Fecha, Hora, configuración, helpers
├── src/                      # Implementaciones (.cpp)
│   ├── entidades/
│   ├── interfaz/
│   └── utilidades/
├── main.cpp                  # Punto de entrada
└── SistemaBarberia.cbp       # Proyecto de Code::Blocks
```

La lógica está pensada con una división clara: las clases **`Manager`** tienen la lógica de cada entidad, las clases **`Archivo`** se encargan de leer y escribir en disco, y los **`Menu`** son solo la interfaz. Así cada parte hace una sola cosa.

---

## 🚀 Cómo ejecutarlo

1. Cloná el repositorio:
   ```bash
   git clone https://github.com/AugustoMartinFernandez/Sistema_Gestion_Barberia.git
   ```
2. Abrí el archivo **`SistemaBarberia.cbp`** con **Code::Blocks** (compilador GNU GCC).
3. Compilá y ejecutá con **Build & Run** (F9).
4. ¡Listo! Te recibe el menú principal.

> 💡 Está pensado para Windows con Code::Blocks/MinGW (usa la librería `rlutil` para colores y posición en consola).

---

## 🎓 Para los que van a cursar Programación II

Si estás en la **TUP de la UTN** y te toca **Programación II**, este repo es para vos.

Sé lo que se siente mirar un enunciado en blanco sin saber por dónde empezar. Por eso dejamos el código lo más ordenado y comentado posible, para que puedas **abrirlo, leerlo y entender cómo se conecta todo**: cómo se piensa una clase, cómo se relacionan las entidades, cómo se guarda en archivos y cómo se arma un informe.

Usalo como **guía y referencia**. Mirá cómo resolvimos cada parte, copiá la estructura, entendé el *por qué* de cada decisión. Y si te animás, **mejoralo**: hacele un fork, agregale funciones, refactorizalo. Aprender leyendo y mejorando código de otros es de las mejores formas de avanzar.

No es un sistema perfecto, es un sistema **real hecho por estudiantes**. Justamente por eso te puede servir más que un ejemplo de manual.

---

## 👨‍💻 Equipo

Proyecto desarrollado por el **Grupo 42** — UTN, Programación II.

| Integrante | Rol | GitHub |
|---|---|---|
| **Augusto Martín Fernández** | Líder del proyecto · Arquitectura · Validaciones y consultas | [@AugustoMartinFernandez](https://github.com/AugustoMartinFernandez) |
| Ezequiel Martín Bernal | Desarrollo de informes | — |
| Mariano Sebastián Mastrocolo | Informes y módulo de barberos | [@Marian-Zh](https://github.com/Marian-Zh) |
| Braian Emmanuel Rojas | Menús, managers y búsquedas | [@BrRojas](https://github.com/BrRojas) |

---

## 📄 Licencia

Proyecto académico de uso libre para fines educativos. Si te sirve, dejá una ⭐ y compartilo con quien lo necesite.

<p align="center">
  <em>Realizado en C++, mates y muchas horas de Code::Blocks. ☕ jaja</em>
</p>
