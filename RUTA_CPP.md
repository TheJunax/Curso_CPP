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
| 9 | EDA en C++ | 🟢 En progreso (M1 ✅ parcial, M2 en curso, **M4 ✅ contenido** ⏳ reto) |

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

> **Nota (Sesión 28):** M5 (BST) y la parte de AVL de M6 quedaron **completos y validados** (escritos por Juan, valgrind limpio). El **heap** (montículo, M3 de la Fase 6) se adelantó aquí porque es un árbol y es el prerrequisito directo de Dijkstra/Kruskal de M7. **Pendiente en árboles:** árbol B (M6) y árbol de expresión (M5). **Existe material del profesor en `Arboles y Grafos/`** (9 archivos de árboles + 11 de grafos con `LEEME.md` y orden sugerido) — se usa de base y los archivos de Juan van aparte para comparar.

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

**Estado Fase 5:** ✅ Completada (2026-09-24) — Proyecto Matriz (Proyecto5.cpp): regla de cinco completa (moves con `noexcept`), bloque plano ` newdouble[f*c]{}`, `operator()` con referencia, `tamF()/tamC()`, `operator<<` amigo. Verificado: copia profunda (`z(0,0)=999` vs `m(0,0)=4.1`), move roba y anula donante (m queda 0×0 sin alocar), valgrind 4 allocs/4 frees 0 leaks 0 errores.

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

## Módulo 1 — Funciones y clases plantilla (express, Sesión 25)

### Conceptos
- [x] `template <typename T>` (Plantilla.cpp)
- [x] Deducción de tipos — y su trampa: deducir es tomar lo que le das, no lo que querías (Sesión 25)
- [x] Clases plantilla — `Nodo<T>` y `ListaCircular<T>` (PlantillaCircular.cpp)
- [x] Instanciación en tiempo de compilación — una clase, N copias generadas por el compilador (Sesión 25)

### Ejercicios
- [x] Función genérica de mínimo/máximo — `minimo` con `int`, `double` y `std::string` (Plantilla.cpp, Sesión 25)
- [ ] Clase `Par<T,U>` — sustituido por el ejercicio más útil: lista genérica con iterador (ver Fase 9 M1)

### Checkpoint
- [x] ¿Cuándo se genera el código de una plantilla? (en compilación; cero costo en ejecución — validado al ver que `ListaCircular<int>` y `ListaCircular<std::string>` son dos clases distintas, Sesión 25)
- [x] ¿Qué pasa si `T` no soporta la operación? (el error aparece al instanciar; y si la deduce mal, no hay error: compara direcciones en vez de texto con `const char*`, Sesión 25)

**Estado:** ✅ Completado (express, Sesión 25) — el M2 variádicas sigue opcional

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
- [x] Lista circular — `ListaCircular.cpp` (Sesiones 23-24): lista simplemente enlazada cuyo último nodo apunta a la cabeza (`ultimo->siguiente = cabeza`) en vez de `nullptr`. Nodo único se apunta a sí mismo; lista vacía = `cabeza == nullptr` y `cola == nullptr`. `insertarFinal`/`insertarInicio` (los tres casos), `buscar`, `eliminar` (cabeza/intermedio/cola/único nodo), `imprimir` que repite la cabeza para mostrar el ciclo, destructor RAII y copia deshabilitada. **Optimización (Sesión 24):** se agregó el puntero `cola` → insertar al inicio, insertar al final y borrar la cabeza pasan a **O(1)**; borrar la cola sigue O(n) porque en una lista simple no hay forma de obtener el anterior. Complejidades resultantes: simple O(1)/O(n)/O(1)/O(n) → circular+cola O(1)/O(1)/O(1)/O(n) → doble O(1) en los cuatro casos (motivo de ser de la lista doble). Verificación: compilación limpia y valgrind 7 allocs/7 frees, 0 fugas, 0 errores.
- [x] Lista genérica con iterador (plantillas) — la parte de **plantilla** quedó hecha (Sesión 25: `PlantillaCircular.cpp` con `ListaCircular<int>` y `ListaCircular<std::string>` sobre el mismo molde). Falta el **iterador** (`begin()`/`end()`) para poder usar `for` por rango sobre la lista propia.
- [x] `std::list` de la STL (comparación) — StlList.cpp (Sesión 21): push_back O(1) por puntero a cola (vs su ListaEnlazada manual O(n) por solo tener cabeza), iteradores bidireccionales (++/--, rbegin/rend), find+erase (mismo patrón que su eliminar), RAII de fábrica. Conexión: std::list ES una lista doble → calentamiento para ListaDoble.

### Ejercicios
- [x] Implementar `ListaEnlazada` con RAII y smart pointers — **completado (Sesión 25)**: `ListaEnlazadaSmart.cpp` es la `ListaEnlazada` genérica (`template <typename T>`) con `std::unique_ptr` en `cabeza` y en `Nodo<T>::siguiente`. Sin destructor (la cadena se libera en cascada: cada nodo es dueño del siguiente) y sin `= delete` manual (el `unique_ptr` no es copiable, el compilador ya borra la copia). `std::move` transfiere la propiedad. Probada con `int` y `std::string`; valgrind 12 allocs/12 frees, 0 fugas, 0 errores. Versión con punteros crudos conservada en `ListaEnlazada.cpp` para comparar.
- [x] `ListaDoble` con inserción/borrado en ambos extremos — `ListaDoblementeEnlz.cpp` (Sesión 22): `insertarInicio`, `insertarFinal`, `eliminarInicio`, `eliminarFinal`, `imprimir`, `imprimirAtras` y destructor RAII. Casos probados: lista vacía, un nodo, varios nodos, eliminación en ambos extremos y del último nodo. Valgrind limpio.
- [x] `ListaCircular` con inserción, búsqueda y borrado — `ListaCircular.cpp` (Sesión 23): los 4 casos de borrado (cabeza, intermedio, cola, único nodo) más lista vacía probados; destructor RAII y copia deshabilitada. Valgrind: 7 allocs/7 frees, 0 leaks, 0 errores.

### Checkpoint
- [ ] ¿Cuándo usar lista vs `std::vector`?
- [x] Complejidad de inserción, búsqueda y borrado — validada en Sesión 22: operaciones en los extremos O(1), búsqueda intermedia O(n).

**Estado:** En progreso (Sesión 25: plantillas express + lista genérica con `unique_ptr`; falta el iterador propio y el checkpoint "¿cuándo usar lista vs `std::vector`?")

## Módulo 2 — Pilas y colas (Caps. 11-12)

### Conceptos
- [x] Pila: concepto LIFO (Sesión 26) — *Last In, First Out*, analogía de los platos del lavaplatos; todo lo que "va apilando" es pila: atrás del navegador, Ctrl+Z, recursión, llamadas anidadas
- [x] Por qué existe la pila: evaluación de expresiones en notación **postfija** (RPN) — `2 + 3 * 4` → `2 3 4 * +`, donde desaparece el problema de la precedencia (Sesión 26)
- [x] Las cuatro operaciones: `meter` (push), `sacar` (pop), `cima` (top), `estaVacia` (empty) (Sesión 26)
- [x] **El invariante de la pila sobre array: la pila no es el array, la pila es el `tope`.** Los elementos son exactamente los índices `0..tope`; lo que está por encima es basura que existe en la memoria pero no pertenece a la pila. Si se escribe sin subir el `tope`, el siguiente `meter` sobrescribe la misma casilla y la pila queda mintiendo (sesenta `tamano()` en 0) **sin error ni fuga detectable** (Sesión 26)
- [x] `bool sacar(T& valor)` en vez de `T sacar()`: el `bool` no se confunde con ningún dato válido (a diferencia de devolver `0` o `-1`); el `T&` es referencia de salida. En C++17 esto es exactamente lo que resuelve `std::optional<T>` (Sesión 26)
- [x] Pila: implementación con array — bloque plano `new T[cap]` (como la `Matriz` de la Fase 5) y `delete[]` en el destructor; **exige que `T` tenga constructor por defecto**, que es su limitación frente a `std::vector` (Sesión 26)
- [ ] Pila con lista enlazada — reutilizar `ListaEnlazadaSmart.cpp`: `insertarInicio` = `meter`, `eliminar` de cabeza = `sacar`, sin `tope` ni capacidad ni posibilidad de llenarse; con `unique_ptr` no hace falta destructor (explicado, falta implementarla)
- [x] `std::stack` — **COMPLETO (Sesión 27)**: es un **adaptador**, no un contenedor: `template <class T, class Container = deque<T>> class stack`. Solo delega `push/pop/top/empty` al contenedor de abajo. Se explicó por qué `deque` y no `vector` (ver abajo).
- [ ] Evaluación de expresiones aritméticas (infija → postfija y evaluación de postfija)
- [ ] Cola: concepto FIFO; implementación con array y con array circular
- [ ] Cola genérica con lista enlazada
- [ ] Bilares (doble entrada) y `std::deque`
- [ ] `std::queue`

