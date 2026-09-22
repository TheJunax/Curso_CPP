# 🧠 Ruta de Aprendizaje de C++ — Curso Práctico

> **Objetivo:** aprovechar los fundamentos de C ya dominados para aprender C++ y llegar a un nivel sólido de POO, memoria/RAII, STL, plantillas, excepciones y estructuras de datos y algoritmos.
>
> **Entorno:** Linux + g++ + Visual Studio Code.
>
> **Guía de referencia:** "C++ Data Structures and Algorithms.pdf" (misma carpeta).
>
> **Metodología:** concepto → ejemplo → reto → revisión → checkpoint → proyecto.
>
> **Regla principal:** no avanzar solo por "terminar" temas. Un módulo se considera completado cuando existe comprensión práctica suficiente.

---

# 📊 Estado general

| Fase | Tema | Estado |
|---|---|---|
| V | Validación de conocimientos previos de C | ✅ Completado (2026-09-22) |
| 1 | C++ desde C | ✅ Completado (2026-09-22) |
| 2 | Funciones C++ | ✅ Completado (2026-09-22) |
| 3 | POO básica: clases y objetos | 🟢 En progreso (M1 y M2 ✅, M3 pendiente) |
| 4 | Herencia y polimorfismo | ⬜ Pendiente |
| 5 | Memoria y RAII | ⬜ Pendiente |
| 6 | STL | ⬜ Pendiente |
| 7 | Plantillas | ⬜ Pendiente |
| 8 | Excepciones | ⬜ Pendiente |
| 9 | EDA en C++ | ⬜ Pendiente |

**Progreso orientativo:** ✅ Fases V, 1 y 2 completadas. 🟢 Fase 3 en progreso (M1 y M2). Siguiente: **Fase 3, Módulo 3 — Operadores y amigos**.

---

# 📚 Cómo usamos este documento

Cada sesión sigue este ciclo:

1. 🧠 Concepto
2. 💻 Ejemplo
3. 🔍 Explicación
4. 🧪 Reto
5. 🐛 Revisión del código
6. 📝 Checkpoint
7. 🏆 Proyecto o avance de módulo

### Estados

- ⬜ Pendiente
- 🟡 Por validar
- 🟢 En progreso
- ✅ Completado
- 🔁 Repasar
- 🧭 Adelanto

---

# 📜 Reglas del curso

1. Intentar resolver los retos antes de pedir la solución.
2. Los errores son parte del aprendizaje — explicarlos sin pretenciosidad.
3. No avanzar automáticamente si un concepto fundamental no está claro.
4. Los checkpoints miden comprensión, no memoria.
5. Se pueden hacer adelantos sin cambiar el orden oficial.
6. Cada fase debe terminar con al menos un proyecto.
7. Todo código debe ejecutarse realmente en Linux/g++.
8. Explicar primero el "por qué" y después la sintaxis.
9. Comparar con C (y JS cuando aplique) solo si ayuda a entender C++.
10. Priorizar comprensión de memoria (RAII, ciclo de vida), tipos, POO y comportamiento del lenguaje.
11. Juan ya sabe C: no repetir fundamentos de cero, mostrar las diferencias C++.

---

# 🎓 VALIDACIÓN DE CONOCIMIENTOS PREVIOS (C)

Juan domina C (punteros, memoria dinámica, structs, archivos). Antes de la Fase 1, se valida con retos prácticos que demuestren que puede comparar y traducir entre C y C++.

**Resultados posibles por checkpoint:**

- ✅ Validado → la fase se marca como completada.
- 🔁 A repasar → los temas débiles se registran en 🔁 REPASOS.

## Checkpoint VC1 — Traducción C → C++

**Reto:** tomar un programa básico de C (Hola Mundo con `printf`/`scanf`) y reescribirlo en C++ con `cout`/`cin`, compilarlo con g++ y ejecutarlo.

