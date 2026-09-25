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
| 3 | POO básica: clases y objetos | ✅ Completado (2026-09-23) |
| 4 | Herencia y polimorfismo | ✅ Completado (2026-09-23) |
| 5 | Memoria y RAII | ✅ Completado (2026-09-24) |
| 6 | STL | 🟢 En progreso (M2 ✅) |
| 7 | Plantillas | ⬜ Pendiente |
| 8 | Excepciones | ⬜ Pendiente |
| 9 | EDA en C++ | 🟢 En progreso (M1) |

**Progreso orientativo:** ✅ Fases V, 1, 2, 3, 4 y 5 completadas. Siguiente: Fase 6 (STL).

---

# 🎯 ORDEN RECOMENDADO DE ESTUDIO (enfoque en Estructuras de Datos)

> El profesor de Juan sigue el libro **"Estructuras de Datos en C++" (Joyanes)**. Por eso la ruta se enfoca en EDA: las fases 6 y 7 son las *herramientas* que el propio libro usa, y la Fase 9 es el *corazón* del temario (Caps. 10-18).

**Orden de estudio recomendado:**

```
   1. Fase 6  STL         ┐
         │                │  HERRAMIENTAS (rápido: contenedores + iteradores + plantillas)
   2. Fase 7  Plantillas  ┘
         │
   3. Fase 9  EDA   ◄────── EL GRUESO (~70% del tiempo) — temario del profesor
         │
   4. Fase 8  Excepciones  COMPLEMENTO (al final, robustez general)
```

- **Fases 6 y 7** → se cubren de forma ágil, solo lo necesario para EDA (usar la STL y escribir estructuras genéricas con `template`).
- **Fase 9** → donde va el esfuerzo principal; es exactamente el contenido del libro del profesor.
- **Fase 8** → se deja para el final como complemento (no es EDA, pero suma robustez).

> Los números de fase se mantienen intactos; lo único que cambia es el **orden** en que se estudian.

> **Nota (Sesión 20):** Juan decidió **saltar directo a la Fase 9 (EDA)** sin cerrar la Fase 6 (faltan M1 list/deque, M3 adaptadores, M4 algoritmos) ni la Fase 7 (plantillas). Esas se verán **just-in-time**, cuando alguna estructura de EDA las necesite (p. ej. `template` al hacer la lista genérica, `std::list` al comparar, `stack`/`queue` en el M2).

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

# ✅ FASE 3 — POO BÁSICA: CLASES Y OBJETOS (completada 2026-09-23)

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
- [x] Sobrecarga de operadores (`+`, `==`, `<<`, ...)
- [x] Funciones `friend`
- [x] Copia: constructor de copia y `operator=`

### Ejercicios
- [x] Clase `Complejo` con `+`, `*`, `==`, `<<`

### Checkpoint
- [x] ¿Qué es y para qué sirve una función `friend`?
- [x] Diferencia entre constructor de copia y asignación

**Estado:** ✅ Completado (2026-09-23) — Sesión 13

### 🏆 Proyecto de fase
- [x] Clase `Fraccion` operativa y probada

---

# ✅ FASE 4 — HERENCIA Y POLIMORFISMO (completada 2026-09-23)

## Objetivo

Modelar jerarquías de tipos y despachar métodos dinámicamente.

## Módulo 1 — Herencia

### Conceptos
- [x] Clases base y derivadas
- [x] `public` / `protected` / `private` herencia
- [x] Constructores en herencia
- [x] Object slicing (🐛)

### Ejercicios
- [x] Clase `Empleado` → `Gerente`
- [x] Constructor de base llamado desde derivada

### Checkpoint
- [x] ¿Qué se hereda y qué no?
- [x] ¿Qué mal hace el slicing y cómo evitarlo?

**Estado:** ✅ Completado (2026-09-23) — Sesión 14

## Módulo 2 — Polimorfismo

### Conceptos
- [x] Métodos `virtual`
- [x] Destructor virtual (🐛)
- [x] Clases abstractas y métodos puros `= 0`
- [x] Despacho dinámico

### Ejercicios
- [x] Jerarquía `Figura` → `Circulo`, `Rectangulo`
- [x] Contenedor de punteros/refs con polimorfismo

### Checkpoint
- [x] ¿Qué pasa sin destructor virtual?
- [x] ¿Cuándo un método debe ser virtual?

**Estado:** ✅ Completado (2026-09-23) — Sesión 14

### 🏆 Proyecto de fase
- [x] Sistema de figuras con área/perímetro polimórficos (Proyecto4.cpp: Figura abstracta, Circulo, Rectangulo, override, destructor virtual; verificado: 12.5664/12.5664 y 12/14)

---

# ⬜ FASE 5 — MEMORIA Y RAII

## Objetivo

Entender el ciclo de vida de los recursos en C++ y delegarlo a la STL.

## Módulo 1 — `new`/`delete` y fugas

### Conceptos
- [x] `new` / `delete` / `new[]` / `delete[]` (🐛)
- [x] Recursos y liberación manual
- [x] Detectar fugas con valgrind

### Ejercicios
- [x] Programa que fuga memoria a propósito y luego lo corrige

