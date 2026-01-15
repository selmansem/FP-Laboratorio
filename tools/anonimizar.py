#!/usr/bin/env python3
"""
Script para anonimizar PDFs de prácticas.
Redacta (tacha con negro) los nombres de alumnos que aparecen después de "Alumno/a:"

Uso:
    python anonimizar_pdf.py documento.pdf
    python anonimizar_pdf.py documento.pdf -o salida.pdf
    python anonimizar_pdf.py documento.pdf --desde-pagina 3

Requisitos:
    pip install -r requirements.txt
"""

import pymupdf as fitz  # PyMuPDF
import argparse
import sys
from pathlib import Path


def anonimizar_pdf(input_path: str, output_path: str = None, desde_pagina: int = 1):
    """
    Anonimiza un PDF redactando los nombres después de 'Alumno/a:'

    Args:
        input_path: Ruta al PDF original
        output_path: Ruta para guardar el PDF anonimizado (opcional)
        desde_pagina: Página desde la que empezar a buscar (1-indexed)
    """

    # Generar nombre de salida si no se especifica
    if output_path is None:
        p = Path(input_path)
        output_path = str(p.parent / f"{p.stem}_anonimizado{p.suffix}")

    # Abrir el documento
    try:
        doc = fitz.open(input_path)
    except Exception as e:
        print(f"❌ Error al abrir el PDF: {e}")
        sys.exit(1)

    print(f"📄 Procesando: {input_path}")
    print(f"   Total de páginas: {len(doc)}")
    print(f"   Buscando desde página: {desde_pagina}")
    print()

    nombres_redactados = 0

    # Procesar cada página (desde_pagina usa índice 1, fitz usa índice 0)
    for page_num in range(desde_pagina - 1, len(doc)):
        page = doc[page_num]

        # Buscar todas las instancias de "Alumno/a:"
        text_instances = page.search_for("Alumno/a:")

        for inst in text_instances:
            # inst es un Rect con la posición de "Alumno/a:"
            # Necesitamos encontrar el nombre que está a la derecha

            # Obtener el texto de esa línea expandiendo el área de búsqueda
            # Expandimos horizontalmente para capturar todo el nombre
            line_rect = fitz.Rect(
                inst.x1,  # Empieza donde termina "Alumno/a:"
                inst.y0 - 2,  # Un poco arriba
                page.rect.width - 50,  # Hasta casi el final de la página
                inst.y1 + 2,  # Un poco abajo
            )

            # Extraer el texto en esa área (el nombre)
            nombre = page.get_text("text", clip=line_rect).strip()

            if nombre:
                # Aplicar redacción (rectángulo negro sobre el nombre)
                page.add_redact_annot(line_rect, fill=(0, 0, 0))  # Negro
                nombres_redactados += 1
                print(f"   Página {page_num + 1}: Redactando nombre...")

    # Aplicar todas las redacciones
    for page_num in range(len(doc)):
        doc[page_num].apply_redactions()

    # Guardar el documento
    try:
        doc.save(output_path)
        doc.close()
    except Exception as e:
        print(f"❌ Error al guardar: {e}")
        sys.exit(1)

    print()
    print(f"✅ Completado!")
    print(f"   Nombres redactados: {nombres_redactados}")
    print(f"   Guardado en: {output_path}")


def main():
    parser = argparse.ArgumentParser(
        description="Anonimiza PDFs redactando nombres de alumnos",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Ejemplos:
  python anonimizar_pdf.py practica.pdf
  python anonimizar_pdf.py practica.pdf -o practica_sin_nombres.pdf
  python anonimizar_pdf.py practica.pdf --desde-pagina 3
        """,
    )

    parser.add_argument("pdf", help="Ruta al archivo PDF a procesar")
    parser.add_argument("-o", "--output", help="Ruta del archivo de salida (opcional)")
    parser.add_argument(
        "--desde-pagina",
        type=int,
        default=1,
        help="Página desde la que empezar a buscar (default: 1)",
    )

    args = parser.parse_args()

    # Verificar que el archivo existe
    if not Path(args.pdf).exists():
        print(f"❌ No se encuentra el archivo: {args.pdf}")
        sys.exit(1)

    anonimizar_pdf(args.pdf, args.output, args.desde_pagina)


if __name__ == "__main__":
    main()