### Ejercicios
- [x] `Pila<T>` genérica sobre array: `meter`, `sacar`, `cima` (dos versiones, no-const y const) + `imprimir` (Pila.cpp, Sesión 26)
- [ ] Balanceo de paréntesis con pila (esqueleto declarado, falta implementarlo)
- [ ] Convertir una expresión infija a postfija con pila
- [ ] Cola circular propia

### Checkpoint
- [x] ¿Por qué `sacar` devuelve `bool` + `T&` y no `T`? (aprobado: `false` no se confunde con ningún valor válido; `0` y `-1` sí se confundirían con datos reales) (Sesión 26)
- [ ] ¿Cuándo usar pila y cuándo cola?
- [ ] ¿Por qué una cola con array simple desperdicia espacio y la circular no?
- [x] ~~**Queda abierta:** `cima()` devuelve `T&`...~~ — **CERRADA en la Sesión 27** (ver abajo la sección completa). **Regla de oro resuelta:** una referencia es un **préstamo** — es válida mientras el dueño esté vivo y mientras nadie le cambie el significado. Tres condiciones: (1) el dueño sigue vivo, (2) el elemento sigue ahí y no se movió, (3) vos seguís significando lo mismo. Ver la sección 🔑 de la Sesión 27. Pendiente en M2: reto de paréntesis, infija→postfija, pila con lista enlazada (reutilizando `ListaEnlazadaSmart`) y todas las colas

**Estado:** En curso (Sesiones 26-27: `Pila<T>` sobre array validada, `std::stack` y la pregunta de la referencia colgante **cerradas**; faltan el reto de paréntesis, infija→postfija, la versión con lista enlazada y todas las colas)

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
- [x] Tabla de dispersión: definición y operaciones — **COMPLETO (Sesión 27)**: las tres piezas (arreglo de cubetas, función de dispersión, resolución de colisiones). `indice = hash(clave) % tamano`. Ganancia: O(1) en lugar de O(n)/O(log n).
- [x] Funciones de dispersión: aritmética modular, plegamiento, mitad del cuadrado, método de la multiplicación — **COMPLETO (Sesión 27)**: modular (la de la STL, FNV-1a en libstdc++), **plegamiento** (sumar códigos; se implementó en `HashEncadenado.cpp`), mitad del cuadrado (descartar bits altos, enumerar los bajos), multiplicación de Knuth (constante del número áureo, se queda con la parte fraccionaria).
- [x] Colisiones y su resolución — **COMPLETO (Sesión 27)**: **inevitables por el principio del palomar** (más claves que cubetas → alguna cubeta tiene 2+, da igual qué tan buena sea la función). Ocurren incluso con n ≤ m (en el demo, "Ana" y "María" caeron juntas en la cubeta 1 con 7 claves en 7 cubetas). Lo que hace la dispersión buena no es *evitarlas*, es hacerlas **raras y repartidas**.
- [x] Factor de carga α = claves / cubetas — **COMPLETO (Sesión 27)**: busca = O(1) llegar a la cubeta + O(α) recorrerla. La STL rehashea al pasar α de 1.
- [x] Direccionamiento enlazado (encadenado) — **COMPLETO (Sesión 27)**: cada cubeta es una `list<pair<K,V>>`. **La colisión no necesita trabajo extra**: el par se apila en la lista de su cubeta.
- [x] Direccionamiento abierto: exploración lineal, cuadrática y doble dirección dispersa — **COMPLETO (Sesión 27)**: todos los datos en un **solo vector plano**, sin punteros. Exploración lineal `(idx+1) % m`, cuadrática `(idx + i²) % m`, doble dispersión (otra función hash).
- [x] **Borrado perezoso / lápidas** (*lazy deletion* / *tombstones*) — **COMPLETO (Sesión 27)**: el bug central del módulo. Ver abajo la demo.
- [x] Relación con `std::unordered_map` — **COMPLETO (Sesión 27)**: `unordered_map` **es** esto. `Map.cpp` y `Frecuencias.cpp` (Sesión 19) son el mismo algoritmo con la libstdc++ escribiéndolo. `operator[]` crea la entrada si no existe, por eso para buscar se usa `find` (Sesión 19).

### Ejercicios
- [x] Tabla dispersa encadenada (listas por cubeta) — `HashEncadenado.cpp` (Sesión 27): `template <typename K, typename V>` con `vector<list<pair<K,V>>>`, `indice()`, `insertar` (con actualización in-place), `buscar` (`bool` + `V&`, mismo patrón que `Pila<T>::sacar` de la Sesión 26), `eliminar`, `factorCarga()`, `crecer()` y `imprimirEstructura()` (sin esto las colisiones son invisibles). **Sin destructor**: el `vector` es dueño de las listas y cada lista de sus pares — el argumento de la Sesión 25 aplicado a la STL. Verificado: 7 claves en 7 cubetas mostrando 3 colisiones, `crecer()` reenc/indexó todo (Ana de la cubeta 2 a la 9), actualización sin incrementar `cantidad`, valgrind 25 allocs/25 frees, 0 fugas, 0 errores.
- [x] Demo del fallo del borrado real en direccionamiento abierto — `HashTrampaBorrado.cpp` (Sesión 27): el bug intermitente demostrado en vivo (ver 🐛).
- [x] Comparación empírica encadenada vs abierta — `HashCache.cpp` (Sesión 27): 200 000 claves, 400 000 cubetas, α 0.5, misma dispersión. **Abierta 16x más rápida al insertar y 2.65x al consultar.**
- [ ] Implementar `TablaDispersa` con direccionamiento abierto — **reto asignado en la Sesión 27, pendiente de resolver por Juan.**

### Checkpoint
- [x] ¿Qué es una colisión y por qué ocurre? — **aprobado (Sesión 27)**: cuando dos claves distintas dan el mismo índice. Es **inevitable** por el principio del palomar, no un defecto de la función.
- [x] ¿Cuándo conviene direccionamiento abierto y cuándo enlazado? — **aprobado (Sesión 27)**, con matiz importante: Juan confundió "cuál tolera mejor" con "cuál se degrada más rápido" (son **opuestas**). Ver tabla de abajo.
- [x] ¿Qué necesita el abierto que el encadenado no? — **aprobado (Sesión 27)**: la **lápida**. La encadenada no tiene este problema **porque no tiene cadena que romper**; al borrar de la lista, el invariante no se altera.
- [x] ¿Por qué la diferencia entre ambas es "la constante escondida" y no la complejidad? — **aprobado (Sesión 27)**: las dos son O(1); lo que cambia es el número de `new` y los *cache misses* (demostrado con `HashCache.cpp`).

**Estado:** 🟡 Por validar — contenido completo y checkpoints aprobados; falta el **reto de implementación** con direccionamiento abierto (exploración lineal + 3 estados + rehash de lápidas).

### 📊 Tabla resumen encadenada vs abierta (Sesión 27)

| | **Encadenada** | **Abierta** |
|---|---|---|
| Representación | `vector<list<pair<K,V>>>` | un `vector<Slot>` plano |
| Punteros | sí (nodos enlazados) | **ninguno** |
| Colisión | se apila en la lista | se rueda a la siguiente casilla |
| Insertar | crea un nodo (`new` interno) | escribe en el arreglo |
| Velocidad real | 7.08 ms insertar / 104.9 ms consultar | **0.44 ms / 39.6 ms** (16x / 2.65x) |
| α tolerable | hasta ~1.0 | **≤ 0.7** |
| Tolera mala dispersión | **mejor** (el daño queda en una cubeta) | peor (cadenas largas bloquean casillas) |
| Borrar | trivial (`erase` de la lista) | **rompe la cadena → necesita lápida** |
| Slogan | tolerante y más lenta | rápida y delicada |

> **Lección de fondo (Sesión 27):** la diferencia real entre estructuras de datos casi nunca es O(1) contra O(n) — es **la misma complejidad con distinta constante**, y la constante la deciden la memoria, los `new` y la caché. Cuando pregunten "¿cuál es mejor?", la respuesta buena es *"depende del patrón"*, respaldada con números.