### Checkpoint
- [x] ¿Por qué `new[]` necesita `delete[]`?
- [x] ¿Cuándo es mejor no usar `new`?

**Estado:** ✅ Completado (2026-09-23) — Sesión 15

## Módulo 2 — RAII y smart pointers

### Conceptos
- [x] RAII: el destructor libera
- [x] `std::unique_ptr`
- [x] `std::shared_ptr` y `std::weak_ptr`
- [x] `std::make_unique` / `std::make_shared`

### Ejercicios
- [x] Reemplazar un `new/delete` por `unique_ptr`
- [x] Clase que maneja recursos con RAII

### Checkpoint
- [x] ¿Qué resuelve RAII frente a C?
- [x] ¿Cuándo usar `shared_ptr` y cuándo `unique_ptr`?

**Estado:** ✅ Completado (2026-09-23) — Sesión 15

## Módulo 3 — Regla de tres/cinco

### Conceptos
- [x] Copia profunda vs superficial
- [x] Regla de tres/cinco (🐛)
- [x] `std::vector` y reubicación de memoria

### Ejercicios
- [x] Clase con buffer dinámico que implementa copia y movimiento

### Checkpoint
- [x] ¿Qué pasa si la copia es superficial?
- [x] ¿Qué problemas causa un destructor mal hecho?

**Estado:** ✅ Completado (2026-09-24) — Sesión 16 (vector/reubicación) + 17 (proyecto Matriz)

### 🏆 Proyecto de fase
- [x] `Matriz` dinámica con RAII y regla de cinco

**Estado Fase 5:** ✅ Completada (2026-09-24) — Proyecto Matriz (Proyecto5.cpp): regla de cinco completa (moves con `noexcept`), bloque plano `new double[f*c]{}`, `operator()` con referencia, `tamF()/tamC()`, `operator<<` amigo. Verificado: copia profunda (`z(0,0)=999` vs `m(0,0)=4.1`), move roba y anula donante (m queda 0×0 sin alocar), valgrind 4 allocs/4 frees 0 leaks 0 errores.

---

# 🗺️ CORRESPONDENCIA CON EL LIBRO (Joyanes, "Estructuras de Datos en C++")

La ruta desde la Fase 6 en adelante está alineada con los capítulos del PDF de la Etapa 3.

| Cap. | Tema del libro | Dónde en la ruta |
|---|---|---|
| 5 | Plantillas (templates) | Fase 7 |
| 6 | Análisis y eficiencia de algoritmos (notación O) | Transversal — se aplica en Fase 9 |
| 7 | Algoritmos recursivos | Transversal — base para árboles (Fase 9 M5-M7) |
| 8 | Ordenación y búsqueda | Fase 6 M4 (`<algorithm>`) + Fase 9 M3 (HeapSort) |
| 10 | Listas | Fase 9 M1 |
| 11 | Pilas | Fase 9 M2 |
| 12 | Colas | Fase 9 M2 |
| 13 | Colas de prioridad y montículos | Fase 9 M3 |
| 14 | Tablas de dispersión / hash | Fase 9 M4 |
| 15 | STL | Fase 6 |
| 16 | Árboles binarios y BST | Fase 9 M5 |
| 17 | Árboles equilibrados (AVL) y árboles B | Fase 9 M6 |
| 18 | Grafos | Fase 9 M7 |

> **Nota:** los capítulos 6 (complejidad/notación O), 7 (recursión) y 8 (ordenación/búsqueda) no tienen fase propia porque son transversales; se cubren dentro de las fases 6 y 9. Si en algún momento se necesita repasarlos de forma aislada, se registran en 🧭 ADELANTOS o 🔁 REPASOS.

> **Orden de estudio:** ver la sección 🎯 ORDEN RECOMENDADO DE ESTUDIO al inicio — el foco es EDA (Fase 9), con las fases 6 y 7 como herramientas y la 8 al final.

---

# 🟢 FASE 6 — STL (libro: Cap. 15, p. 433)

## Objetivo

Programar con los contenedores y algoritmos estándar sin reinventar la rueda.

## Módulo 1 — Iteradores y contenedores secuenciales

### Conceptos
- [ ] Iteradores: `begin()`/`end()`, `++`, `*`, y sus categorías (entrada, salida, forward, bidireccional, acceso aleatorio)
- [ ] `std::vector` (consolidación de lo visto en Fase 5)
- [ ] `std::string` (repaso express de VC2)
- [ ] `std::list` (lista doblemente enlazada de la STL)
- [ ] `std::deque` (doble cola)
- [ ] ¿Cuándo `vector`, cuándo `list`, cuándo `deque`?

### Ejercicios
- [ ] Recorrer y modificar un `vector` con iteradores
- [ ] Comparar `vector` vs `list` al insertar/borrar al inicio

### Checkpoint
- [ ] ¿Qué es un iterador y para qué sirve?
- [ ] ¿Por qué el iterador de `vector` es de acceso aleatorio y el de `list` no?

**Estado:** ⬜ Pendiente

## Módulo 2 — Contenedores asociativos

