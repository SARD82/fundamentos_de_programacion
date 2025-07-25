# Procesamiento de Imágenes en C (Proyecto Académico)

Este proyecto fue desarrollado como parte de mi formación en programación estructurada y manejo de memoria en lenguaje C. El sistema permite manipular imágenes BMP y PNM desde consola mediante argumentos de línea de comandos, simulando una herramienta de tipo CLI.

## 📌 Funcionalidades principales

- Separación de canales RGB (rojo, verde, azul)
- Conversión de imágenes a escala de grises
- Conversión a blanco y negro con umbral configurable
- Generación de histogramas por canal
- Mezcla de dos imágenes con factor alpha

## 🛠️ Tecnologías y conceptos aplicados

- Lenguaje C
- Manejo de archivos binarios (lectura y escritura de BMP y PNM)
- Manipulación de matrices tridimensionales
- Argumentos desde línea de comandos (`argc` y `argv`)
- Programación modular
- Validación de errores y entradas

## 📁 Estructura del repositorio

```
├── FINAL_p.c               # Código fuente completo
├── Pseudocodigo.txt        # Representación en pseudocódigo estructurado
└── imágenes generadas      # Archivos BMP de salida (rojo, verde, gris, etc.)
```

## ▶️ Cómo compilar y ejecutar

1. Compila el programa:
   ```bash
   gcc FINAL_p.c -o imagenes
   ```

2. Ejecuta una funcionalidad (por ejemplo, separación de canales):
   ```bash
   ./imagenes 1b entrada.bmp
   ```

3. Para ayuda completa sobre los comandos disponibles:
   ```bash
   ./imagenes -help
   ```

## 🧠 Aprendizajes clave

- Diseño de sistemas en C con entrada dinámica desde terminal
- Manipulación eficiente de imágenes mediante operaciones por píxel
- Control de flujo robusto con estructuras condicionales
- Generación de salidas visuales y textuales automatizadas

## 📄 Licencia

Este proyecto fue realizado con fines educativos. Puedes reutilizar el código siempre y cuando cites la fuente y no uses con fines comerciales sin permiso.

---

Desarrollado por **Santiago Durán Rendón**
