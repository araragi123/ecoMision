# Bitácora de uso de IA generativa — EcoMisión
## 1. ¿Para qué usamos IA generativa?
Usamos IA generativa principalmente como una **herramienta de apoyo para
aprender** y para revisar ideas de diseño. 

La IA nos ayudo mas que todo a aprender mejor algunos temas que no nos habia quedado muy claro como por ejemplo los siguiente:
 
- "¿Qué es una clase abstracta y para qué sirve?"
- "¿Cuál es la diferencia entre sobrecarga y sobreescritura?"
- "¿Qué es el polimorfismo en POO?"
- "¿Para qué sirve `std::unordered_map` y cuándo conviene usarlo?"

Después de leer la explicación, la discutíamos en equipo con nuestras propias
palabras para asegurarnos de que la habíamos entendido.Por que podiamos haberle preguntado a la IA osbre esos temas pero si no los entendiamos no haciamos nada.

## 2. ¿Qué decisión de diseño revisamos con IA?

En la parte del diseño no sabíamos si era mejor usar `vector<Zona*>`, una matriz o `unordered_map` para guardar las zonas de la reserva.

Asi que le preguntamos a la IA cuál opción era más conveniente teniendo en cuenta que necesitamos buscar zonas por su código, por ejemplo `"bosque"` o `"rio"`.

Lo que nos dijo que con un `vector` es necesario recorrer todos los elementos hasta encontrar la zona buscada, mientras que `unordered_map` permite encontrarla directamente usando la clave, haciendo la búsqueda más rápida y eficiente.

Asi que decidimos usar `unordered_map<string, Zona*>` en la clase `Reserva`, porque facilita buscar zonas de manera más rápida. Esta decisión también quedó registrada en `diseno.md`.

## 3. ¿Qué sugerencia de IA aceptamos y por qué?
Aceptamos usar una clase abstracta `ElementoInteractivo` con un método virtual puro y clases hijas que lo sobreescriben. La aceptamos porque resuelve el problema de tener un `if/switch` enorme por cada tipo de elemento, y porque coincide con lo que pide el enunciado.
## 4. ¿Qué sugerencia de IA corregimos o rechazamos y por qué?
Rechazamos usar smart pointers (`unique_ptr`, `shared_ptr`). Aunque son más modernos, no los hemos visto en clase y no podríamos defenderlos en la sustentación. Preferimos `new`/`delete` manual porque muestra de forma explícita la creación y destrucción de objetos, que es algo que el enunciado pide demostrar.
 ## 5. ¿Qué parte del proyecto debe poder defender cada integrante?
 | Integrante | Parte que defiende | Conceptos clave |
 | Maria Camila Giraldo | `ElementoInteractivo`, las clases hijas (`ElementosInteractivos/`) y `Explorador` | Abstracción, herencia, clase abstracta, sobreescritura, polimorfismo, encapsulamiento |
 |Santiago Garcia| `Reserva`, `Zona`, `EcoMision` y `main` | `unordered_map`, agregación, asociación, sobrecarga, flujo del programa |