### Conceptos
- [x] `std::set` / `std::multiset` (conjunto ordenado sin repetidos; `multiset` permite repetidos) — express, Sesión 19
- [x] `std::map` / `std::multimap` (diccionario; `multimap` permite claves repetidas) — Map.cpp, Sesión 19
- [x] `std::unordered_map` / `std::unordered_set` (hash, sin orden) — Frecuencias.cpp, Sesión 19
- [x] ¿Cuándo `map` y cuándo `unordered_map`? (orden O(log n) vs hash O(1))

### Ejercicios
- [x] Agenda con `map<string,string>` (insertar, buscar con `find`, mostrar ordenado, eliminar con `erase`) — Map.cpp, verificado con compilación limpia y valgrind 0 leaks (Sesión 19)
- [x] Contar frecuencias con `unordered_map` — Frecuencias.cpp (Sesión 19)

### Checkpoint
- [x] ¿Cuándo `map` y cuándo `unordered_map`? (respondido: `map` ordena, `unordered_map` es más rápido con hash; Sesión 19)
- [x] ¿Por qué para buscar se usa `find` y no `operator[]`? (respondido: `operator[]` crea la entrada si no existe; Sesión 19)

**Estado:** ✅ Completado (2026-09-24) — Sesión 19

## Módulo 3 — Adaptadores de contenedores

### Conceptos
- [ ] `std::stack`
- [ ] `std::queue`
- [ ] `std::priority_queue`

### Ejercicios
- [ ] Balanceo de paréntesis con `std::stack`
- [ ] Simular una cola de impresión con `std::queue`

### Checkpoint
- [ ] ¿Qué diferencia hay entre un contenedor y un adaptador de contenedor?

**Estado:** ⬜ Pendiente

## Módulo 4 — Algoritmos (`<algorithm>`)

### Conceptos
- [ ] `sort`, `find`, `transform`, `accumulate`
- [ ] Rangos y lambdas aplicadas
- [ ] `for` basado en rango

### Ejercicios
- [ ] Pipeline de datos con `transform`/`sort`
- [ ] Ordenar y buscar en `vector`

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

## Módulo 2 — Conceptos y variadicas (OPCIONAL / AVANZADO — no está en el libro)

### Conceptos
- [ ] `auto` en parámetros (C++20)
- [ ] Conceptos básicos
- [ ] Plantillas variádicas (punto extra)

### Ejercicios
- [ ] Función que imprime N argumentos

### Checkpoint
- [ ] ¿Para qué sirven los conceptos?

**Estado:** ⬜ Pendiente (opcional — se puede omitir sin bloquear la ruta; son temas C++20 que el libro no cubre)

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

# 🟢 FASE 9 — ESTRUCTURAS DE DATOS Y ALGORITMOS EN C++ (libro: Caps. 10-18)

## Objetivo

Implementar y aplicar las estructuras de datos clásicas en C++, guiado por el PDF "Estructuras de Datos en C++" (Joyanes). Cada módulo corresponde a un capítulo del libro.

## Módulo 1 — Listas (Cap. 10)

### Conceptos
- [x] Lista enlazada simple: clase Nodo, cabecera/cola, inserción (cabeza/final/entre nodos), búsqueda, borrado — ✅ COMPLETA (Sesiones 20-21): `insertarInicio`, `insertarFinal`, `insertarOrdenado` (inserción entre nodos), `buscar`, `eliminar` (cabeza/medio/final/no-existe), destructor RAII. Verificada con valgrind 0 leaks 0 errores.
- [ ] Lista ordenada — ✅ técnica de inserción ordenada dominada (`insertarOrdenado`); el resto son los métodos ya hechos. Anotar complejidad en la revisión.
- [x] Lista doblemente enlazada — `ListaDoblementeEnlz.cpp` (Sesión 22): `NodoDoble` con `anterior`/`siguiente`, `cabeza`/`cola`, inserción y eliminación O(1) en ambos extremos, impresión bidireccional, destructor RAII y copia deshabilitada para evitar doble free. Compilación limpia con `g++ -Wall -Wextra -g`; valgrind: 7 allocs/7 frees, 0 leaks y 0 errores.
- [ ] Lista circular
- [ ] Lista genérica con iterador (plantillas)
- [x] `std::list` de la STL (comparación) — StlList.cpp (Sesión 21): push_back O(1) por puntero a cola (vs su ListaEnlazada manual O(n) por solo tener cabeza), iteradores bidireccionales (++/--, rbegin/rend), find+erase (mismo patrón que su eliminar), RAII de fábrica. Conexión: std::list ES una lista doble → calentamiento para ListaDoble.

### Ejercicios
- [ ] Implementar `ListaEnlazada` con RAII y smart pointers — ✅ ListaEnlazada.cpp en mano: punteros crudos + destructor RAII (insertarInicio/Final/Ordenado, buscar, eliminar, imprimir; valgrind 0 leaks 0 errores). Pendiente el refactor a `unique_ptr`.
- [x] `ListaDoble` con inserción/borrado en ambos extremos — `ListaDoblementeEnlz.cpp` (Sesión 22): `insertarInicio`, `insertarFinal`, `eliminarInicio`, `eliminarFinal`, `imprimir`, `imprimirAtras` y destructor RAII. Casos probados: lista vacía, un nodo, varios nodos, eliminación en ambos extremos y del último nodo. Valgrind limpio.