**Cubre:** `g++` vs `gcc`, `iostream`, `cout`/`cin`, `namespace`, `using namespace std`.

**Resultado:** ✅ Completado (2026-09-22)

## Checkpoint VC2 — Cadenas y arrays

**Reto:** resolver un ejercicio clásico de C ((strlen/strcpy/strcmp)) usando `std::string` y los métodos equivalentes de la STL.

**Cubre:** `std::string`, operadores y métodos, comparación natural de strings.

**Resultado:** ✅ Completado (2026-09-22)

## Checkpoint VC3 — Punteros y memoria

**Reto:** explicar y demostrar en C++ la diferencia entre `*`, `&`, referencias `T&` y por qué en C++ ya casi no se usa punteros crudos.

**Cubre:** punteros vs referencias, `const` con punteros/referencias, `nullptr`.

**Resultado:** ✅ Completado (2026-09-22)

---

# ✅ FASE V — VALIDACIÓN DE C (completada 2026-09-22)

## Objetivo

Confirmar que la base de C está sólida antes de entrar a C++.

### Módulo — Entorno g++

#### Conceptos
- [x] Compilar con `g++`
- [x] `-Wall -Wextra -g`
- [x] Ejecutar con `./programa`
- [x] Diferencia `gcc` vs `g++`

#### Checkpoint
- [x] Compilar manualmente un .cpp
- [x] Explicar para qué sirve cada flag

**Estado:** ✅ Completado (2026-09-22)

---

# ⬜ FASE 1 — C++ DESDE C

## Objetivo

Entender qué cambia C++ frente a C: modelo de datos, entrada/salida y tipos.

## Módulo 1 — Primer programa C++

### Conceptos
- [x] `#include <iostream>`
- [x] `main()`
- [x] `cout` / `cin`
- [x] `std::` y `using namespace std`
- [x] `endl` y `\n`
- [x] Compilación con g++

### Ejercicios
- [x] Hola Mundo en C++
- [x] Entrada y salida con `cin`/`cout`

### Checkpoint
- [x] Comparar `printf`/`scanf` con `cout`/`cin`
- [x] Explicar qué es un namespace

**Estado:** ✅ Completado (cubierto por VC1, sesión 2)

## Módulo 2 — Tipos, `const` y referencias

### Conceptos
- [x] Tipos básicos y `auto` (lección: `0` → int, `0.0` → double)
- [x] `const` y `constexpr`
- [x] Referencias `T&` (vs punteros)
- [x] `nullptr` (vs `NULL`)
- [x] Conversiones: `static_cast` (vs casting de C)

### Ejercicios
- [x] Programa que usa `auto`
- [x] Intercambio de variables con referencias

### Checkpoint
- [x] Explicar por qué las referencias son más seguras que los punteros (VC3)
- [x] Cuándo usar `const`

**Estado:** ✅ Completado (2026-09-22)

### 🏆 Proyecto de fase
- [x] Conversor de unidades reescrito en C++ moderno (Proyecto1.cpp, 6 pruebas pasadas)

**Estado Fase 1:** ✅ Completada (2026-09-22)

---

# ⬜ FASE 2 — FUNCIONES C++

## Objetivo

Dominar las herramientas de funciones que C no tenía.

## Módulo 1 — Sobrecarga y parámetros

### Conceptos
- [x] Sobrecarga de funciones (int/double, ambigüedad y desambiguación con `static_cast`)
- [x] Parámetros por defecto (`dibujarRec`, regla del final de la lista)
- [x] Parámetros por referencia y por valor (ya dominado: puras por valor, `pedirDatos` por ref)
- [x] `inline`

### Ejercicios
- [x] Función `sumar` sobrecargada para `int` y `double`
- [x] Función con parámetros por defecto

### Checkpoint
- [x] ¿Cuándo el compilador elige una sobrecarga? (cuando los argumentos encajan exacto)
- [x] Diferencia entre pasar por valor y por referencia (Proyecto 1 / VC3)

