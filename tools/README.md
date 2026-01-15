# Tools

Esta carpeta contiene herramientas útiles desarrolladas para poder gestionar o manipular de forma eficiente cualquier elemento del repositorio.

## Listado de herramientas

-   `anonimizar.py`: Herramienta para anonimizar documentos PDF eliminando información personal como nombres, fechas o identificadores únicos.
    -   Uso:
        ```bash
        python3 anonimizar.py ruta/al/documento.pdf -o salida.pdf --desde-pagina N
        ```
    -   Parámetros:
        -   `ruta/al/documento.pdf`: Ruta al archivo PDF que se desea anonimizar.
        -   `-o salida.pdf`: (Opcional) Ruta al archivo PDF de salida anonimizado (por defecto es `anonimizado.pdf`).
        -   `--desde-pagina N`: (Opcional) Página desde la cual comenzar a anonimizar (por defecto es 1).
    -   Requisitos:
        ```bash
        pip install -r requirements.txt
        ```
    -   Nota: Usar un entorno virtual es recomendable para evitar conflictos con otras librerías instaladas globalmente.
        ```bash
        python3 -m venv venv
        source venv/bin/activate  # En Linux/Mac
        venv\Scripts\activate     # En Windows
        ```