### Checkpoint
- [ ] ¿Cuándo usar lista vs `std::vector`?
- [x] Complejidad de inserción, búsqueda y borrado — validada en Sesión 22: operaciones en los extremos O(1), búsqueda intermedia O(n).

**Estado:** En progreso (Sesión 22: lista doble implementada y verificada; faltan lista circular, iterador genérico y el smart pointer de la lista simple)

## Módulo 2 — Pilas y colas (Caps. 11-12)

### Conceptos
- [ ] Pila: concepto LIFO; implementación con array y con lista enlazada
- [ ] `std::stack`
- [ ] Evaluación de expresiones aritméticas (infija → postfija y evaluación de postfija)
- [ ] Cola: concepto FIFO; implementación con array y con array circular
- [ ] Cola genérica con lista enlazada
- [ ] Bicolas (doble entrada) y `std::deque`
- [ ] `std::queue`

### Ejercicios
- [ ] Balanceo de paréntesis con pila
- [ ] Convertir una expresión infija a postfija con pila
- [ ] Cola circular propia

### Checkpoint
- [ ] ¿Cuándo usar pila y cuándo cola?
- [ ] ¿Por qué una cola con array simple desperdicia espacio y la circular no?

**Estado:** ⬜ Pendiente

## Módulo 3 — Colas de prioridad y montículos (Cap. 13)

### Conceptos
- [ ] Cola de prioridad (TAD)
- [ ] Implementaciones: vector/lista ordenada, tabla de prioridades
- [ ] Montículo (heap): definición, propiedad de ordenación, representación en array
- [ ] Operaciones: insertar, buscar mínimo, eliminar mínimo
- [ ] Ordenación por montículos (HeapSort)
- [ ] `std::priority_queue`
- [ ] (Avanzado) Montículos binomiales

### Ejercicios
- [ ] Implementar un `MinHeap` con RAII
- [ ] HeapSort sobre un `std::vector`

### Checkpoint
- [ ] ¿Por qué HeapSort es O(n log n)?
- [ ] ¿Qué diferencia una cola de prioridad de una cola normal?

**Estado:** ⬜ Pendiente

## Módulo 4 — Tablas de dispersión y funciones hash (Cap. 14)

### Conceptos
- [ ] Tabla de dispersión: definición y operaciones
- [ ] Funciones de dispersión: aritmética modular, plegamiento, mitad del cuadrado, método de la multiplicación
- [ ] Colisiones y su resolución
- [ ] Direccionamiento abierto: exploración lineal, cuadrática y doble dirección dispersa
- [ ] Direccionamiento enlazado (encadenado)
- [ ] Relación con `std::unordered_map`

### Ejercicios
- [ ] Implementar `TablaDispersa` con direccionamiento abierto
- [ ] Tabla dispersa encadenada (listas por cubeta)

### Checkpoint
- [ ] ¿Qué es una colisión y por qué ocurre?
- [ ] ¿Cuándo conviene direccionamiento abierto y cuándo enlazado?

**Estado:** ⬜ Pendiente

## Módulo 5 — Árboles binarios y BST (Cap. 16)

### Conceptos
- [ ] Árboles: terminología (raíz, hojas, altura, grado)
- [ ] Árbol binario: equilibrio, árbol completo
- [ ] Representación de un nodo y creación de un árbol
- [ ] Árbol de expresión
- [ ] Recorridos: preorden, enorden, postorden
- [ ] Árbol binario de búsqueda (BST): búsqueda, inserción, borrado
- [ ] Diseño recursivo de un árbol de búsqueda

### Ejercicios
- [ ] BST implementada con smart pointers
- [ ] Mostrar los tres recorridos
- [ ] Evaluar un árbol de expresión

### Checkpoint
- [ ] ¿Por qué el BST se degenera en el peor caso?
- [ ] Complejidad prometida por `std::map`

**Estado:** ⬜ Pendiente

## Módulo 6 — Árboles equilibrados y árboles B (Cap. 17)

### Conceptos
- [ ] Eficiencia de búsqueda en un árbol ordenado
- [ ] Árbol AVL: altura, factor de equilibrio
- [ ] Rotaciones: simple y doble
- [ ] Inserción con balanceo
- [ ] Árboles B: definición, TAD y representación de página
- [ ] Formación de un árbol B (orden m), búsqueda e inserción

### Ejercicios
- [ ] AVL con rotaciones simples y dobles
- [ ] Búsqueda e inserción en un árbol B

### Checkpoint
- [ ] ¿Qué garantiza un AVL que un BST simple no?
- [ ] ¿Por qué los árboles B se usan en bases de datos y sistemas de archivos?

**Estado:** ⬜ Pendiente

## Módulo 7 — Grafos y algoritmos (Cap. 18)

### Conceptos
- [ ] Conceptos: nodo, arista, grado, camino; TAD Grafo
- [ ] Representación: matriz de adyacencia y listas de adyacencia
- [ ] Recorridos: BFS (anchura) y DFS (profundidad)
- [ ] Componentes conexas y fuertemente conexas
- [ ] Ordenación topológica
- [ ] Matriz de caminos y cierre transitivo (Warshall) — opcional
- [ ] Caminos mínimos desde un origen: Dijkstra
- [ ] Todos los caminos mínimos: Floyd — opcional
- [ ] Árbol de expansión mínimo: Prim y Kruskal

