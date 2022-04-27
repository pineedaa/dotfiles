# Carlos Pineda

from libqtile.config import Key
from libqtile.command import lazy
from libqtile.utils import guess_terminal
from .widgets import openMenu

mod = 'mod4'
terminal = guess_terminal()

keys = [
    # Cambiar entre ventanas
    Key([mod], 'h', lazy.layout.left(),
        desc='Cambiar foco a la izquierda'),
    Key([mod], 'l', lazy.layout.right(),
        desc='Cambiar foco a la derecha'),
    Key([mod], 'j', lazy.layout.down(),
        desc='Cambiar foco abajo'),
    Key([mod], 'k', lazy.layout.up(),
        desc='Cambiar foco arriba'),
    Key([mod], 'space', lazy.layout.next(),
        desc='Cambiar foco a otra ventana'),

    # Cambiar posición de las ventanas en 'bsp'
    Key([mod, 'shift'], 'h', lazy.layout.shuffle_left(),
        desc='Mover la ventana a la izquierda'),
    Key([mod, 'shift'], 'l', lazy.layout.shuffle_right(),
        desc='Mover la ventana a la derecha'),
    Key([mod, 'shift'], 'j', lazy.layout.shuffle_down(),
        desc='Mover la ventana abajo'),
    Key([mod, 'shift'], 'k', lazy.layout.shuffle_up(),
        desc='Mover la ventana arriba'),
    
    # Cambiar tamaño de las ventanas en 'bsp'
    Key([mod, 'control'], 'h', lazy.layout.grow_left(),
        desc='Aumentar tamaño a la izquierda'),
    Key([mod, 'control'], 'l', lazy.layout.grow_right(), 
        desc='Aumentar tamaño a la derecha'),
    Key([mod, 'control'], 'j', lazy.layout.grow_down(),
        desc='Aumentar tamaño a arriba'),
    Key([mod, 'control'], 'k', lazy.layout.grow_up(),
        desc='Aumentar tamaño a abajo'),
    Key([mod], 'n', lazy.layout.normalize(),
        desc='Resetear los tamaños'),

    Key([mod], 'Tab', lazy.next_layout(),
        desc='Cambiar entre layouts'),
 
    Key([mod], 'w', lazy.window.kill(),
        desc='Cerrar la ventana seleccionada'),

    Key([mod, 'control'], 'r', lazy.restart(),
        desc='Reiniciar Qtile'),
    Key([mod, 'control'], 'q', lazy.spawn('/sbin/shutdown now'),
        desc='Apagar'),

    # Mis atajos de teclado
    Key([mod], 's', lazy.spawn('scrot'), 
        desc='Hacer captura de pantalla'),
    Key([mod], 'Return', lazy.spawn(terminal),
        desc='Lanzar terminal'),
    Key([mod], 'b', lazy.spawn('firefox'),
        desc='Abrir firefox'),
    Key([mod], 'm', lazy.spawn('rofi -show run'),
        desc='Abrir menú'),
    Key([mod], 'e', lazy.spawn('alacritty -e ranger'),
        desc='Abrir gestor de archivos en cli'),
    Key([mod, 'shift'], 'e', lazy.spawn('thunar'),
        desc='Abrir gestor de archivos'),
    Key([mod, 'shift'], 'm', lazy.spawn('rofi -show'),
        desc='Abrir menú para ventanas abiertas'),
    Key([mod, 'shift'], 'b', lazy.hide_show_bar(),
        desc='Oculta la barra'),
    Key([mod], 'f', lazy.window.toggle_floating(),
        desc='Toogle para hacer flotar ventanas'),

    # Botones de sonido
    Key([], 'XF86AudioLowerVolume', lazy.spawn('pactl set-sink-volume @DEFAULT_SINK@ -5%')),
    Key([], 'XF86AudioRaiseVolume', lazy.spawn('pactl set-sink-volume @DEFAULT_SINK@ +5%')),
    Key([], 'XF86AudioMute', lazy.spawn('pactl set-sink-mute @DEFAULT_SINK@ toggle')),

    # Botones de brillo
    Key([], 'XF86MonBrightnessUp', lazy.spawn('brightnessctl set +10%')),
    Key([], 'XF86MonBrightnessDown', lazy.spawn('brightnessctl set 10%-')),
]