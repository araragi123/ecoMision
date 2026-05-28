# Documento de diseño — EcoMisión

Este documento muestra cómo evolucionó el diseño del sistema y explica las
decisiones más importantes. Incluye **tres versiones** del diagrama de clases:
inicial (antes de programar), ajustada (mientras programábamos) y final
(producto terminado).

---

## 1. Versión inicial (antes de programar)

Primera idea sobre el papel. Identificamos las clases principales y las
relaciones básicas, sin detallar todavía atributos ni métodos.

```mermaid
classDiagram
    class EcoMision
    class Reserva
    class Zona
    class Explorador
    class ElementoInteractivo

    EcoMision --> Reserva : usa
    EcoMision --> Explorador : usa
    Reserva --> Zona : contiene
    Zona --> ElementoInteractivo : contiene
    ElementoInteractivo <|-- AnimalHerido
    ElementoInteractivo <|-- EstacionEnergia
    ElementoInteractivo <|-- ResiduoContaminante
```

Dudas que teníamos en este punto:

- ¿Cómo guardar las zonas dentro de la Reserva? (¿lista, mapa?)
- ¿Cuántas clases hijas de `ElementoInteractivo` necesitamos? (mínimo 3)
- ¿Dónde poner la sobrecarga?

---

## 2. Versión ajustada (después de empezar a programar)

Al programar, decidimos:

- Usar `std::unordered_map<string, Zona*>` en la `Reserva`, porque buscamos
  zonas **por código**.
- Que `Zona` guarde los elementos como `vector<ElementoInteractivo*>` para
  poder usar **polimorfismo**.
- Poner la **sobrecarga** en `Zona::interactuarCon()` (por índice y por nombre).

```mermaid
classDiagram
    class EcoMision {
        -Reserva* reserva
        -Explorador* explorador
        +iniciar()
    }
    class Reserva {
        -unordered_map~string, Zona*~ zonas
        +agregarZona(codigo, zona)
        +buscarZona(codigo) Zona*
    }
    class Zona {
        -string nombre
        -vector~ElementoInteractivo*~ elementos
        +agregarElemento(e)
        +interactuarCon(indice, exp)
        +interactuarCon(nombre, exp)
    }
    class Explorador {
        -string nombre
        -int energia
        -int puntajeAmbiental
        +recuperarEnergia(n)
        +aumentarPuntaje(n)
    }
    class ElementoInteractivo {
        <<abstract>>
        #string nombre
        +interactuar(exp)* void
    }

    EcoMision --> Reserva
    EcoMision --> Explorador
    Reserva o-- Zona
    Zona o-- ElementoInteractivo
    ElementoInteractivo <|-- AnimalHerido
    ElementoInteractivo <|-- EstacionEnergia
    ElementoInteractivo <|-- ResiduoContaminante
```

---

## 3. Versión final (después de terminar)

Diagrama completo del código entregado. Agregamos dos clases hijas más
(`PortalDeRuta` y `PlantaMedicinal`) para enriquecer la demostración, y
detallamos los métodos clave.