### Ejercicios
- [ ] Grafo con `std::vector` de adyacencia
- [ ] BFS/DFS sobre un grafo
- [ ] Camino más corto con Dijkstra
- [ ] Árbol de expansión mínimo con Prim y con Kruskal

### Checkpoint
- [ ] ¿Cuándo matriz y cuándo lista de adyacencia?
- [ ] Explicar Dijkstra con ejemplos
- [ ] Diferencia entre Prim y Kruskal

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
| 12 | 2026-09-23 | Repaso Fase 3 M2: scope y orden de vida de objetos (constructor/destructor, inversión de orden), lista de inicialización vs asignación en el cuerpo, miembro `const` y error "no match for operator=". MiniReto.cpp: clase `Persona` con `const string nombre`, getter público, verificación desde `main` compilada con `-Wall -Wextra` (exit 0). Checkpoint 2/3: quedó flojo "const vs private" y "asignar vs inicializar" → marcado en 🔁 | 🟡 Por validar |
| 13 | 2026-09-23 | Fase 3 M3: sobrecarga de operadores (`operator+`, `*`, `==`), funciones `friend` (`operator<<` con encadenamiento), constructor de copia vs `operator=` (demo Copia.cpp, predicción 4/4 en Prediccion.cpp). 🏆 Proyecto 3 (Complejo con +,\*,\,==,<<) y 🏆 Proyecto 4 (Fraccion con mcd, simplificación, signo, +,-,\*,/,\,==,<<). 🐛 shadowing detectado y corregido: `den = 1` en cuerpo modificaba el parámetro, no el miembro; fix con ternario en lista de inicialización. **Fase 3 completada** | ✅ Completado |
| 14 | 2026-09-23 | Fase 4 M1+M2: herencia (`public`/`protected`), constructores en cadena, object slicing (demo 48 vs 40 bytes), `virtual` y despacho dinámico (demo: sin virtual → "Figura generica 0"; con virtual → áreas reales), destructor virtual (demo Base/Derivada: sin virtual el ~Derivada no corre), clases abstractas, `override`, for basado en rango y `vector` (adelanto Fase 6). Ejercicios: CuentaBancaria→CuentaAhorros (Herencia.cpp), Empleado→Gerente (ejemplo). 🏆 Proyecto de fase: sistema de figuras (Proyecto4.cpp) aprobado. Checkpoints M1 y M2 en voz de Juan. Regla de tutoría: NO modificar el código del estudiante sin permiso (jalón de orejas registrado). **Fase 4 completada** | ✅ Completado |
| 15 | 2026-09-23 | Fase 5 (continuación de la sesión 14, mismo día): M1 `new`/`delete`/`new[]`/`delete[]` (Memoria1.cpp, orden inverso de destrucción), valgrind, reto Fuga.cpp corregido (`delete` → `delete[]`: warning `-Wmismatched-new-delete` + crash `munmap_chunk invalid pointer`). ✅ M1. M2 RAII: smart pointers — `unique_ptr` (move, sin copia, destrucción automática, demo SmartPointers.cpp + valgrind 0), `shared_ptr`/`weak_ptr` (use_count, make_shared, demo en chat), reto: Fuga.cpp reescrito sin `new`/`delete` (unique_ptr + make_unique + parámetros por defecto; valgrind `All heap blocks were freed`). ✅ M2. M3: copia superficial vs profunda (BufferMal doble free con AddressSanitizer vs BufferBien valgrind limpio), regla de tres/cinco, reto RetoReglaCinco.cpp (move ctor con bug `datos(new int (n))` → 12 bytes definitivamente perdidos + bloque de 1 int; corregido a robo directo `datos(otro.datos)` → 5 allocs/5 frees). Checkpoints M1, M2 y M3 en voz de Juan. Regla de tutoría reforzada: AVISAR antes de crear archivos y no tocar sus archivos sin autorización. Duda resuelta: el hash se ve en Fase 6 (`std::unordered_map`) y EDA. **Fase 5 M1 y M2 ✅, M3 a medias** | ✅ Completado |
| 16 | 2026-09-24 | Fase 5 M3 (cierre): `std::vector` y reubicación de memoria. Demo VectorReubicacion.cpp (size vs capacity, crecimiento 1→2→4→8→16, O(1) amortizado). Reto AtrapaVector.cpp: clase Contador contadora de copias/movimientos dentro de un vector. Descubrimiento clave: con move `noexcept` el vector REUBICA MOVIENDO (0 copias); sin `noexcept` el vector copia todos los elementos (garantía fuerte de excepción, `move_if_noexcept`). Conexión con RetoReglaCinco: el vector es el juez de la regla de cinco. 🐛 copy ctor sin `const` corregido a `Contador(const Contador&)`. Checkpoint 3/3 aprobado (por qué copia sin noexcept / const faltante / por qué 10 destructores al final). **M3 ✅ — falta solo el 🏆 proyecto `Matriz`** | ✅ Completado |
| 17 | 2026-09-24 | 🏆 Proyecto de fase: `Matriz` dinámica (Proyecto5.cpp). Decision de diseño discutida: bloque plano unico `new double[f*c]{}` (como hace std::vector) vs doble puntero vs vector miembro. Iteraciones: (1) parametro `datos` sobrando en el constructor (warning -Wunused-parameter) y copy ctor/asignacion que alocaban sin copiar contenido → corregido con bucle; (2) 🐛 shadowing en `operator()(int filas, int c)` — funcionaba por casualidad pero confundia al llamar → renombrado a `f`; (3) 🐛 `cout << "\n"` dentro de `operator<<` (era `os`) → mezcla de streams, corregido; (4) move assign sin `noexcept` → corregido; (5) demo final: copia profunda `z(0,0)=999 | m(0,0)=4.1`, move roba (m queda 0×0 sin alocar), valgrind 4 allocs/4 frees 0 leaks 0 errores. **Fase 5 COMPLETADA** | ✅ Completado |
| 18 | 2026-09-24 | Inicio Fase 6 (STL): contenedores + iteradores, demo StlDemo1_Map.cpp (`std::map`, `find`/`end`, `it->first/second`, for-rango, orden automático por clave, trampa de `operator[]`). Reto lanzado: Agenda con `map<string,string>` (menú agregar/buscar/mostrar/eliminar) — **pendiente de resolver**. Ajuste de la ruta con el libro Joyanes (caps 10-18): añadida tabla 🗺️ de correspondencia; Fase 6 reestructurada en 4 módulos (Cap 15: iteradores/secuenciales, asociativos, adaptadores, algoritmos); Fase 9 reestructurada en 7 módulos alineados a los caps (listas, pilas/colas, montículos, hash, BST, AVL/árboles B, grafos) e incorporados los caps 13, 14 y 17 que faltaban; Fase 7 M2 marcado OPCIONAL (C++20, fuera del libro). Decisión de alcance tomada con Juan vía preguntas. Además, a raíz de que el profesor pidió centrarse en estructuras de datos, se añadió la sección 🎯 ORDEN RECOMENDADO DE ESTUDIO: Fase 6 (STL express) → Fase 7 (Plantillas express) → Fase 9 (EDA, el grueso) → Fase 8 (Excepciones, al final). Juan preguntó por el `trie`; se explicó qué es y se aclaró que NO está dentro de los árboles B (estructuras distintas); quedó agendado como tema extra para después de árboles (🧭 ADELANTOS) | ✅ Completado |
| 19 | 2026-09-24 | Fase 6 M2 (asociativos): reto de la **Agenda con `map<string,string>`** completado (Map.cpp). Funciones `agregarContacto`, `buscarContacto` (find/end), `mostrarContactos` (iteradores), `eliminarContacto` (find + erase), menú `do-while`+`switch`. 🐛 detectado y corregido: en el `case 1` leía el teléfono en `nombre` (`cin >> nombre` dos veces) → contacto con nombre = teléfono y teléfono vacío. Corregido a `cin >> telefono`. Mejora aplicada: `const`-correctness en `buscarContacto` y `mostrarContactos`. Verificado: flujo completo agregar/mostrar/buscar existente/buscar inexistente/eliminar/mostrar, compila limpio y valgrind 0 leaks. **M2 cerrado:** checkpoint aprobado 2/2 (map vs unordered_map; find vs operator[]) y ejercicio de frecuencias hecho por el tutor en Frecuencias.cpp a petición de Juan (ya dominaba el tema). Explicados express `set`/`multiset`/`multimap`. | ✅ Completado |
| 20 | 2026-09-24 | **Arranque de EDA (Fase 9 M1, Cap. 10 — Listas).** Decisión de Juan (vía pregunta): saltar directo a EDA; Fase 6 M1/M3/M4 y Fase 7 quedan just-in-time. Concepto de lista enlazada vs array (inserción O(1) al inicio, búsqueda O(n), sin acceso aleatorio). Puente C→C++: `struct Nodo` con `malloc` → `class Nodo` con constructor y `new`. Esqueleto `ListaEnlazada.cpp` con clase `Nodo` + clase `Lista` (`cabeza`) y 3 TODO. Juan implementó `insertarInicio`, `imprimir` y el destructor RAII. 🐛 en el primer intento del destructor: sin `while`, borraba `temp` (2º nodo) en vez de `cabeza`, y leía `temp->siguiente` **después** del `delete` → *Invalid read* + 32 bytes fugados. Corregido con el `while` y el orden correcto (leer siguiente → borrar → avanzar). Verificado: `1-> 7-> 3-> null`, compila limpio, valgrind 0 leaks / 0 errores. | ✅ Completado |
| 21 | 2026-09-24 | Fase 9 M1 (Cap. 10): **núcleo de la lista enlazada simple completado** (ListaEnlazada.cpp). `insertarInicio` ✓, `insertarFinal` ✓ (tras 🐛 self-loop en lista vacía corregido), `buscar` ✓ (quitarle el cout: el que busca no imprime), `eliminar` ✓ — el reto gordo, resuelto paso a paso tras 4 intentos: se corrigieron (1) falta de `return true` en caso cabeza, (2) orden en condición del while (`actual != nullptr` ANTES de `actual->dato` — corto-circuito del `&&`), (3) línea trampa `anterior->siguiente = nullptr` que cortaba toda la lista y (4) `return false` en vez de `true` al borrar con éxito. Destructor RAII ✓. Verificado: flujo completo, valgrind 0 leaks / 0 errores, sin segfaults. Método usado: construcción guiada paso a paso (guarda → caso cabeza → paseo dos punteros → desenganche → delete). Luego `insertarOrdenado` completado a la primera: caso fácil reutiliza patrones de `insertarInicio`, paseo con `anterior`/`actual` y condición `actual != nullptr && actual->dato < valor` (corto-circuito aplicado sin ayuda), doble engarce `nuevo->siguiente = actual; anterior->siguiente = nuevo`. Resultado `2-> 3-> 5-> 8-> null`, valgrind 0 leaks 0 errores. **Lista simple COMPLETA (inserción cabeza/final/entre nodos, búsqueda, borrado, RAII).** Mini-tema corto: **`std::list` de la STL** (StlList.cpp) — push_back O(1) por puntero a cola (vs su manual O(n)), iteradores bidireccionales ++/-- y rbegin/rend, find+erase con el patrón de su eliminar, RAII de fábrica; conexión con la próxima ListaDoble. | ✅ Completado |
| 22 | 2026-09-25 | Fase 9 M1 (Cap. 10): `ListaDoble` con `NodoDoble` (`anterior`/`siguiente`), `cabeza`/`cola`, inserción y eliminación O(1) en ambos extremos, impresión bidireccional, destructor RAII y copia deshabilitada. Se corrigieron enlaces colgantes/use-after-free al eliminar, casos de lista vacía y nodo único, y `if (cola = nullptr)` por comparación. `main` ampliado; compilación limpia con `g++ -Wall -Wextra -g`; valgrind: 7 allocs/7 frees, 0 leaks y 0 errores. Checkpoint aprobado: vaciar ambos extremos, guardar el nodo antes de `delete` y búsqueda intermedia O(n). | Completado |