**Estado:** ✅ Completado (2026-09-22)

## Módulo 2 — Lambda y funciones anónimas

### Conceptos
- [x] Sintaxis de lambda `[...](...) -> ...`
- [x] Captura por valor/referencia (demostrado con contraste 125 vs 64)
- [x] Uso con la STL (`std::count_if`)

### Ejercicios
- [x] Lambda que filtra un vector (notas >= 60)

### Checkpoint
- [x] Explicar qué captura y por qué (valor = copia congelada, referencia = original en vivo)

**Estado:** ✅ Completado (2026-09-22)

### 🏆 Proyecto de fase
- [x] Mini calculadora con menú usando funciones C++ (Proyecto2.cpp, batería 6/6)

**Estado Fase 2:** ✅ Completada (2026-09-22)

---

# ⬜ FASE 3 — POO BÁSICA: CLASES Y OBJETOS

## Objetivo

Unir datos y comportamiento en un tipo definido por el usuario.

## Módulo 1 — Clases y encapsulamiento

### Conceptos
- [x] `class` vs `struct`
- [x] `private` / `public` / `protected`
- [x] Métodos y atributos
- [x] `this`
- [x] Métodos `const`

### Ejercicios
- [x] Clase `CuentaBancaria` con depositar/retirar/saldo
- [x] Clase `Persona` con método `const`

### Checkpoint
- [x] ¿Por qué encapsular?
- [x] ¿Qué significa que un método sea `const`?

**Estado:** ✅ Completado (2026-09-22) — Sesión 10

## Módulo 2 — Constructores y destructores

### Conceptos
- [x] Constructor por defecto
- [x] Constructor con parámetros
- [x] Lista de inicialización
- [x] Destructor `~Clase()`
- [x] Orden de construcción/destrucción

### Ejercicios
- [x] Clase `Archivo` que abre/cierra en constructor/destructor
- [x] Lista de inicialización en `Persona`

### Checkpoint
- [x] ¿Cuándo se llama cada constructor y el destructor?
- [x] ¿Por qué se inicializa en la lista y no en el cuerpo?

**Estado:** ✅ Completado (2026-09-22) — Sesión 11

## Módulo 3 — Operadores y amigos

### Conceptos
- [ ] Sobrecarga de operadores (`+`, `==`, `<<`, ...)
- [ ] Funciones `friend`
- [ ] Copia: constructor de copia y `operator=`

### Ejercicios
- [ ] Clase `Complejo` con `+`, `*`, `==`, `<<`

### Checkpoint
- [ ] ¿Qué es y para qué sirve una función `friend`?
- [ ] Diferencia entre constructor de copia y asignación

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] Clase `Fraccion` operativa y probada

---

# ⬜ FASE 4 — HERENCIA Y POLIMORFISMO

## Objetivo

Modelar jerarquías de tipos y despachar métodos dinámicamente.

## Módulo 1 — Herencia

### Conceptos
- [ ] Clases base y derivadas
- [ ] `public` / `protected` / `private` herencia
- [ ] Constructores en herencia
- [ ] Object slicing (🐛)

### Ejercicios
- [ ] Clase `Empleado` → `Gerente`
- [ ] Constructor de base llamado desde derivada

### Checkpoint
- [ ] ¿Qué se hereda y qué no?
- [ ] ¿Qué mal hace el slicing y cómo evitarlo?

**Estado:** ⬜ Pendiente

## Módulo 2 — Polimorfismo

### Conceptos
- [ ] Métodos `virtual`
- [ ] Destructor virtual (🐛)
- [ ] Clases abstractas y métodos puros `= 0`
- [ ] Despacho dinámico

### Ejercicios
- [ ] Jerarquía `Figura` → `Circulo`, `Rectangulo`
- [ ] Contenedor de punteros/refs con polimorfismo