### 🐛 El bug del módulo: el borrado real rompe la cadena (Sesión 27)

> **Invariante de la exploración lineal:** *toda búsqueda para en la PRIMERA casilla vacía.*

La razón: si una casilla está vacía, es porque nadie la *"ocupó"* al colisionar. Si alguien hubiera colisionado ahí, la habría tomado; entonces las casillas siguientes no pueden pertenecer a la misma cubeta de origen. **Siempre que no haya habido un borrado.**

Al **borrar de verdad** se crea un hueco en medio de la cadena y el invariante se rompe: la búsqueda para en el hueco y **nunca alcanza** lo que estaba después. El dato no se pierde — **la tabla miente**, que es peor, porque el programa cree que no existe.

Caso del ejercicio: `Ana`(2) `Luis`(3) `Zoe`(4), se borra `Luis` → `buscar("Zoe")` arranca en la cubeta 4, **encuentra la casilla 3 vacía, para, y da falso negativo**.

Y lo peor — el bug es **intermitente**: al insertar `23` (también colisiona en 2), se instala en el hueco del 21, la cadena vuelve a quedar continua y `buscar("Zoe")` **vuelve a funcionar**. Mismo programa, mismos datos, resultado distinto. Depende del orden de llegada.

**Solución (por eso existe el borrado perezoso):** el borrado real **no puede existir** — no es pereza de implementación, es geometría: al vaciar la casilla 3, la información de "en la 4 hay un 22 que venía de la cubeta 2" **ya se destruyó** y no hay algoritmo de búsqueda que lo recupere. La STL marca un **tercer estado**:

| Estado | Significa | ¿La búsqueda sigue? | ¿Ocupa casilla? |
|---|---|---|---|
| `VACIA` | nunca hubo nada | **NO — para** | no |
| `LAPIDA` | hubo algo, se borró | **SÍ — sigue** | sí, a efectos de búsqueda |
| `OCUPADA` | hay dato | sí | sí |

**Costo oculto:** las lápidas ocupan casilla para la búsqueda pero no cuentan como datos. Si se borra e inserta mucho, la tabla se llena de lápidas y buscar se vuelve O(n) **sin que el factor de carga lo anuncie**. Por eso `crecer()` debe contar también las lápidas, y en el rehash **se descartan** (allí sí se "vacían", porque se redibuja todo desde cero).

> **Puente a los árboles (Sesión 27):** este es el mismo drama del `erase` de un BST. *Cuando una estructura depende de que "lo de atrás está unido a lo de adelante", el borrado se vuelve el punto delicado.*

## Módulo 5 — Árboles binarios y BST (Cap. 16)

### Conceptos
- [x] Árboles: terminología (raíz, hojas, altura, grado)
- [x] Árbol binario: equilibrio, árbol completo
- [x] Representación de un nodo y creación de un árbol
- [ ] Árbol de expresión
- [x] Recorridos: preorden, enorden, postorden
- [x] Árbol binario de búsqueda (BST): búsqueda, inserción, borrado
- [x] Diseño recursivo de un árbol de búsqueda

### Ejercicios
- [ ] BST implementada con smart pointers
- [x] Mostrar los tres recorridos
- [ ] Evaluar un árbol de expresión

### Checkpoint
- [x] ¿Por qué el BST se degenera en el peor caso?
- [x] Complejidad prometida por `std::map`

**Estado:** 🟡 Contenido ✅, falta árbol de expresión (queda en M7) y BST con smart pointers

**Ver también:** `ArbolHeap.cpp` cubre el árbol completo (que estaba en la lista de este módulo).

## Módulo 6 — Árboles equilibrados y árboles B (Cap. 17)

### Conceptos
- [x] Eficiencia de búsqueda en un árbol ordenado
- [x] Árbol AVL: altura, factor de equilibrio
- [x] Rotaciones: simple y doble
- [x] Inserción con balanceo
- [ ] Árboles B: definición, TAD y representación de página
- [ ] Formación de un árbol B (orden m), búsqueda e inserción

### Ejercicios
- [x] AVL con rotaciones simples y dobles (`ArbolAVL.cpp`, escrito por Juan)
- [ ] Búsqueda e inserción en un árbol B

### Checkpoint
- [x] ¿Qué garantiza un AVL que un BST simple no? (altura O(log n) garantizada vs O(n) degenerado)
- [ ] ¿Por qué los árboles B se usan en bases de datos y sistemas de archivos?

**Estado:** 🟡 AVL ✅ completo, falta árbol B

**Ver también:** `ArbolHeap.cpp` cubre el montículo (M3 de la Fase 6, adelantado aquí por ser árboles).

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

# 🔑 SESIÓN 27 — LA REFERENCIA COLGANTE (cerró la pregunta de la Sesión 26)

> Pregunta abierta desde la Sesión 26: *`cima()` devuelve `T&` al interior del array, así que la referencia puede quedar colgando. ¿Qué garantiza `std::stack::top()` y bajo qué regla el retorno por referencia es seguro?*

## La intuición de Juan y dónde falla

Juan: *"al ser una referencia nos asegura que apuntará a una dirección de memoria real, es decir, que no se quedará colgando"*. **Es medio cierta, y la parte cierta es valiosa:** una referencia no puede ser nula ni no inicializada (`int& r;` no compila, `int& r = 30;` no compila). Eso la hace **mejor que un puntero crudo**.

Lo que falta: **la referencia garantiza la DIRECCIÓN, no la VIDA**. Es un apodo, y el apodo no tiene ni idea de los planes del objeto. Analogía: la dirección de una casa escrita en un papelito. Si la demuelen, el papelito sigue diciendo la misma dirección y vos seguís creyendo que tenés casa.

## Son TRES estados, no dos (el punto nuevo de la sesión)

| Estado | Dirección | Qué pasa | ¿Se queja? |
|---|---|---|---|
| 1. Objeto vivo | válida | todo bien | — |
| 2. **Objeto muerto, memoria viva** | válida | el dato cambió o el objeto renació | **NO** ← el peor |
| 3. Memoria liberada (`delete[]`) | liberada | UAF de verdad | sí, valgrind lo ve |

El **estado 2 es el que no existía en el modelo mental de Juan, y es el peor de los tres** porque el programa deja seguir como si nada. Demostrado en `RefColgante.cpp` con `std::string`: el string viejo **murió** en su `~string()` y nació otro en la misma dirección; el alias sigue apuntando ahí y no se entera. *Un cadáver con el mismo DNI.*

> **Con `int` no se nota:** un `int` no tiene destructor, así que "morir" es solo cambiar de valor. **`std::string` sí tiene destructor**, y ahí sí hay un objeto que muere de verdad. **Los tipos con destructor son los que matan.**

## `std::stack`: por qué `deque` y no `vector` (StackRef.cpp)

Juan respondería bien el "reubica y cuelga" pero mezcló los dos problemas. La distinción clave:

| | Qué es | ¿Pasa con `deque`? | Gravedad |
|---|---|---|---|
| **(1)** | La referencia **se cuelga** (memoria liberada) | **no**, `deque` nunca reubica | *undefined behavior* |
| **(2)** | La referencia **ya no apunta a la cima** (sigue válida pero cambió de significado) | **sí, en los dos** | no es bug, es sentido |

**(1) es la razón del `deque`.** La garantía textual de la STL: *"las referencias a elementos siguen siendo válidas al hacer push y pop"*. `deque` cumple porque **nunca mueve lo que ya está**: al necesitar más espacio agrega un bloque nuevo y deja los viejos intactos. `vector` copia a un bloque nuevo y **libera el viejo** → cualquier referencia queda apuntando a la nada. Medido: `vector` → `r = -192796850` + *Invalid read of size 4*; `deque` → `r = 999`, intacta.

**(2) no se arregla con nada:** "la cima" no es un objeto, es una **posición que se mueve**. Por eso el patrón de uso de una pila es `top()` → leer → `pop()`, y nunca `int& r = s.top(); ... s.push(x); ... usar r`.

## 📜 La regla de oro (Sesión 27)

Devolver `T&` al interior de un contenedor es seguro si y **solo si**:

1. **El dueño sigue vivo** — el contenedor no se destruye, ni se copia/mueve de forma que invalide.
2. **El elemento sigue ahí y no se movió** — no lo borraron, no lo sobreescribieron, y si el contenedor reubica, no hubo operación que disparara la reubicación.
3. **Y vos seguís significando lo mismo** — el elemento no cambió de rol (el caso C).