---

# 🐛 ERRORES IMPORTANTES

_(Ir llenando a medida que aparezcan. Revisar SIEMPRE antes de evaluar código.)_

- [x] `new`/`delete` sin pareja correcta → fuga de memoria o crash (`delete` sobre `new[]` detectado por `-Wmismatched-new-delete` + `munmap_chunk(): invalid pointer`, Sesión 15)
- [x] Destructor no virtual en clase base → UB al destruir por puntero base (Sesión 14)
- [x] Object slicing al pasar objeto derivado por valor (Sesión 14)
- [ ] Referencia colgante devuelta de una función
- [x] Regla de tres/cinco ignorada → doble free (BufferMal, Sesión 15)
- [ ] `using namespace std` global provocando colisiones
- [ ] Llamada a virtual en constructor → no llama al override
- [ ] Comparar `char*` con `==` en vez de `strcmp`/`std::string`
- [ ] Excepción capturada por valor → slicing
- [ ] Cambiar el vector durante la iteración → iterador inválido
- [ ] Constructor de copia sin `const`: `Contador(Contador &otro)` no puede copiar desde objetos `const`; debe ser `Contador(const Contador &otro)`. No pica hoy, pica cuando el vector/STL necesite copiar desde algo const (Sesión 16, AtrapaVector)
- [ ] Move constructor SIN `noexcept` dentro de `std::vector` → el vector COPIA en las reubicaciones (garantía fuerte de excepción, `move_if_noexcept`). Con `noexcept` → mueve O(1). El `noexcept` del move es la señal de rendimiento (Sesión 16, AtrapaVector)
- [ ] `cout` dentro de `operator<<` que recibe `os`: el salto de línea se va al stream equivocado (pantalla en vez del destino). Dentro de un `operator<<` TODO sale por `os` (Sesión 17, Proyecto5; misma lección del método que calcula e imprime, Sesión 14)
- [ ] Parámetro de constructor que sobra y hace shadowing con el miembro: `Matriz(int filas, int col, double* datos)` con `datos` sin usar → warning `-Wunused-parameter`; el parámetro debe eliminarse (Sesión 17, Proyecto5)
- [ ] Leer dos veces en la MISMA variable: `cin >> nombre` cuando se quería `cin >> telefono` → el segundo valor pisa al primero y la otra variable queda vacía. Compila sin warning; solo se ve en la salida (nombre = teléfono, teléfono = ""). (Sesión 19, Map.cpp)
- [ ] `new int (n)` vs `new int[n]`: los PARÉNTESIS crean UN solo int con valor `n`; los CORCHETES crean un array de `n`. Confundirlos en un move ctor → bloque del tamaño equivocado (Sesión 15, RetoReglaCinco)
- [ ] Move constructor que ALOCA en vez de ROBAR: el move debe ser cero asignaciones de memoria; si el donante se anula sin robar/liberar su bloque → fuga silenciosa (12 bytes definitivamente perdidos, Sesión 15)
- [ ] Shadowing: parámetro del constructor con el mismo nombre del miembro → `den = 1` en el cuerpo cambia el PARÁMETRO, no el miembro (el miembro ya nació con la lista de inicialización). Fix: ternario en la lista `den(den == 0 ? 1 : den)` (Sesión 13)
- [ ] `std::string = 0` → crash: un string no se inicializa como número (Sesión 3)
- [ ] Destructor de lista enlazada mal escrito: (1) sin `while` solo libera un nodo; (2) borrar `temp` (el 2º) en vez de `cabeza` (el 1º) fuga el primero; (3) leer `temp->siguiente` DESPUÉS del `delete` = *use-after-free* (valgrind: Invalid read). Regla: **leer el siguiente → borrar el actual → avanzar**. (Sesión 20, ListaEnlazada.cpp)
- [ ] Self-loop en lista enlazada: `nuevo->siguiente = cabeza` cuando `cabeza` ya es `nuevo` → bucle infinito silencioso (timeout 124). El constructor ya inicializa `siguiente(nullptr)`; esa línea SOBRA (Sesión 20, ListaEnlazada.cpp)
- [ ] `eliminar` de lista enlazada — 4 errores clásicos: (1) falta `return true` tras borrar la cabeza → sigue caminando con lista modificada; (2) `actual->dato != valor && actual != nullptr` lee el dato antes de validar null → el orden debe ser `actual != nullptr && actual->dato != valor` (corto-circuito del `&&`); (3) `anterior->siguiente = nullptr` después del desenganche correcto → corta toda la lista restante; (4) `return false` al haber borrado con éxito. (Sesión 21, ListaEnlazada.cpp)
- [ ] Método de cálculo que imprime (cout dentro de area()/perimetro()): mezcla responsabilidades; el método solo calcula y devuelve, quien imprime es el llamador (Sesión 14, Proyecto4; misma lección del `\n` en operator<< de la Fraccion)
- [ ] Método que mezcla estilo imperativo y funcional: `saldo += monto` + devolver copia (depositar de Herencia.cpp) → comportamiento doble y confuso; elegir uno: void que muta this, o const que devuelve nuevo (Sesión 14)
- [ ] `find()` no devuelve bool: devuelve posición o `npos`; `npos == npos` es siempre true (Sesión 3)
- [ ] `*p = &x;` con `p = nullptr`: mezclar asignación al puntero (`p = &x`) con la del valor apuntado (`*p = ...`) → error de tipos y segfault (Sesión 4)
- [ ] `else` pegado al último `if` de una cadena → mensajes contradictorios (Sesión 3)
- [ ] `const int &r = x; r = 100;` NO cambia x: es error de compilación (Sesión 4)
- [x] Lista doblemente enlazada: al borrar un nodo hay que reconectar el vecino (`cabeza->anterior = nullptr` o `cola->siguiente = nullptr`) antes de `delete`; si no, queda un puntero colgante y valgrind marca *Invalid read*. Al borrar el único nodo, `cabeza` y `cola` deben quedar en `nullptr` (Sesión 22, ListaDoblementeEnlz.cpp).
- [x] `if (cola = nullptr)` es asignación, no comparación: compila con warning `-Wparentheses` y deja el enlace en estado incorrecto; debe escribirse `cola == nullptr` (Sesión 22).