### Checkpoint
- [ ] ¿Qué pasa sin destructor virtual?
- [ ] ¿Cuándo un método debe ser virtual?

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] Sistema de figuras con área/perímetro polimórficos

---

# ⬜ FASE 5 — MEMORIA Y RAII

## Objetivo

Entender el ciclo de vida de los recursos en C++ y delegarlo a la STL.

## Módulo 1 — `new`/`delete` y fugas

### Conceptos
- [ ] `new` / `delete` / `new[]` / `delete[]` (🐛)
- [ ] Recursos y liberación manual
- [ ] Detectar fugas con valgrind

### Ejercicios
- [ ] Programa que fuga memoria a propósito y luego lo corrige

### Checkpoint
- [ ] ¿Por qué `new[]` necesita `delete[]`?
- [ ] ¿Cuándo es mejor no usar `new`?

**Estado:** ⬜ Pendiente

## Módulo 2 — RAII y smart pointers

### Conceptos
- [ ] RAII: el destructor libera
- [ ] `std::unique_ptr`
- [ ] `std::shared_ptr` y `std::weak_ptr`
- [ ] `std::make_unique` / `std::make_shared`

### Ejercicios
- [ ] Reemplazar un `new/delete` por `unique_ptr`
- [ ] Clase que maneja recursos con RAII

### Checkpoint
- [ ] ¿Qué resuelve RAII frente a C?
- [ ] ¿Cuándo usar `shared_ptr` y cuándo `unique_ptr`?

**Estado:** ⬜ Pendiente

## Módulo 3 — Regla de tres/cinco

### Conceptos
- [ ] Copia profunda vs superficial
- [ ] Regla de tres/cinco (🐛)
- [ ] `std::vector` y reubicación de memoria

### Ejercicios
- [ ] Clase con buffer dinámico que implementa copia y movimiento

### Checkpoint
- [ ] ¿Qué pasa si la copia es superficial?
- [ ] ¿Qué problemas causa un destructor mal hecho?

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] `Matriz` dinámica con RAII y regla de cinco

---

# ⬜ FASE 6 — STL

## Objetivo

Programar con los contenedores y algoritmos estándar sin reinventar la rueda.

## Módulo 1 — Contenedores

### Conceptos
- [ ] `std::vector`
- [ ] `std::string`
- [ ] `std::map` / `std::unordered_map`
- [ ] `std::set`
- [ ] `std::stack` / `std::queue`
- [ ] Iteradores

### Ejercicios
- [ ] Agenda con `map<string,string>`
- [ ] Ordenar y buscar en `vector`

### Checkpoint
- [ ] ¿Cuándo `map` y cuándo `unordered_map`?
- [ ] ¿Qué es un iterador y para qué sirve?

**Estado:** ⬜ Pendiente

## Módulo 2 — Algoritmos

### Conceptos
- [ ] `<algorithm>`: `sort`, `find`, `transform`, `accumulate`
- [ ] Rangos y lambdas aplicadas
- [ ] `for` basado en rango

### Ejercicios
- [ ] Pipeline de datos con `transform`/`sort`

### Checkpoint
- [ ] ¿Por qué usar algoritmos estándar y no bucles manuales?

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] Gestor de calificaciones sobre STL (versión C++)

---

# ⬜ FASE 7 — PLANTILLAS

## Objetivo

Escribir código genérico que sirva para muchos tipos.

## Módulo 1 — Funciones y clases plantilla

### Conceptos
- [ ] `template <typename T>`
- [ ] Deducción de tipos
- [ ] Clases plantilla
- [ ] Instanciación en tiempo de compilación

### Ejercicios
- [ ] Función `maximo` genérica
- [ ] Clase `Par<T,U>`

### Checkpoint
- [ ] ¿Cuándo se genera el código de una plantilla?
- [ ] ¿Qué pasa si `T` no soporta la operación?

**Estado:** ⬜ Pendiente

