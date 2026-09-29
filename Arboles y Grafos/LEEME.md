# Estructuras de datos en C++: Arboles y Grafos

Cada archivo es un programa **completo e independiente**: se compila solo y trae un `main` con un ejemplo que muestra el resultado en pantalla.

Todo esta en espanol y **sin tildes ni enies** (para que no salgan simbolos raros en la consola de Windows).

## Como compilar

```
g++ nombre_del_archivo.cpp -o programa
./programa          (en Windows: programa.exe)
```

## Arboles (`arboles/`)

| Archivo | Que tiene |
|---|---|
| `01_arbol_binario.cpp` | Nodo, armar el arbol a mano, recorridos (pre, in, post, por niveles), altura, nodos y hojas. Usa el arbol del ejercicio 16.2 |
| `02_arbol_busqueda.cpp` | BST con funciones: insertar y buscar (**recursivo e iterativo**), minimo, maximo, borrar (3 casos), mostrar |
| `02b_arbol_busqueda_clase.cpp` | El mismo BST pero dentro de una **clase** con destructor |
| `03_arbol_avl.cpp` | AVL: factor de equilibrio, las 4 rotaciones, insertar |
| `04_arbol_en_arreglo_y_heap.cpp` | Arbol guardado en arreglo (`2i+1`, `2i+2`, `(i-1)/2`) y heap de maximos |
| `05_arbol_b.cpp` | Arbol B: buscar, insertar con division de nodos, mostrar por niveles |
| `06_arbol_general.cpp` | Arbol con muchos hijos usando `vector` (ejemplo de carpetas) |
| `06b_arbol_general_hijo_hermano.cpp` | Arbol general con **primer hijo / siguiente hermano** (sin vector) |
| `07_arbol_expresion.cpp` | Arbol de expresion: evaluar, infija/prefija/postfija, construirlo **a mano y desde postfija** |

## Grafos (`grafos/`)

| Archivo | Que tiene |
|---|---|
| `01_grafo_matriz_adyacencia.cpp` | Grafo con matriz: agregar/eliminar arista, vecinos, grado |
| `02_grafo_lista_adyacencia.cpp` | Grafo con lista: **sin pesos y con pesos** |
| `03_recorridos_bfs_dfs.cpp` | BFS (con distancias y camino mas corto), DFS **recursivo y con pila**, componentes conexos |
| `04_dijkstra.cpp` | Camino mas corto con pesos, version simple con matriz |
| `04b_dijkstra_cola_prioridad.cpp` | Dijkstra rapido con `priority_queue` |
| `05_prim.cpp` | Arbol de expansion minima (Prim) |
| `06_kruskal.cpp` | Arbol de expansion minima (Kruskal + union-find) |
| `07_floyd_warshall.cpp` | Distancias minimas entre todos los pares |
| `08_orden_topologico.cpp` | Orden topologico y deteccion de ciclos (ejemplo de materias con prerrequisitos) |

Los archivos 04 a 07 de grafos usan **el mismo grafo con pesos**, asi se pueden comparar los resultados.

## Orden sugerido para estudiar

1. `arboles/01` -> `02` -> `02b` (lo basico)
2. `arboles/03` (AVL) y `04` (heap)
3. `grafos/01` -> `02` -> `03`
4. `grafos/04` -> `05` -> `06`
5. Lo demas segun lo que pidan en clase

## Recordatorios importantes

- Siempre reasignar la raiz: `raiz = insertar(raiz, x);` y `raiz = borrar(raiz, x);`
- Todo lo que se crea con `new` hay que liberarlo con `delete` (funcion `destruir`).
- En grafos siempre se usa un arreglo `visitado`, porque puede haber ciclos.
- Dijkstra **no** funciona con pesos negativos; Floyd si (mientras no haya ciclos negativos).
