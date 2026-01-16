import os
import sys
from pathlib import Path

try:
    import pikepdf

    MOTOR = "pikepdf"
except ImportError:
    try:
        from pypdf import PdfReader, PdfWriter

        MOTOR = "pypdf"
    except ImportError:
        print("Instala una de estas bibliotecas:")
        print("  pip install pikepdf")
        print("  pip install pypdf")
        sys.exit(1)


def comprimir_con_pikepdf(entrada: Path, salida: Path) -> None:
    with pikepdf.open(entrada) as pdf:
        pdf.save(
            salida,
            recompress_flate=True,
            compress_streams=True,
            object_stream_mode=pikepdf.ObjectStreamMode.generate,
            preserve_pdfa=False,
        )


def comprimir_con_pypdf(entrada: Path, salida: Path) -> None:
    reader = PdfReader(entrada)
    writer = PdfWriter()

    for page in reader.pages:
        page.compress_content_streams()
        writer.add_page(page)

    if reader.metadata:
        writer.add_metadata(reader.metadata)

    with open(salida, "wb") as f:
        writer.write(f)


def comprimir_pdf(entrada: str, salida: str = None) -> dict:
    entrada = Path(entrada)

    if not entrada.exists():
        raise FileNotFoundError(f"No se encontró: {entrada}")

    if salida is None:
        salida = entrada.with_stem(f"{entrada.stem}_comprimido")
    else:
        salida = Path(salida)

    tamaño_original = entrada.stat().st_size

    if MOTOR == "pikepdf":
        comprimir_con_pikepdf(entrada, salida)
    else:
        comprimir_con_pypdf(entrada, salida)

    tamaño_final = salida.stat().st_size
    reduccion = (1 - tamaño_final / tamaño_original) * 100

    return {
        "archivo_original": str(entrada),
        "archivo_comprimido": str(salida),
        "tamaño_original": tamaño_original,
        "tamaño_final": tamaño_final,
        "reduccion_porcentaje": round(reduccion, 2),
        "motor": MOTOR,
    }


def formato_tamaño(bytes: int) -> str:
    for unidad in ["B", "KB", "MB", "GB"]:
        if bytes < 1024:
            return f"{bytes:.2f} {unidad}"
        bytes /= 1024
    return f"{bytes:.2f} TB"


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Uso: python3 comprimir_pdf.py archivo.pdf [salida.pdf]")
        sys.exit(1)

    entrada = sys.argv[1]
    salida = sys.argv[2] if len(sys.argv) > 2 else None

    try:
        resultado = comprimir_pdf(entrada, salida)
        print(f"Motor usado: {resultado['motor']}")
        print(f"Original:    {formato_tamaño(resultado['tamaño_original'])}")
        print(f"Comprimido:  {formato_tamaño(resultado['tamaño_final'])}")
        print(f"Reducción:   {resultado['reduccion_porcentaje']}%")
        print(f"Guardado en: {resultado['archivo_comprimido']}")
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)