## Módulo 2 — Conceptos y variadicas (avanzado)

### Conceptos
- [ ] `auto` en parámetros (C++20)
- [ ] Conceptos básicos
- [ ] Plantillas variádicas (punto extra)

### Ejercicios
- [ ] Función que imprime N argumentos

### Checkpoint
- [ ] ¿Para qué sirven los conceptos?

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] Contenedor genérico simple con plantillas

---

# ⬜ FASE 8 — EXCEPCIONES

## Objetivo

Manejar errores de forma estructurada y segura.

## Módulo 1 — `try` / `catch` / `throw`

### Conceptos
- [ ] `throw`
- [ ] `try` / `catch`
- [ ] Captura por referencia const (🐛)
- [ ] Orden de los `catch`

### Ejercicios
- [ ] Función que valida división y lanza excepción

### Checkpoint
- [ ] ¿Por qué capturar por referencia const y no por valor?
- [ ] ¿Qué pasa si ninguna excepción se captura?

**Estado:** ⬜ Pendiente

## Módulo 2 — Garantías de excepción

### Conceptos
- [ ] RAII como protección contra excepciones
- [ ] `noexcept`
- [ ] Excepciones standard: `std::out_of_range`, `std::invalid_argument`

### Ejercicios
- [ ] Clase que libera recursos aunque se lance excepción

### Checkpoint
- [ ] ¿Cómo ayuda RAII a manejar excepciones?
- [ ] ¿Cuándo marcar `noexcept`?

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] Validar entradas de usuario con excepciones en un programa real

---

# ⬜ FASE 9 — ESTRUCTURAS DE DATOS Y ALGORITMOS EN C++

## Objetivo

Implementar y aplicar las estructuras de datos clásicas en C++, guiado por el PDF de la Etapa 3.

## Módulo 1 — Listas y pilas/colas

### Conceptos
- [ ] Lista enlazada (sencilla/doble)
- [ ] Pila con `std::stack` y con implementación propia
- [ ] Cola con `std::queue`

### Ejercicios
- [ ] Implementar `ListaEnlazada` con RAII
- [ ] Balanceo de paréntesis con pila

### Checkpoint
- [ ] ¿Cuándo usar lista vs `std::vector`?
- [ ] Complejidad de cada operación

**Estado:** ⬜ Pendiente

## Módulo 2 — Árboles

### Conceptos
- [ ] Árbol binario
- [ ] BST e inserción/búsqueda
- [ ] Recorridos (inorden, preorden, postorden)
- [ ] Árbol con `std::map` internamente

### Ejercicios
- [ ] BST implementada con smart pointers
- [ ] Mostrar recorridos

### Checkpoint
- [ ] ¿Por qué el BST se degenera en el peor caso?
- [ ] Complejidad prometida por `std::map`

**Estado:** ⬜ Pendiente

## Módulo 3 — Grafos y algoritmos

### Conceptos
- [ ] Representación: matriz y lista de adyacencia
- [ ] BFS/DFS
- [ ] Dijkstra
- [ ] Uso del PDF como referencia

### Ejercicios
- [ ] Grafo con `std::vector` de adyacencia
- [ ] Camino más corto con Dijkstra

### Checkpoint
- [ ] ¿Cuándo matriz y cuándo lista de adyacencia?
- [ ] Explicar Dijkstra con ejemplos

**Estado:** ⬜ Pendiente

### 🏆 Proyecto de fase
- [ ] Navegador simple de caminos en un mapa (proyecto final)

---

# 📅 REGISTRO DE SESIONES