> **En una frase: una referencia es un PRÉSTAMO.** Es válida mientras el dueño esté vivo y mientras nadie le cambie el significado. Lo que **no** garantiza es que el dueño no se muera — de eso te hacés cargo vos.

**Demostración de que la #2 es necesaria (`RefColgante.cpp`):**
```cpp
Pila<int> p(5);  p.meter(1); p.meter(2); p.meter(3);
int& r = p.cima();      // r apunta a datos[2]
// p se destruye -> ~Pila() -> delete[] datos
std::cout << r;         // -1401685260 : LECTURA DE MEMORIA LIBERADA
// valgrind: Invalid read of size 4, 8 bytes inside a block of size 20 free'd
```

**Patrón de la STL:** `T& t = p.cima();` es segura dentro del bloque porque el prvalue **se materializa** (hace una copia que vive hasta el final del bloque). `auto&& t = p.cima();` es **alias puro** y se cuelga. **Una palabra de diferencia** — misma familia que la trampa de la Sesión 25.

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
| 23 | 2026-09-25 | Fase 9 M1 (Cap. 10): **lista circular** (ListaCircular.cpp). Juan la implementó siguiendo el esqueleto de la clase `Lista` del libro: `insertarFinal`, `insertarInicio`, `buscar`, `eliminar` e `imprimir` (con el cierre del ciclo `-> cabeza` al final). Puntos que se resolvieron: (1) el bucle de búsqueda de una lista circular **no puede ser `while(actual != nullptr)`** porque nunca es nullptr — hay que terminar con `do...while(actual != cabeza)`; (2) el nodo único se apunta a sí mismo; (3) el recorrido para insertar al inicio arranca en la cabeza, no en la cola. `this->` explícito en el puente C→C++ (el `this` de C es un parámetro; en C++ es implícito) y `nuevo = cabeza` como reasignación de puntero local (no toca el miembro de la lista). Destructor RAII con recorrido y `delete`. `ListaCircular(const ListaCircular&) = delete` con explicación de por qué no basta `= delete` en la copia (si no, el `delete this` apunta a memoria ajena). Verificado: `insertarFinal`, `insertarInicio`, `buscar`, `eliminar` (cabeza / intermedio / cola / nodo único) e imprimir; valgrind 7 allocs/7 frees, 0 fugas, 0 errores. Checkpoint 2/2: por qué `buscar` es O(n) y por qué `eliminar` de la cabeza **no** puede ser O(1) sin puntero `cola` (al borrar la cabeza, la nueva cabeza es el *siguiente*, y la nueva cola es... el mismo nodo) | ✅ Completado |
| 24 | 2026-09-25 | Fase 9 M1 (Cap. 10): **optimización de la lista circular con puntero `cola`**. Se agregó `Nodo* cola` a `ListaCircular` para eliminar el recorrido O(n) al buscar el último nodo. Juan identificó por su cuenta la razón de por qué borrar la cola sigue siendo O(n) (se necesita el nodo anterior para reconectar a la cabeza, y en una lista simple no se puede caminar hacia atrás) — que es justamente la razón de ser de la lista doble. `insertarFinal` e `insertarInicio` quedaron O(1); `eliminar` de la cola actualiza `cola = anterior` **con condición** (`if(anterior->siguiente == cabeza)`) para no romper el caso intermedio. Complejidades: circular+cola = O(1)/O(1)/O(1)/O(n) vs doble = O(1) en los cuatro casos. Verificado con un test que borra la cola y luego inserta al final (el escenario donde un `cola` desactualizado amputaba la lista: `0 -> 1 -> 2 -> 3 -> 0` + insertarFinal(4) daba `0 -> 4 -> 0` y 3 fugas). Compilación limpia; valgrind 7 allocs/7 frees, 0 fugas, 0 errores. Pendiente opcional: reemplazar el `while` de buscar-la-cola en `eliminar` de cabeza por `cola->siguiente = cabeza` para que sea O(1). | Completado |
| 25 | 2026-09-25 | **Fase 7 express (plantillas) + cierre del smart pointer en listas**, arranque por delegación de Juan ("ya lo demás lo haces tú"). (1) `Plantilla.cpp`: función `minimo<T>` con `int`, `double` y `std::string`; se detectó la trampa de la deducción: `minimo("Ana","Zoe")` deduce `T = const char*` y el `<` pasa a comparar **direcciones**, no letras (mismo resultado para ambos órdenes) mientras que con `std::string` da el alfabético → "las plantillas hacen lo que les das". (2) `PlantillaCircular.cpp`: Juan convirtió la lista circular en `template <typename T>` por su cuenta (bien: los dos `template`, `T dato`, `Nodo<T>* cabeza/cola`, `insertarFinal(T)`); el compilador le marcó `missing template argument list after 'Nodo'` y el tutor completó lo que faltaba (7 sitios: ctor `Nodo(T)`, parámetros, 17 punteros locales `Nodo<T>*`, 6 `new Nodo<T>`, `= delete` con `<T>`), más `<string>` y un bloque de prueba con `ListaCircular<std::string>` (Miguel/Ana/Zoe). valgrind 10 allocs/10 frees, 0 fugas, 0 errores → **el mismo molde sirve para `int` y para texto sin tocar una línea de la lógica**. (3) `ListaEnlazadaSmart.cpp`: la `ListaEnlazada` convertida a `std::unique_ptr` (`cabeza` y `Nodo<T>::siguiente` como dueños) + `make_unique` y `std::move`. Desaparecen el destructor (14 líneas) y los `= delete` (el `unique_ptr` no es copiable); `insertarInicio` cabe en 2 líneas; borrar la cabeza es `cabeza = std::move(cabeza->siguiente)`. Probada con `int` y `std::string`; valgrind 12 allocs/12 frees, 0 fugas, 0 errores. (4) **Hallazgo de diseño**: `unique_ptr` + lista circular = **ciclo de propiedad** (el último es dueño de la cabeza y la cabeza es dueña del último por la cadena) → fuga garantizada y recursión infinita al destruir; por eso el último enlace debe ser no-dueño. Explica por qué `std::list` de la STL **no** es circular. Plantillas M1 marcadas ✅ (express). Pendiente para M1: el **iterador propio** (`begin()`/`end()`) y el checkpoint lista vs `std::vector`. Decisión de Juan: seguir a **pilas** (Fase 9 M2, Cap. 11) dejando el iterador para después | ✅ Completado |
| 26 | 2026-09-26 | Fase 9 M2 (Cap. 11): **pilas**. Concepto LIFO y por qué existe: la evaluación de expresiones en postfija (RPN) es el problema que hizo nacer la estructura (`2 + 3 * 4` → `2 3 4 * +`, sin regla de precedencia). Checkpoint previo aprobado por Juan: sin subir el `tope` se sobrescribe la misma casilla y la pila queda mintiendo (`tamano()` en 0) **sin error ni fuga detectable** → se instaló el modelo mental "la pila no es el array, la pila es el `tope`". Segundo checkpoint aprobado: `sacar` devuelve `bool` + `T&` y no `T` porque `false` no se confunde con ningún dato válido (con `0` o `-1` no se podría distinguir "estaba vacía" de "había un 0"). `Pila.cpp` (plantilla `Pila<T>` sobre bloque plano `new T[cap]`, al estilo de la `Matriz` de la Fase 5): Juan implementó `meter` y `sacar` correctamente respetando el invariante (escribir en `datos[tope + 1]` **después** de subir el `tope`) y acertó usar `tope + 1 == capacidad` en vez de `tamano() == capacidadMaxima()` (lee la variable directo, no se puede desincronizar). El tutor corrigió: (1) 🐛 `cima()` con la condición al revés devolvía `datos[-1]` → índice negativo fuera del bloque, *undefined behavior* silencioso; (2) `return;` sin valor en la versión `const` de `cima()` (lo cazó el compilador: `return-statement with no value`); (3) código muerto (`if/else` con return en ambos lados + return de relleno) → convención STL: caso raro sale temprano, caso normal es el camino recto; (4) `datos[tamano()]` duplicaba el invariante → `datos[tope + 1]`. Verificado: llenar 5, `meter` en pila llena devuelve `false`, LIFO puro al sacar (5 4 3 2 1), `sacar` de vacía devuelve `false` sin tocar `valor`, y **la misma plantilla con `std::string`**; compilación limpia y valgrind 4 allocs/4 frees, 0 fugas, 0 errores. Quedó planteada y **sin responder** la pregunta de cierre: `cima()` devuelve `T&` al elemento del array, así que la referencia puede quedar colgando si la pila se vacía o se recicla (misma trampa de la Sesión 20 con otro disfraz) y bajo qué regla es seguro. Pendiente en M2: reto de paréntesis, `std::stack`, infija→postfija, pila con lista enlazada (reutilizando `ListaEnlazadaSmart`) y las colas | ✅ Completado |
| 27 | 2026-09-29 | **Fase 9 M4 (Cap. 14 — Tablas de dispersión). Juan pidió estudiar hash + árboles + grafos; se acordó **un módulo por sesión**, así que hoy M4 completo y árboles/grafos quedan agendados.** Concepto: cubetas + función de dispersión + resolución de colisiones; las 4 funciones clásicas (modular, plegamiento, mitad del cuadrado, multiplicación de Knuth); colisiones **inevitables por el principio del palomar**; factor de carga α y su relación con el rehash. `HashEncadenado.cpp` (tutor): tabla encadenada con `vector<list<pair<K,V>>>`, **sin destructor** (RAII de la STL), `buscar` con el patrón `bool`+`V&` de la Sesión 26, y `crecer()` que reenc/indexó todo (Ana de la cubeta 2 a la 9 — se ve por qué el rehash es O(n)). Verificado: 25 allocs/25 frees, 0 fugas, 0 errores. 🐛 warning `-Wrange-loop-construct` en `for (const string& n : {"Ana","Sara",...})`: es el `initializer_list<const char*>` de la Sesión 25 otra vez (se construye un `string` temporal cada vuelta); corregido a `const char*`. **Puntos donde Juan acertó y se le corrigió el porqué:** P1 (Ana en 2, Luis se rueda a la 3) ✅; P2 (Zoe a la 4, y si se llena se duplica) ✅ con el matiz de α ≤ 0.7 en abierto; **P3 (el borrado rompe la cadena) ✅ en la conclusión pero el mecanismo quedó enredado** → se aterrizó con el invariante "toda búsqueda para en la PRIMERA casilla vacía" y una demo de 40 líneas (`HashTrampaBorrado.cpp`) donde el bug se ve correr. **Hallazgo de la sesión: el bug es INTERMITENTE** — tras borrar `Luis` la 3 queda vacía y `buscar("Zoe")` da falso negativo, pero al insertar `23` (que también colisiona) se tapa el hueco, la cadena queda continua y la búsqueda **vuelve a funcionar**: mismo programa, mismos datos, resultado distinto. Esa es la clase de bug más difícil de cazar en producción. `HashCache.cpp` (tutor): 200 000 claves, α 0.5, misma dispersión → **la abierta es 16x más rápida al insertar y 2.65x al consultar**, aunque las dos son O(1). Se explicaron las dos causas distintas: 16x es **menos `new`** (la encadenada reserva memoria del SO por cada clave) y 2.65x es **caché** (la encadenada salta entre direcciones del heap → *cache miss* ~100 ns; la abierta lee memoria contigua con *prefetch* gratis). Checkpoint "cuándo abierto y cuándo encadenado" aprobado **con corrección de fondo: Juan confundió "cuál tolera mejor" con "cuál se degrada más rápido"** (son preguntas opuestas: la encadenada tolera mejor, la abierta se degrada más rápido). Se aclará: la diferencia real entre estructuras casi nunca es O(1) vs O(n) sino **la misma complejidad con distinta constante**, y la respuesta buena a "¿cuál es mejor?" es "depende del patrón". **Pendiente:** reto de implementar `HashAbierto.cpp` (exploración lineal, 3 estados con lápida, rehash que descarte las lápidas) + la pregunta abierta de la Sesión 26 (referencia colgante en `cima()`). **Juan decidió parar y seguir después** (el borrado perezoso se entiende mejor descansado), pero antes resolvió la **pregunta abierta de la Sesión 26** (referencia colgante en `cima()`). (`RefColgante.cpp`, `StackRef.cpp`). Sus respuestas: la intuición "una referencia asegura una dirección real" es **medio cierta y la parte certa es valiosa** (no puede ser nula, mejor que un puntero crudo) pero le falta el concepto clave: **la referencia garantiza la DIRECCIÓN, no la VIDA** — es un apodo, y el apodo no sabe cuándo muere lo apuntado. Se instaló el modelo de **tres estados** (vivo / **objeto muerto con memoria viva** / memoria liberada), siendo el segundo el peor porque el programa no se queja: demostrado con `std::string`, donde el string viejo **muere** en su destructor y nace otro en la misma dirección ("un cadáver con el mismo DNI"). Se explicó por qué los **tipos con destructor son los que matan** (con `int` no se nota porque no tiene destructor). Sobre `std::stack`: respondió bien "`push_back` reubica y cuelga" pero **mezcló dos problemas distintos** — (1) la referencia se cuelga (memoria liberada) y (2) la referencia ya no apunta a la cima (sigue válida pero cambió de sentido). El (1) es la razón real del `deque` (garantía textual: *las referencias siguen válidas al hacer push/pop*; `deque` nunca reubica lo que ya está, `vector` copia y libera el bloque viejo). El (2) **no se arregla con nada** ("la cima" no es un objeto, es una posición que se mueve) y es la razón del patrón `top()` → leer → `pop()`. **Regla de oro entregada y anotada:** devolver `T&` al interior de un contenedor es seguro si y solo si (1) el dueño sigue vivo, (2) el elemento sigue ahí y no se movió, (3) vos seguís significando lo mismo. *Una referencia es un préstamo.* **El tutor se comió dos bugs propios en las demos y ambos quedaron como lección:** (a) escribió `int r; r = cimaDe(p);` creyendo que era una referencia cuando **copiaba el valor** — detectado porque valgrind daba 0 errores donde esperaba un UAF, y confirmado desensamblando (`movl %eax, -36(%rbp)` es una copia); el **tipo lo decide la declaración, no el origen del valor**; (b) una tanda de `meter` devolvieron `false` (pila llena) y no se escuchó el aviso, así que `datos[2]` nunca se sobreescribió y la demo mintió. También se vio que que la capacidad de `std::vector` **duplica 1→2→4→8**, no de 3 en 3, así que un cuarto `push` con 3 elementos NO reubica (había que llenar la capacidad y meter uno más), y que un `delete` de más es un doble free (5 errores en vez de 1). **Pendientes:** reto `HashAbierto.cpp`; reto de paréntesis, infija→postfija y colas de M2; y **Sesión 28: árboles (M5, BST)**. | 🟡 Por validar |
| 28 | 2026-09-29 | **Fase 9 M5 + M6 + montículos: árboles completos en una sola sesión.** Tres estructuras escritas por Juan de punta a punta. **Método de la sesión (cambio de ritmo pedido por él):** de "el tutor escribe el ejemplo y Juan hace el reto" a **"el tutor explica la idea en español normal, Juan escribe el código, y después el tutor pregunta para verificar"**. Resultado: los tres árboles salieron de Juan, no del tutor. **HALLAZGO IMPORTANTE DEL DÍA: el profe ya tenía los ejemplos en `Arboles y Grafos/arboles/` (9 archivos de árboles + 11 de grafos, con LEEME.md y orden sugerido).** El tutor se había inventionado `ArbolBST.cpp` y `ArbolBSTCrudo.cpp` con `unique_ptr` cuando ya existía `02_arbol_busqueda.cpp` con punteros crudos — exactamente el lenguaje que Juan ya dominaba. **Lección de método: antes de fabricar un ejemplo, revisar qué material hay en la carpeta del curso.** Se borraron los dos archivos inventados. **1) BST (`ArbolBST.cpp`):** Juan escribió `insertar`, `minimo`, `inorden`, `buscar`, `borrar` (los 3 casos), `mostrarArbol` y `destruir`. **Revisión: 3 bugs.** (a) En `borrar`, las ramas recursivas sin `=` (`borrar(raiz->izq, valor);`) → el `delete` ocurría pero el padre quedaba apuntando a memoria liberada: 15 errores de valgrind, doble `delete` en `destruir`, valores basura en pantalla. (b) En `borrar`, **error espejo** `raiz->der = borrar(raiz->izq, valor)` — consulta izq, escribe der: compila limpio y da un árbol plausible pero incorrecto. (c) `buscar` sin `return` en las ramas recursivas → siempre devolvía `false`. Además el `main` probaba `borrar(raiz, 30)` con datos `{70,5,50,10,40,65,20}` donde **no hay 30**, y `borrar(raiz,50)`-rotado "es la raíz" cuando la raíz era 70 (el caso 3 —el importante— no se probaba). **Juan resolvió solo (c)** y el (a) se lo corrigió el tutor. **2) AVL (`ArbolAVL.cpp`):** escrito bloque por bloque con el tutor guiando. (a) `CrearNodo` sin el `new` (escribía en un puntero no inicializado) y `actualizarAltura` con `nodo->izq->altura` directo en vez de `altura(nodo->izq)` → *Invalid read* en las hojas. (b) `rotarDerecha`: `nodo->der = nodo` (nodo hijo de sí mismo) + `nodo->izq = hijo` invertido (el nieto nunca se usaba — lo delató el warning `-Wunused-variable`). (c) `rotarIzquierda`: `hijo->der = nieto` en vez de `nodo->der = nieto` → nieto colgado del lado equivocado. (d) `insertar`: **los `return` faltaban en las 2 rotaciones simples** → los nodos quedaban vivos pero huérfanos (el inorden imprimía `10` solo de 3 nodos). **Juan acertó las 3 preguntas predictivas** antes de codificar las rotaciones (a quién se rota, qué sube, por qué se guarda al nieto) y **el orden de `actualizarAltura` (abajo primero) sin que se lo pidieran**. **3) Heap (`ArbolHeap.cpp`):** Juan copió el archivo del profe y pidió que se lo explicaran en vez de reescribirlo — cambio de método válido. Acertó las 5 preguntas de verificación al 100%: (1) sin `i = padre` es bucle infinito, (2) guardar `maximo` antes de sobrescribir la raíz, (3) el último es el más chico y por eso hay que bajarlo, (4) heap vacío → -1, (5) el `if (izq < cantidad)` evita leer `heap[1]` inexistente. **Validado con pruebas extra:** heap de 1 elemento, extracción sobre vacío, y heapsort de 15 números aleatorios → ordenado de mayor a menor. **Los 5 bugs del día fueron la MISMA clase de error:** "una función que devuelve algo tiene que devolverlo en todos los caminos" — apareció 4 veces (buscar, borrar, rotarIzquierda, insertar AVL) y a la 4a Juan ya la reconoció solo. **Decisión de Juan que vale registrar:** dijo que el `unique_ptr` le parecía "muy complicado" y que el ejemplo del profe con punteros crudos era más fácil — **tenía razón**, y se le explicó el trueque: el crudo cobra en la línea de inserción (se lee en una línea) y paga en el destructor (6 líneas que no escribís) y en el `= delete` (2 líneas que no escribís). Se offered hacer el doble ejercicio pero Juan prefirió seguir con el material del profe. **Pendientes:** árbol B (M6), árbol de expresión (M5), `HashAbierto.cpp`, retos de M2, y **`grafos` (M7) — que es lo siguiente**. El heap seindsight quedó listo justo a tiempo: es lo que necesitan Dijkstra y Kruskal. | 🟢 Tres estructuras completas |
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
- [x] Lista circular — buscar la cola con `do { ultimo = ultimo->siguiente; } while(ultimo != cabeza)` termina en la **cabeza**, no en la cola → el nodo nuevo se inserta justo tras la cabeza y el resto de la lista queda **huérfano** (pérdida silenciosa: no crashea, no da warning, solo se pierden datos; se detectó porque `buscar(2)` daba false). Condición correcta: `while(ultimo->siguiente != cabeza)`. Distinción clave: para **visitar** todos se para al llegar a la cabeza; para **encontrar la cola** se para cuando el nodo actual ya apunta a la cabeza (Sesión 23).
- [x] Lista circular — `while(actual != nullptr)` NO termina nunca: en una circular no existe `nullptr`; el centinela es `cabeza` (igual que en el `for`/`while` hay que cambiar la condición, no solo el cuerpo). Con orden `actual != cabeza && actual->dato != valor` (corto-circuito) (Sesión 23).
- [x] Lista circular — `cabeza = cabeza->siguiente; delete cabeza;` **borra la nueva cabeza** y fuga la vieja. Orden correcto: guardar `aBorrar = cabeza` → mover la cabeza → reconectar → `delete aBorrar` (Sesión 23).
- [x] Lista circular — al borrar la cabeza hay que reconectar el **último nodo** a la nueva cabeza (`ultimo->siguiente = cabeza`), si no queda apuntando al nodo liberado. Y en el caso de nodo único, `cabeza` debe quedar en `nullptr` (Sesión 23).
- [x] `nuevo = cabeza` NO modifica la lista: solo reasigna la variable local. Para cambiar la lista hay que escribir en un `->siguiente` (`nuevo->siguiente = cabeza`). Patrón repetido: appeared 3 veces antes de corregirlo (Sesión 23).
- [x] Lista circular — destructor con `cabeza` como caminante Y como referencia de parada: al hacer `cabeza = temp` la referencia se mueve con el caminante, `temp != cabeza` siempre es falso y para tras borrar 1 nodo (3 fugas en valgrind). El caminante debe ser una variable local (`actual`) y `cabeza` queda quieta como punto de retorno. Además el `do...while` necesita guarda de lista vacía (si no, crash) y el último chequeo no borra nada: en n nodos hay n borrados y n+1 comparaciones (Sesión 23).
- [x] Puntero `cola` mal actualizado: asignarle un nodo que no es la cola rompe el invariante `cola->siguiente == cabeza` y las siguientes inserciones amputan la lista (pérdida silenciosa). Regla: **`cola` solo cambia en cuatro situaciones**: (1) inserción al final, (2) inserción en lista vacía, (3) borrado de la cola, (4) borrado del único nodo (allí cabeza y cola van ambos a `nullptr`). Insertar al inicio NO cambia la cola. Y al borrar la cola, la actualización va **con condición** (`if(anterior->siguiente == cabeza) cola = anterior;`), porque en el caso intermedio la cola no cambia (Sesión 24).
- [x] Decidir sobre un nodo DESPUÉS de `delete`: si después de borrar se lee `actual->siguiente` (o cualquier miembro) para preguntar algo, es *use-after-free*. Todas las decisiones que dependan del nodo a borrar se toman **antes** del `delete` (misma lección del destructor en Sesión 20) (Sesión 24).
- [x] Plantilla: pasar un literal de texto a un parámetro `T` → se deduce `T = const char*` (decaimiento arreglo-a-puntero), NO `std::string`. El `<` pasa a comparar **direcciones de memoria**: `minimo("Ana","Zoe")` y `minimo("Zoe","Ana")` dan el mismo resultado (dirección), mientras que con `std::string` da el alfabético. Las plantillas hacen exactamente lo que les das: si el tipo deducido no es el esperado, el error está aguas arriba (Sesión 25).
- [x] Dentro de una clase plantilla hay que escribir `Nodo<T>*`, no `Nodo*`: error `missing template argument list after 'Nodo'`. Y `T` debe aparecer en **todos** los lugares: miembro de dato, parámetros de los métodos, tipo del nodo (`Nodo<T>`) y la declaración del objeto (`ListaCircular<int>`). Olvidar uno = el mismo bug de "invarianté sin actualizar" (Sesión 25).
- [x] `unique_ptr` + lista **circular** = ciclo de propiedad: el último nodo es dueño de la cabeza y la cabeza es dueña (por la cadena) del último → nadie suelta a nadie, fuga garantizada y recursión infinita al destruir. Por eso el último enlace tiene que ser un puntero **no dueño** (crudo), o se rompe el ciclo a mano. Esto explica por qué `std::list` de la STL **no** es circular (Sesión 25).
- [x] 🐛 `cima()` con la condición **al revés** en la pila sobre array: `if(estaVacia()){ return datos[tope]; }` devolvía `datos[-1]`, índice **negativo y fuera del bloque reservado** → *undefined behavior* silencioso (en el mejor caso basura; en el peor, memoria de otro objeto y el programa falla tres líneas después sin relación aparente). Lección doble: (1) `datos[tope]` solo es válido si `tope >= 0`, o sea **la condición del `if` tiene que ser la del caso raro**; (2) un índice negativo en C++ no avisa, no dispara alarma, `valgrind` lo reporta como *Invalid read* si lo detecta y a veces ni eso (Sesión 26).
- [x] 🐛 `return;` sin valor dentro de una función que promete `const T&` → el compilador lo caza con `error: return-statement with no value, in function returning 'const T&'`. Ojo: en C el mismo error **no lo caza nadie** y el programa sigue con basura como retorno (Sesión 26).
- [x] 🐛 Código muerto: `if/else` con `return` en **ambos** lados y un `return` de relleno después. No rompía nada, pero es el tipo de línea que alguien borra "porque está de más" y se lleva por delante el `return true` de al lado. Convención del libro y de la STL: **el caso raro sale temprano (`if` + `return`), el caso normal es el camino recto** (Sesión 26).
- [x] 🐛 Escribir el invariante dos veces: `datos[tamano()]` es literalmente `datos[tope + 1]`, porque `tamano()` **es** `tope + 1`. Si mañana cambia el significado de `tope`, `meter` se entera por el compilador pero `tamano()` no. Usar la variable directa (`datos[tope + 1]`, `tope == capacidad - 1`) deja el invariante en **un solo lugar** (Sesión 26).
- [x] Acierto de Juan: en el chequeo de pila llena usó `tope + 1 == capacidad` en vez de `tamano() == capacidadMaxima()`; la primera lee la variable directamente y **no puede desincronizarse** del `tope`. Es el mismo criterio que aplicó solo en `sacar` con `estaVacia()`. Menos indirección = menos formas de meter la pata (Sesión 26).
- [x] 🐛 `for (const string& n : {"Ana", "Sara", ...})` → el `initializer_list` es de **`const char*`**, no de `string`; se construye un `std::string` **temporal en cada vuelta** y `g++` lo avisa con `-Wrange-loop-construct`. Es la Sesión 25 (deducción de `T` = `const char*`) disfrazada de otra cosa. Ojo: **funciona bien igual**, por eso el warning hay que leerlo y no ignorarlo (Sesión 27, HashEncadenado.cpp)
- [x] 🐛 `setw` / `setprecision` no vienen en `<iostream>`: requieren **`<iomanip>`**. `error: 'setw' was not declared in this scope` (Sesión 27, HashCache.cpp)
- [x] 🐛 **Borrado real en direccionamiento abierto rompe la cadena.** El invariante es *"toda búsqueda para en la PRIMERA casilla vacía"*, y vaciar una casilla en medio de una cadena lo destruye: lo que estaba después **se vuelve inalcanzable** y la tabla **miente** (falso negativo), que es peor que perder el dato. Y el fallo es **intermitente**: depende del orden de inserción, así que insertar una clave que tapó el hueco lo "arregla" sin que nadie toque el bug. No hay algoritmo de búsqueda que lo solucione — la información se destruye al vaciar. Por eso existe el **borrado perezoso** (estado `LAPIDA`): la casilla sigue ocupada para la búsqueda, así que la cadena no se rompe (Sesión 27, HashTrampaBorrado.cpp)
- [x] Pregunta trampa en exams y en parciales: **"¿cuál tolera mejor X?" y "¿cuál se degrada más rápido?" son preguntas opuestas** y se responden con estructuras distintas. Decir "la X" a las dos es indicador de que se está contestando sin pensar la pregunta. La respuesta buena a "¿cuál es mejor?" es **"depende del patrón"** (Sesión 27)
- [x] 🐛 **`int r; r = f();` NO es una referencia, aunque `f()` devuelva `int&`.** El tipo lo decide la DECLARACIÓN, no el origen del valor: la asignación **copia el contenido**. vs `int& r = f();` que sí es alias. Cometido por el tutor al armar la demo de la referencia colgante: el programa parecía tener un UAF, pero valgrind daba 0 errores porque en realidad no había ninguno. **Diagnosticarlo por el ensamblador** (`g++ -O0 -S`) fue lo que louruhó: `movl %eax, -36(%rbp)` es una copia, no un `mov` de puntero (Sesión 27)
- [x] 🐛 Capacidad de `std::vector`: libstdc++ duplica **1 → 2 → 4 → 8**, no de 3 en 3. Con 3 elementos la capacidad **ya es 4**, así que un cuarto `push` NO reubica y no hay UAF: la demo "parecía" correcta y no demostraba nada. Para forzar la reubicación hay que **llenar la capacidad y meter uno más** (Sesión 27, StackRef.cpp)
- [x] 🐛 Ignorar el `bool` de retorno de `meter`. Al vaciar solo 1 de 3 elementos, 2 de los 3 `meter` siguientes devolvieron `false` (pila llena) y **no se insertaron**; `datos[2]` nunca se sobreescribió y la demo mintió. La operación **te avisó** y no se escuchó — exactamente la lección de la Sesión 26: si algo puede fallar, tiene que avisar, y hay que escucharlo (Sesión 27, RefColgante.cpp)
- [x] 🐛 **Doble `delete`** al querer "limpiar" un `delete` ya hecho para callar a valgrind: 5 errores en vez de 1. Un solo `delete pp` ya libera el objeto **y** su bloque interno (el `~Pila` llama `delete[] datos`) (Sesión 27, RefColgante.cpp)
- [x] `T& t = p.cima();` (seguro, materializa una copia) vs `auto&& t = p.cima();` (alias puro, se cuelga): **una palabra de diferencia** entre "copia que vive hasta el final del bloque" y "referencia al interior del contenedor". Misma familia que la trampa de la Sesión 25 (deducción de `T`) (Sesión 27)
- [x] La diferencia real entre dos estructuras de datos rara vez es O(1) contra O(n): es **la misma complejidad con distinta constante**. Lo que decide la constante: el número de `new`, si los datos están **contiguos en memoria** (caché y *prefetch*) o dispersos (*cache miss* ~100 ns). Medido: encadenada vs abierta = 16x al insertar (menos `new`) y 2.65x al consultar (caché), siendo las dos O(1) (Sesión 27, HashCache.cpp)
- [x] 🐛 **Borrar en un BST: la recursión reasigna, o el padre queda apuntando a memoria liberada.** En `borrar(nodo, valor)` las ramas recursivas TIENEN que reasignar el hijo (`nodo->izq = borrar(nodo->izq, valor)`). Si se escribe `borrar(nodo->izq, valor);` a secas, el `delete` sí ocurre pero **el padre sigue apuntando al nodo liberado** → *Invalid read* al recorrer y **doble `delete`** al destruir (15 errores de valgrind, valores basura en pantalla, "cadáver con el mismo DNI"). Mismo patrón que el `= delete` de los apuntadores a member en la Sesión 22. El `insertar` de tu BST ya lo hacía bien; el `borrar` es donde se cuela (Sesión 28, ArbolBST.cpp)
- [x] 🐛 **El error espejo: el valor se asigna al lado equivocado.** `raiz->der = borrar(raiz->izq, valor)` — se **consulta** el hijo izquierdo pero se **escribe** en el derecho. No crashea: compila limpio, corre, y produce un árbol *plausible pero incorrecto* (y valgrind lo detecta como `Invalid read` después). Es la peor clase de bug: **ningún aviso**. La trampa del espejo aparece al escribir una versión y copiarla reflejada; el cerebro compara por forma, no por símbolo. **Antídoto:** leer la línea en voz alta como "tomo X, guardo en Y" y comprobar que X e Y coinciden. A Juan le pasó en `borrar` (Sesión 28) y antes en el `search` del BST de la Sesión 19
- [x] 🐛 **Una función recursiva que devuelve algo tiene que devolverlo en TODOS los caminos.** El patrón `if (condicion) { recursion(); }  ... return valorPorDefecto;` se cuela cuando se **olvida el `return` en una rama**: la rama ejecuta el efecto (los nodos sí se reconectan) pero **el resultado se pierde** y la función cae al `return` de relleno devolviendo el nodo viejo. **En `borrar`/`buscar`/`insertar` con rotaciones, el efecto y el valor son cosas distintas**: la rotación SÍ ocurre (reordena punteros) pero si no la retornás, el padre se queda con el puntero viejo. Síntoma: el árbol "pierde" nodos (viven en memoria pero nadie los apunta) y el inorden sale incompleto. Es la **4a vez en el día** que aparece (buscar → borrar → rotarIzquierda → insertar AVL) — a la 4a Juan ya la reconoció sin ayuda. **Corolario: si escribes una función recursiva y un `if` con `return`, TODOS los caminos deben tener `return`** (Sesión 28, ArbolBST.cpp y ArbolAVL.cpp)
- [x] 🐛 `nullptr->altura` compila pero revienta: acceder al campo de un puntero que puede ser nulo es un *Invalid read*, y el compilador **no avisa** (solo avisa del `nodo->izq` nulo, no del `->` sobre él). El patrón correcto: `mayor(altura(nodo->izq), altura(nodo->der))` — la función `altura` ya sabe qué hacer con el `nullptr` (devuelve 0). **Regla general: si algo puede ser nullptr, se accede por la función que lo maneja, NUNCA con `->campo` directo** (Sesión 28, ArbolAVL.cpp)
- [x] **Altura de un nodo = 1 + max(altura_izq, altura_der), NO la suma.** Sumar las dos alturas da un número que no corresponde a nada: mide "cuántos nodos hay colgados" en vez de "cuán profundo es el árbol". Consecuencia concreta: un nodo con FE real de -2 (claramente volcado) saldría con FE = 0 si se suman las alturas, y el AVL **no detectaría el desequilibrio** → se degrada a lista y todo el módulo se cae. Analogía útil: la altura de un edificio es el piso más alto que existe, no el total de pisos de todas las alas. La función `mayor(a,b)` existe justamente para no tener que escribir el `if` a mano (Sesión 28, ArbolAVL.cpp)
- [x] **Guardar la altura en cada nodo (AVL) vs. recalcularla (BST): es O(1) vs O(n) por inserción.** En el BST la altura se necesita UNA vez al final → recorrer el árbol no cuesta nada. En el AVL se necesita **después de cada inserción** (para preguntar "¿este nodo se volcó?"): si fueras a recalcularla recorriendo, insertar el n-ésimo dato costaría O(n) y con 1M de datos el árbol sería inútil. Guardándola en el nodo, es leer un campo. **La regla general: si un dato se necesita en cada operación, se cachea en el nodo; si se necesita una vez al final, se calcula cuando toca** (Sesión 28, ArbolAVL.cpp)
- [x] 🐛 **Rotación: el nieto se guarda aparte ANTES de reconectar, o se desconecta y se fuga.** En `rotarDerecha(nodo)`: se guarda `hijo = nodo->izq`, `nieto = hijo->der`, y LUEGO `nodo->izq = nieto`. Si se reescribe `nodo->izq` antes de guardar al nieto, el nieto se queda colgando de un puntero viejo y **se pierde para siempre** (el mismo drama del "se me olvidó reconectar" del borrado de lista y de la hash). El orden correcto es: **guardar → reconectar → actualizar alturas de abajo hacia arriba → return de la raíz nueva**. La rotación **no crea ni destruye nodos**: son 4 reasignaciones de puntero, ni un `new` ni un `delete`. Y la rotación **devuelve `Nodo*`, no `void`**: el padre y el hijo intercambian papeles, y el llamador necesita saber cuál es la nueva raíz del pedazo (Sesión 28, ArbolAVL.cpp)
- [x] **Un árbol en arreglo solo es posible si es COMPLETO.** La propiedad clave: nivel 0 tiene 1 nodo, nivel 1 tiene 2, nivel 2 tiene 4, etc., y el último nivel se llena **de izquierda a derecha** — sin huecos. Solo así la aritmética funciona: para el nodo en `i`, `izq = 2i+1`, `der = 2i+2`, `padre = (i-1)/2`. En un BST (que se desbalancea: un nodo con 1 hijo, otro con 3) **no se puede guardar en un arreglo** sin dejar huecos: la posición del hijo no es predecible por aritmética. Esa es la razón de que el heap viva en un `int heap[MAX]` (ningún `new`, ninguna fuga) mientras el BST y el AVL usan punteros (Sesión 28, ArbolHeap.cpp)
- [x] **Heap de máximos: el invariante es "cada padre es MAYOR que sus hijos", y por eso el máximo SIEMPRE está en `heap[0]`.** La prueba: el máximo de todo el árbol es el máximo de su raíz, que es el máximo de la raíz; y la raíz es el máximo de todo lo que cuelga de ella. "La raíz es el máximo" se demuestra por inducción sobre los niveles. Lo que **no** importa es cómo estén organizados los hermanos y los primos — solo importa padre > hijo. **Consecuencia:** insertar es "poner al final y subir", extraer es "sacar la raíz, bajar el último y reacomodar". El heapsort sale de sacar todos seguidos: sale ordenado de mayor a menor en O(n log n) sin comparar elementos que no sean padre e hijo (Sesión 28, ArbolHeap.cpp)
- [x] **Al extraer el máximo hay que guardar `maximo = heap[0]` ANTES de `heap[0] = heap[cantidad-1]`.** Es el mismo patrón que "guardar el sucesor antes de borrarlo" en el `borrar` del BST: **una variable local que sobrevive a la sobrescritura de su contexto**. Además, el paso "mover el último a la raíz" **no es opcional**: si se sacara la raíz sin llenar el hueco, el arreglo queda con un espacio vacío en el medio y la aritmética `2i+1, 2i+2` de los hijos **deja de tener sentido** para todos los índices mayores. Por eso la operación termina en O(log n) y no en O(1) (Sesión 28, ArbolHeap.cpp)
- [x] `while (i > 0)` en el "subir" del heap: si se olvida `i = padre;` después de intercambiar, el índice se queda quieto y el `if` es siempre verdadero → **bucle infinito** (timeout 124). El `i` del heap es una **posición**, no un nodo: actualizar el índice es "actualizar la referencia al nodo actual", el mismo criterio que "el caminante es una variable local, no la cabeza" de la Sesión 23 (Sesión 28, ArbolHeap.cpp)
- [x] `if (izq < cantidad && heap[izq] > heap[mayorPos])` — la **primera mitad del `&&` es una guarda de existencia**, no una condición del heap: si `cantidad = 4`, el índice 4 no existe y `heap[4]` es lectura fuera del arreglo. Es el mismo cortocircuito que en la lista (`actual != nullptr && actual->dato == valor`, Sesión 21): **el orden importa, primero lo que evita el acceso**. Y `mayorPos` empieza en `i` como el "mayor por defecto", así que si ningún hijo es mayor, `mayorPos == i` y el `break` corta (Sesión 28, ArbolHeap.cpp)

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
- [x] **Fase 7 (plantillas) adelantada a la Sesión 25**, just-in-time: al convertir `ListaCircular` y `ListaEnlazada` en `template <typename T>` (y al ver que una misma clase sirve para `int` y para `std::string`) hizo falta `template <typename T>`, deducción y clases plantilla antes de llegar a la Fase 7 formal. Se trabó la Fase 7 M1 completa (express) y quedó pendiente solo el M2 de variádicas (opcional, C++20, fuera del libro). No se perdió nada del orden.
- [x] **Referencias colgantes en `cima()` — RESUELTA en la Sesión 27** (pregunta abierta al cierre de la Sesión 26): `Pila<T>::cima()` devuelve `T&` al interior del array; si la pila se vacía o el elemento se recicla, esa referencia queda colgando. Resuelto: la referencia garantiza la DIRECCIÓN pero no la VIDA (tres estados, no dos); `std::stack` usa `deque` porque nunca reubica; regla de oro: una referencia es un **préstamo**, válida mientras el dueño viva y mientras nadie le cambie el significado. Ver la sección 🔑 de la Sesión 27. Importante para el resto del curso: es la misma clase de error que el *use-after-free* de la Sesión 20, y va a reaparecer en iteradores y en la cola circular.
- [x] **Tablas hash, árboles y grafos adelantados a la Sesión 27** (a pedido de Juan): se arrancó el bloque final de la Fase 9 (M4-M7) con M4 (hash). Justificación: son Caps. 14, 16, 17 y 18 del libro de Joyanes — el temario del profesor — y Juan los necesitaba ya. No se pierde nada del orden porque el orden *dentro* del bloque se respeta (hash → árboles → grafos). Lo que sí queda oficialmente **aplazado**: cola circular y `std::queue` de M2, y los montículos de M3 (que se harán just-in-time con `std::priority_queue` al llegar a Dijkstra/Kruskal/Prim).
- [x] **Montículos (heap) adelantados a la Sesión 28** — son M3 de la Fase 6, pero se hicieron aquí porque son un árbol (contenido de M5/M6) y porque **son el prerrequisito directo de Dijkstra y Kruskal** (M7), que llegan en la sesión siguiente. Con el heap understood, `std::priority_queue` deja de ser una caja negra. También se cubren con el heap los dos puntos que la ruta listaba en M5 (árbol binario completo) sin necesidad de un módulo aparte.
- [x] **Material del profesor en `Arboles y Grafos/`** — el profe dejó 9 archivos de árboles y 11 de grafos, todos con `main` y un `LEEME.md` con el orden sugerido. Se "/"ruta de estudio se ahora sigue el **LEEME del profe** cuando haymaterial equivalente, y los archivos de Juan van aparte para poder comparar. El nombre de los del profe lleva prefijo numérico (`01_`, `02_`, `02b_`, ...), lo que los hace auto-ordenables en el explorador de archivos.
