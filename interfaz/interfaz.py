import tkinter as tk
from tkinter import ttk, messagebox

# Paleta de colores
COLOR_FONDO = "#E0F7FA"  # Celeste claro
COLOR_BOTONES = "#80DEEA"  # Celeste medio
COLOR_TEXTO = "#00796B"  # Verde oscuro (para contraste)
COLOR_VERDE_CLARO = "#C8E6C9"  # Verde claro para secciones

def mostrar_mensaje_bienvenida():
    messagebox.showinfo("Bienvenido", "¡Bienvenido a la Clínica Dental Ratoncito Pérez!")

def abrir_registro_pacientes():
    ventana_registro = tk.Toplevel()
    ventana_registro.title("Registro de Pacientes")
    ventana_registro.geometry("400x300")  # Ancho x Alto (en píxeles)
    ventana_registro.config(bg=COLOR_FONDO)
    
    tk.Label(ventana_registro, text="Nombre del Paciente:", bg=COLOR_FONDO, fg=COLOR_TEXTO).pack(pady=5)
    tk.Entry(ventana_registro).pack(pady=5)
    
    tk.Label(ventana_registro, text="Edad:", bg=COLOR_FONDO, fg=COLOR_TEXTO).pack(pady=5)
    tk.Entry(ventana_registro).pack(pady=5)
    
    tk.Button(ventana_registro, text="Guardar", bg=COLOR_BOTONES, fg="white").pack(pady=10)

# Crear ventana principal
root = tk.Tk()
root.title("Clínica Dental Ratoncito Pérez")
root.geometry("600x400")
root.config(bg=COLOR_FONDO)

# Encabezado
tk.Label(
    root, 
    text="🐭 Clínica Dental Ratoncito Pérez 🦷", 
    font=("Helvetica", 16, "bold"), 
    bg=COLOR_VERDE_CLARO, 
    fg=COLOR_TEXTO,
    pady=10
).pack(fill="x")

# Botones principales
frame_botones = tk.Frame(root, bg=COLOR_FONDO)
frame_botones.pack(pady=20)

botones = [
    ("Registrar Paciente", abrir_registro_pacientes),
    ("Agendar Cita", lambda: messagebox.showinfo("En desarrollo", "Próximamente...")),
    ("Historial Médico", lambda: messagebox.showinfo("En desarrollo", "Próximamente...")),
    ("Salir", root.quit)
]

for texto, comando in botones:
    tk.Button(
        frame_botones, 
        text=texto, 
        bg=COLOR_BOTONES, 
        fg="white", 
        padx=10, 
        pady=5, 
        command=comando
    ).pack(side="left", padx=10, pady=5)

# Pie de página
tk.Label(
    root, 
    text="© 2023 Clínica Dental Ratoncito Pérez - ¡Sonrisas saludables!", 
    font=("Helvetica", 8), 
    bg=COLOR_VERDE_CLARO, 
    fg=COLOR_TEXTO,
    pady=5
).pack(side="bottom", fill="x")

# Mostrar mensaje de bienvenida al iniciar
root.after(500, mostrar_mensaje_bienvenida)

root.mainloop()