```mermaid
classDiagram
    class EcoMision {
        -reserva: Reserva*
        -explorador: Explorador*
        -prepararReserva() void
        -crearExplorador() void
        -ejecutarDemostracion() void
        +EcoMision()
        +~EcoMision()
        +iniciar() void
    }

    class Reserva {
        -zonas: std::unordered_map~std::string, Zona*~
        +Reserva()
        +~Reserva()
        +agregarZona(codigo: std::string, zona: Zona*) void
        +buscarZona(codigo: std::string) Zona*
        +mostrarZonas() void
    }

    class Zona {
        -nombre: std::string
        -elementos: std::vector~ElementoInteractivo*~
        +Zona(nombre: std::string)
        +~Zona()
        +getNombre() std::string
        +agregarElemento(elemento: ElementoInteractivo*) void
        +mostrarElementos() void
        +interactuarCon(indice: int, explorador: Explorador*) void
        +interactuarCon(nombreElemento: std::string, explorador: Explorador*) void
    }

    class Explorador {
        -nombre: std::string
        -energia: int
        -puntajeAmbiental: int
        -zonaActual: std::string
        +Explorador(nombre: std::string, energiaInicial: int)
        +getNombre() std::string
        +getEnergia() int
        +getPuntajeAmbiental() int
        +getZonaActual() std::string
        +perderEnergia(cantidad: int) void
        +recuperarEnergia(cantidad: int) void
        +aumentarPuntaje(cantidad: int) void
        +cambiarZona(codigoZona: std::string) void
        +mostrarEstado() void
    }

    class ElementoInteractivo {
        <<abstract>>
        #nombre: std::string
        +ElementoInteractivo(nombre: std::string)
        +~ElementoInteractivo()
        +interactuar(explorador: Explorador*)* void
        +getNombre() std::string
    }

    class AnimalHerido {
        -puntosPorAyudar: int
        +AnimalHerido(nombre: std::string, puntosPorAyudar: int)
        +interactuar(explorador: Explorador*) void
    }

    class EstacionEnergia {
        -energiaQueDa: int
        +EstacionEnergia(nombre: std::string, energiaQueDa: int)
        +interactuar(explorador: Explorador*) void
    }

    class PlantaMedicinal {
        -energiaQueDa: int
        -puntosQueDa: int
        +PlantaMedicinal(nombre: std::string, energiaQueDa: int, puntosQueDa: int)
        +interactuar(explorador: Explorador*) void
    }

    class PortalDeRuta {
        -zonaDestino: std::string
        +PortalDeRuta(nombre: std::string, zonaDestino: std::string)
        +interactuar(explorador: Explorador*) void
    }

    class ResiduoContaminante {
        -energiaQueCuesta: int
        -puntosPorLimpiar: int
        +ResiduoContaminante(nombre: std::string, energiaQueCuesta: int, puntosPorLimpiar: int)
        +interactuar(explorador: Explorador*) void
    }

    EcoMision --> Reserva : asociación
    EcoMision --> Explorador : asociación
    Reserva o-- Zona : agregación
    Zona o-- ElementoInteractivo : agregación
    ElementoInteractivo <|-- AnimalHerido : herencia
    ElementoInteractivo <|-- EstacionEnergia : herencia
    ElementoInteractivo <|-- PlantaMedicinal : herencia
    ElementoInteractivo <|-- PortalDeRuta : herencia
    ElementoInteractivo <|-- ResiduoContaminante : herencia
    ElementoInteractivo ..> Explorador : usa en interactuar()
```

## 4. Matriz de decisiones de diseño

| Decisión | Alternativas consideradas | Decisión final | Justificación | Riesgo si se modela mal |
|---|---|---|---|---|
| Cómo representar las zonas | vector, matriz, `unordered_map` | `unordered_map` | La reserva busca zonas **por código**; el mapa hace esa búsqueda directa y rápida. | Se complica la búsqueda o se mezcla con lógica de tablero. |
| Relación Reserva–Zona | Composición vs agregación | Agregación (`Zona*`) | La reserva agrupa zonas y las administra; guardar punteros permite polimorfismo y flexibilidad. | Memoria mal liberada o acoplamiento excesivo. |
| Relación Zona–Elemento | Guardar objetos vs guardar punteros | Punteros `ElementoInteractivo*` | Sin punteros NO hay polimorfismo (perderíamos el tipo real del objeto). | Se pierde el polimorfismo (problema de "object slicing"). |
| Jerarquía de elementos | Una sola clase con un "tipo" (int/enum) | Clase abstracta + herencia | Cada elemento cambia por **comportamiento**, no solo por datos; la herencia lo expresa mejor. | Código lleno de `if/switch` difícil de mantener y extender. |
| Dónde poner la sobrecarga | En Zona vs en Explorador | En `Zona::interactuarCon()` | Es natural interactuar con un elemento por índice o por nombre desde la zona. | Sobrecarga forzada o poco útil. |
| Cómo coordinar todo | Lógica en `main` vs clase central | Clase `EcoMision` | El `main` queda pequeño y la responsabilidad de coordinar está en un solo lugar. | `main` gigante, difícil de leer y probar. |

---