---

# 🔁 REPASOS PENDIENTES

_(Ir llenando con los temas débiles marcados en cada checkpoint.)_

- [x] `const` con referencias: confundido en VC3, validado con demo en vivo y reforzado en Fase 1 (Sesiones 4-5)
- [ ] `const` vs `private` (dos ejes distintos: acceso vs momento de asignación) y asignación en el cuerpo vs inicialización en la lista: explicado en Sesión 12, Juan dijo entender pero no comprobó con código (declinó el ejercicio). Retomar con un mini-ejercicio cuando salga el tema

---

# 🧭 ADELANTOS

_(Registrar aquí cualquier tema trabajado fuera de orden y su justificación.)_

- [x] `enum class` (C++ moderno): explicado en Sesión 11. Juan dudó si `union`/`enum` eran prerrequisito del Módulo 2; se aclaró que ya los domina de C y se mostró la única diferencia importante de C++ (ámbito y tipado fuerte). No bloquea ningún módulo.
- [x] `for` basado en rango (`for (auto* f : figuras)`) y `std::vector` (push_back, size, recorrido): salieron natural en la Sesión 14 (Fase 4, proyecto de figuras) y se explicaron. Adelanto de la Fase 6; se profundizará allá con algoritmos.
- [ ] `trie` (árbol de prefijos): tema EXTRA, **fuera del libro de Joyanes** (no es temario del profesor). Juan preguntó por él en la Sesión 18. Quedó **agendado para verlo después de la Fase 9 M5/M6 (árboles)**, ya que usa nodos, punteros/smart pointers y recursión. Idea: árbol N-ario donde cada arista es una letra; cada nodo con `std::map<char, Nodo*>`; sirve para autocompletado y búsqueda por prefijo en O(longitud). Ojo: NO está dentro de los árboles B (confusión aclarada: son estructuras distintas, ambos árboles N-arios pero de lógica diferente).