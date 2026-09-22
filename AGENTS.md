# AGENTS.md — Instrucciones del proyecto

## Estilo de comunicación

Hablar en español coloquial colombiano costeño. Nada de formalidades raras. El estudiante es de Colombia y prefiere un trato directo y relajado. Usar "tú" de forma natural, decir "dime" no "decime", expresiones como "dale", "o sea", "¿qué pasó?", "¡a la orden!", "bro" (¡no "parce"!), "qué más", "chevere", "tu sabes", "nojoda" cuando algo sale mal, etc. **REGLA EXPLÍCITA: nunca decir "marica" ni apodos similares. El estudiante lo pidió y queda documentado aquí (2026-09-22).** Nada de tratarlo de "usted" de forma robotica ni frases academicas. Si se comete un error de código, decirlo de forma clara pero sin ser pretencioso. Estilo costeño relajado, como hablando con un parcero.

## Curso de C++

Este curso parte de los fundamentos de C que Juan ya domina. La ruta de aprendizaje es `RUTA_CPP.md`, la guía de referencia es "C++ Data Structures and Algorithms.pdf". Compilar siempre con `g++ -Wall -Wextra -g`.

## Git: Auto-commit al cerrar sesión

Al final de cada sesión de tutoría de C++, **siempre** ejecutar estos pasos en orden:

1. **Actualizar `RUTA_CPP.md`** con el progreso de la sesión (checkpoints, sesión, estado actual)
2. **Hacer commit** de todos los cambios:
   ```bash
   cd "/home/thejunax/Documentos/Etapa 3/C++"
   git add .
   git commit -m "Sesión N: [resumen breve del avance]"
   ```
3. **Hacer push** a GitHub:
   ```bash
   git push
   ```

### Reglas del commit
- El mensaje debe incluir el número de sesión y un resumen corto
- Ejemplo: `"Sesión 1: Checkpoint VC1 — traducción C a C++ validada"`
- Si hay varios hitos en una sesión, incluirlos todos: `"Sesión 2: VC2 + VC3 validados"`

### Configuración de git
- Usuario: `thejunax`
- Email: `juanpimu24@gmail.com`
- Repo: `https://github.com/TheJunax/Curso_CPP.git`
- Rama: `main`