| Sesión | Fecha | Contenido | Estado |
|---|---|---|---|
| 1 | — | Creación de la ruta | ✅ Creación |
| 2 | 2026-09-22 | VC1 validado: traducción C→C++ (`cout`/`cin`), flags `-Wall -Wextra -g -o` | ✅ Completado |
| 3 | 2026-09-22 | VC2 validado: `std::string` (length, comparación natural, concatenación, find/npos, indexación) | ✅ Completado |
| 4 | 2026-09-22 | VC3 validado: punteros vs referencias, `nullptr`, `const`. **Fase V completada** | ✅ Completado |
| 5 | 2026-09-22 | Fase 1 M1+M2: `auto`, `constexpr`, `static_cast`, intercambio con referencias | ✅ Completado |
| 6 | 2026-09-22 | 🏆 Proyecto 1 (conversor de unidades): menú, `constexpr`, validación con `return`, funciones puras. **Fase 1 completada** | ✅ Completado |
| 7 | 2026-09-22 | Fase 2 M1: sobrecarga, ambigüedad (`sumar(3,4.5)`), parámetros por defecto, desambiguar con `static_cast` | ✅ Completado |
| 8 | 2026-09-22 | Fase 2 M2: lambdas, captura por valor vs referencia (125 vs 64), `count_if` con vector | ✅ Completado |
| 9 | 2026-09-22 | 🏆 Proyecto 2 (calculadora): funciones, validación de cero (división y módulo), código muerto eliminado. **Fase 2 completada** | ✅ Completado |
| 10 | 2026-09-22 | Fase 3 M1: clases, encapsulamiento (`private`/`public`), `this`, métodos `const` (`CuentaBancaria`, `Persona`). **M1 completado** | ✅ Completado |
| 11 | 2026-09-22 | Fase 3 M2: constructores (por defecto/con parámetros), lista de inicialización, destructor, orden construcción/destrucción, `fstream` (`ofstream`/`ifstream`), clase `Archivo` con RAII. Mini-tema: `enum class` (duda de prerrequisitos saldada). Regla de comunicación "no marica" documentada en AGENTS.md. **M2 completado** | ✅ Completado |

---

# 🐛 ERRORES IMPORTANTES

_(Ir llenando a medida que aparezcan. Revisar SIEMPRE antes de evaluar código.)_

- [ ] `new`/`delete` sin pareja correcta → fuga de memoria o crash
- [ ] Destructor no virtual en clase base → UB al destruir por puntero base
- [ ] Object slicing al pasar objeto derivado por valor
- [ ] Referencia colgante devuelta de una función
- [ ] Regla de tres/cinco ignorada → doble free
- [ ] `using namespace std` global provocando colisiones
- [ ] Llamada a virtual en constructor → no llama al override
- [ ] Comparar `char*` con `==` en vez de `strcmp`/`std::string`
- [ ] Excepción capturada por valor → slicing
- [ ] Cambiar el vector durante la iteración → iterador inválido
- [ ] `std::string = 0` → crash: un string no se inicializa como número (Sesión 3)
- [ ] `find()` no devuelve bool: devuelve posición o `npos`; `npos == npos` es siempre true (Sesión 3)
- [ ] `*p = &x;` con `p = nullptr`: mezclar asignación al puntero (`p = &x`) con la del valor apuntado (`*p = ...`) → error de tipos y segfault (Sesión 4)
- [ ] `else` pegado al último `if` de una cadena → mensajes contradictorios (Sesión 3)
- [ ] `const int &r = x; r = 100;` NO cambia x: es error de compilación (Sesión 4)

---

# 🔁 REPASOS PENDIENTES

_(Ir llenando con los temas débiles marcados en cada checkpoint.)_

- [x] `const` con referencias: confundido en VC3, validado con demo en vivo y reforzado en Fase 1 (Sesiones 4-5)

---

# 🧭 ADELANTOS

_(Registrar aquí cualquier tema trabajado fuera de orden y su justificación.)_

- [x] `enum class` (C++ moderno): explicado en Sesión 11. Juan dudó si `union`/`enum` eran prerrequisito del Módulo 2; se aclaró que ya los domina de C y se mostró la única diferencia importante de C++ (ámbito y tipado fuerte). No bloquea ningún módulo.